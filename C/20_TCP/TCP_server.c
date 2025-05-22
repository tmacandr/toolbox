/*****************************************************************************
* FILE: TCP_server.c
*
* DESCRIPTION:
*    Implements a bare-bones network server.  Opens a listening socket and
*    waits for connections.  Sockets are implemented using TCP.
*
*    Receives messages of ASCII text and replies with a simple ack.  Accepts
*    one or more clients simultaneously.  Will close peer-to-peer socket when
*    initiated by the client and will accept new connections form the same or
*    different clients.
*
* COPYRIGHT:
*    Copyright (c) 2004, Sally Recuas (SallyRecuas@gmail.com)
*
*    Permission to use, copy, modify, and/or distribute this software for any
*    purpose with or without fee is hereby granted, provided that the above
*    copyright notice and this permission notice appear in all copies.
*
*    THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
*    WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
*    MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
*    ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
*    WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
*    ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
*    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifdef WIN32

   #include <Winsock2.h>

#else

   /*
    * Assume UNIX
    */
   #include <unistd.h>
   #include <sys/types.h>
   #include <sys/socket.h>
   #include <netinet/in.h>
   #include <arpa/inet.h>
   #include <errno.h>
   #include <asm-generic/errno.h>

   #define SOCKET int

   #define SOCKET_ERROR   (-1)
   #define INVALID_SOCKET (-1)

   #define WSAEWOULDBLOCK     EWOULDBLOCK
   #define WSAECONNABORTED    ECONNABORTED
   #define WSAECONNRESET      ECONNRESET
   #define WSAENOTCONN        ENOTCONN
   #define WSAESHUTDOWN       ESHUTDOWN

   #define min(a,b) ( ( (a) < (b) ) ? (a) : (b) )

#endif

static void Initialize (void);
static void Open_Listen_Socket (const unsigned short port_num);
static void Service (void);
static void Receive_Message (const unsigned int index);
static void Accept_New_Client(void);
static void Shutdown (SOCKET which_socket);
static void Show_Error (const char *msg);
static void Show_Usage_And_Exit (void);
static int  Get_Last_Error (void);

static SOCKET listen_socket = 0;

#define MAX_NUM_CLIENTs   16

static SOCKET client_sockets[MAX_NUM_CLIENTs];


/***********************************************
* FUNCTION: main
*
* DESCRIPTION:
*    Main entry point of program.
************************************************/
int main (int argc, char **argv)

{
         unsigned short port_num;

   printf("_____________TCP Server________________________\n");

   if (argc != 2)
   {
       Show_Usage_And_Exit();
   }

   sscanf(argv[1], "%hu", &port_num);

   Initialize ();

   Open_Listen_Socket (port_num);

   Service ();

   Shutdown (listen_socket);

   printf("_______________________________________________\n");

   return 0;
}


/***********************************************
* FUNCTION: Initialize
*
* DESCRIPTION:
*    Initializes internal state.  For Win32,
*    invokes the startup mechanics.
************************************************/
static void Initialize (void)

{
   #ifdef WIN32

            WSADATA wsaData;
            int     result;

      result = WSAStartup(MAKEWORD(2,2), &wsaData);

      if (result != NO_ERROR)
      {
          Show_Error ("WSAStartup failed");

          exit (EXIT_FAILURE);
      }

   #endif

   memset (client_sockets, 0, sizeof(client_sockets));
}


/***********************************************
* FUNCTION: Open_Listen_Socket
*
* DESCRIPTION:
*    Creates a socket, binds it, and then sets
*    it to the listening state.
*
*    Binding means setting the socket to use
*    the IP address of the ethernet card of
*    this box.
*
*    Listening means it's available (i.e.
*    "listening") to accept connection requests
*    from clients.
************************************************/
static void Open_Listen_Socket (const unsigned short port_num)

{
   int                status;

   /* don't expect too many clients at once */
   int                backlog = 1;
   struct sockaddr_in my_IP_address_info;
   char               host_name[256];

   struct sockaddr_in *sai = (struct sockaddr_in *) &my_IP_address_info;
   char               *addr_string;

   listen_socket = socket
                     (AF_INET,      /* domain   */
                      SOCK_STREAM,  /* type     */
                      IPPROTO_TCP); /* protocol */

   if (listen_socket == SOCKET_ERROR)
   {
       Show_Error ("Create of listen socket failed");

       exit (EXIT_FAILURE);
   }

   /*
    * Bind the socket to this ethernet card (or
    * whichever device has the IP address).
    */
   my_IP_address_info.sin_family      = AF_INET;
   my_IP_address_info.sin_addr.s_addr = INADDR_ANY;
   my_IP_address_info.sin_port        = htons(port_num);

   status = bind
              (listen_socket, 
               (const struct sockaddr *) &my_IP_address_info, 
               sizeof(my_IP_address_info));

   if (status == SOCKET_ERROR)
   {
       Show_Error ("bind() failed");

       Shutdown (listen_socket);

       exit (EXIT_FAILURE);
   }

   memset (host_name, 0, sizeof(host_name));

   status = gethostname(host_name, sizeof(host_name));

   if (status == SOCKET_ERROR)
   {
       Show_Error("Call to 'gethostname' failed");

       Shutdown (listen_socket);

       exit (EXIT_FAILURE);
   }

   addr_string = inet_ntoa(sai->sin_addr);

   printf("---> Host name....: %s\n"
          "---> Address......: %s\n",
          host_name,
          addr_string);

   /*
    * Set it to the listening state.
    */
   status = listen
              (listen_socket,
               backlog);

   if (status == SOCKET_ERROR)
   {
       Show_Error ("Set socket to 'listen' state failed");

       Shutdown (listen_socket);

       exit (EXIT_FAILURE);
   }
}


/***********************************************
* FUNCTION: Service
*
* DESCRIPTION:
*    Loop that monitors all sockets.  New
*    connections are established and existing
*    connections are serviced.
************************************************/
static void Service (void)

{
         int            status;
         int            num_fds = 0;
         fd_set         read_fds,
                        write_fds,
                        except_fds;
         struct timeval timeout_val =
                               {
                                   (long) 2, /* seconds      */
                                   (long) 0  /* microseconds */
                               };
         unsigned int   counter = 0;
         int            is_set;
         unsigned int   i;

   printf("\t_____________Begin Service________________\n");

   /*
    * For this example, not interested in
    * 'write' or 'exception' triggers.  But
    * these can be very useful in a full-up,
    * real system ... especially the 'exceptions'
    * mask.
    */
   FD_ZERO(&write_fds); 
   FD_ZERO(&except_fds); 

   for (;;)
   {
       num_fds = 0;

       FD_ZERO(&read_fds); 

       FD_SET(listen_socket, &read_fds);

       #ifdef WIN32
       num_fds = 0;
       #else
       num_fds = listen_socket;
       #endif

       for (i = 0; i < MAX_NUM_CLIENTs; i++)
       {
           if (client_sockets[i])
           {
               FD_SET(client_sockets[i], &read_fds);

               #ifndef WIN32
               num_fds = num_fds + client_sockets[i];
               #endif
           }
       }

       /*
        * Have to set 'timeout' each time because
        * the select() resets it to "how much time
        * was left", which is 0 on a timeout.
        */
       timeout_val.tv_sec  = 2;
       timeout_val.tv_usec = 0;

       printf("---> Select on %d sockets\n", num_fds);

       #ifndef WIN32
       num_fds++; /* see 'man' page on 'select()' */
       #endif

       status = select (num_fds,  /* WIN32 ignores 'nfds' */
                        &read_fds,
                        &write_fds,
                        &except_fds,
                        &timeout_val);

       if (status == SOCKET_ERROR)
       {
           Show_Error ("Error from 'select'\n");
       }
       else if (status == 0)
       {
           printf("\t---> Timeout (status = %d) (%u)\n",
                  status,
                  counter++);

           if (counter == 15)
           {
               printf("***> No traffic - exit\n");

               break;
           }
       }
       else
       {
           counter = 0;

           for (i = 0; i < MAX_NUM_CLIENTs; i++)
           {
               if ( client_sockets[i] )
               {
                   is_set = FD_ISSET(client_sockets[i], &read_fds);

                   if (is_set)
                   {
                       Receive_Message(i);
                   }
               }
           }

           is_set = FD_ISSET(listen_socket, &read_fds);

           if (is_set)
           {
               printf("---> listen socket triggered\n");

               Accept_New_Client();
           }

           /*
            * Would probably be good to check
            * the 'exceptions' mask here ... but
            * skip for this example.
            */
       }
   }

   printf("\t__________________________________________\n");
}


/***********************************************
* FUNCTION: Receive_Message
*
* DESCRIPTION:
*    Receives an incoming message off the given
*    socket.
************************************************/
static void Receive_Message (const unsigned int index)

{
         char   message[2 * 1024];
         int    flags = 0;
         int    status;
         int    len;
         int    err_num;
         SOCKET s = client_sockets[index];

   memset (message, 0, sizeof(message));

   status = recv (s, message, sizeof(message), flags);

   if (status == SOCKET_ERROR)
   {
       err_num = Get_Last_Error();

       switch (err_num)
       {
           case WSAECONNABORTED:
           case WSAECONNRESET:
           case WSAENOTCONN:
           case WSAESHUTDOWN:
           {
               printf("\t---> Connection to client %u is closed\n",
                      index);

               Shutdown (client_sockets[index]);

               client_sockets[index] = 0;

               break;
           }
       
           default:
           {
               Show_Error ("Error receiving message");
           }
       }
   }
   else
   {
       printf("\tMessage received...: %s\n",
              message);

       /*
        * Send echo reply ...
        */
       sprintf(message, "Message received and understood\r\n\r\n");

       len = (int) strlen (message);

       status = send (s, message, len, flags);

       if (status == SOCKET_ERROR)
       {
           Show_Error ("Error sending ack");
       }
   }
}


/***********************************************
* FUNCTION: Accept_New_Client
*
* DESCRIPTION:
*    Accepts a connection request from a new
*    client via the 'listening socket'.
************************************************/
static void Accept_New_Client(void)

{
         struct sockaddr addr_of_new_client;
         int             addr_size = sizeof(struct sockaddr);
         SOCKET          new_socket;
         unsigned int    i;

   memset (&addr_of_new_client, 0, sizeof(addr_of_new_client));

   #ifdef WIN32
      #define ADDR_SIZE int
   #else
      #define ADDR_SIZE socklen_t
   #endif

   new_socket = accept
                  (listen_socket,
                   &addr_of_new_client,
                   (ADDR_SIZE *) &addr_size);

   if ( new_socket == INVALID_SOCKET )
   {
       Show_Error ("Accept of new client failed\n");
   }
   else
   {
       for (i = 0; i < MAX_NUM_CLIENTs; i++)
       {
           if (client_sockets[i] == 0)
           {
               client_sockets[i] = new_socket;

               return;
           }
       }

       printf("===> Max number of clients exceeded (%u)\n",
              MAX_NUM_CLIENTs);
   }
}


/***********************************************
* FUNCTION: Shutdown
*
* DESCRIPTION:
*    Issues both a 'shutdown' and a 'close' on
*    the specified socket.
************************************************/
static void Shutdown (SOCKET which_socket)

{
         int status;
         int how =  /* disable both sends and receives */
                #ifdef WIN32
                    SD_BOTH;
                #else
                    SHUT_RDWR;
                #endif

   status = shutdown(which_socket, how);

   printf("---> shutdown status = %d\n", status);

   #ifdef WIN32

      closesocket (which_socket);

   #else

      close (which_socket);

   #endif
}


/***********************************************
* FUNCTION: Show_Error
*
* DESCRIPTION:
*    Utility that queries the system to determine
*    what error has occurred and writes the info
*    to <stdout>.
************************************************/
static void Show_Error
               (const char *msg)

{
   char buffer[1024];
   int  err_num = 0;

   memset (buffer, 0, sizeof(buffer));

   #ifdef WIN32

      err_num = Get_Last_Error();

      FormatMessageA
            (FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
             NULL,
             err_num,
             MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
             buffer,
             (DWORD) sizeof(buffer),
             NULL);

   #else

      sprintf(buffer, "%s", msg);

      perror (buffer);

   #endif

   printf("_________SOCKET_ERROR______\n");
   printf("***> Message...: %s\n", msg);
   printf("***> Err Num...: %d\n", err_num);
   printf("***> Report....: %s\n", buffer);
   printf("___________________________\n");
}


/***********************************************
* FUNCTION: Show_Usage_And_Exit
*
* DESCRIPTION:
*    Called when the command-line args are not
*    correct.  Issues a 'how to' message to
*    <stdout>.
************************************************/
static void Show_Usage_And_Exit (void)

{
   printf("***> ERROR - invalid argument(s)\n"
          "***> USAGE:\n"
          "***>    server <port-num>\n"
          "***> EXAMPLE:\n"
          "***>    server 25555\n");

   exit (EXIT_FAILURE);
}


/***********************************************
* FUNCTION: Get_Last_Error
*
* DESCRIPTION:
*    Thin layer over OS utility that reports
*    the value of the last system error.
************************************************/
static int Get_Last_Error (void)

{
   #ifdef WIN32

      return WSAGetLastError();

   #else

      return errno;

   #endif
}

/* EOF */

