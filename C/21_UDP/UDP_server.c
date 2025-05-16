/*****************************************************************************
* FILE: UDP_server.c
*
* DESCRIPTION:
*    Implements a bare-bones network server.  Opens a listening socket and
*    waits for connections.  Sockets are implemented using UDP.
*
*    Receives messages of ASCII text and replies with a simple ack.  Accepts
*    one or more clients simultaneously.  Will close peer-to-peer socket when
*    initiated by the client and will accept new connections form the same or
*    different clients.
*
* COPYRIGHT:
*    Copyright (c) 2024, Tim MacAndrew (six_eight_squash@yahoo.com)
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


#ifdef WIN32

   #include <Winsock2.h>

   #define ECONNABORTED WSAECONNABORTED
   #define ECONNRESET   WSAECONNRESET
   #define ENOTCONN     WSAENOTCONN
   #define ESHUTDOWN    WSAESHUTDOWN

#else

   /*
    * Assume UNIX
    */
   #include <string.h>
   #include <unistd.h>
   #include <sys/types.h>
   #include <sys/socket.h>
   #include <netinet/in.h>
   #include <arpa/inet.h>
   #include <errno.h>

   #define SOCKET int

   #define SOCKET_ERROR (-1)

#endif

static void Initialize (void);
static void Create_Socket (void);
static void Service (void);
static void Send_Reply_Message (char *message, struct sockaddr_in to);
static void Receive_Message (void);
static void Shutdown (void);
static void Show_Error (const char *msg);
static void Show_Usage_And_Exit (void);


static unsigned short port_num = 0;

static SOCKET the_socket = 0;


/***********************************************
* FUNCTION: main
*
* DESCRIPTION:
*    Main entry point of program.
************************************************/
int main (int argc, char **argv)

{
   printf("_____________UDP Server________________________\n");

   if (argc != 2)
   {
       Show_Usage_And_Exit ();
   }

   sscanf(argv[1], "%hu", &port_num);

   Initialize ();

   Create_Socket ();

   Service ();

   Shutdown ();

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

   the_socket = 0;
}


/***********************************************
* FUNCTION: Create_Socket
*
* DESCRIPTION:
*    Creates a UDP socket that will be used for
*    sending and receiving messages to interested
*    clients.
*
*    Socket is bound to default device.
************************************************/
static void Create_Socket (void)

{
         int                status;
         struct sockaddr_in my_IP_address_info;
         char               host_name[1024];

   /*
    * Create the listen socket
    */
   the_socket = socket
                   (AF_INET,      /* domain   */
                    SOCK_DGRAM,   /* type     */
                    IPPROTO_UDP); /* protocol */

   if (the_socket == SOCKET_ERROR)
   {
       Show_Error ("Create of broadcast socket failed");

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
              (the_socket, 
               (const struct sockaddr *) &my_IP_address_info, 
               sizeof(my_IP_address_info));

   if (status == SOCKET_ERROR)
   {
       Show_Error ("bind() failed");

       Shutdown ();

       exit (EXIT_FAILURE);
   }

   memset (host_name, 0, sizeof(host_name));

   status = gethostname(host_name, sizeof(host_name));

   if (status == SOCKET_ERROR)
   {
       Show_Error("Call to 'gethostname' failed");

       Shutdown ();

       exit (EXIT_FAILURE);
   }

   printf("---> Host name....: %s\n", host_name);
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

   printf("\t_____________Begin Service________________\n");

   FD_ZERO(&write_fds); 
   FD_ZERO(&except_fds); 

   for (;;)
   {
       FD_ZERO(&read_fds); 

       FD_SET(the_socket, &read_fds);

       #ifdef WIN32
       num_fds = 0;
       #else
       num_fds = the_socket + 1;
       #endif

       /*
        * Have to set 'timeout' each time because
        * on UNIX the select() resets it to "how much time
        * was left", which is 0 on a timeout.
        */
       timeout_val.tv_sec  = 2; /* seconds  */
       timeout_val.tv_usec = 0; /* uSeconds */

       status = select (num_fds,
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
           printf("\t---> Timeout (%u)\n", counter++);
       }
       else
       {
           is_set = FD_ISSET(the_socket, &read_fds);

           if (is_set)
           {
               Receive_Message();
           }
       }
   }

   printf("\t__________________________________________\n");
}


/***********************************************
* FUNCTION: Send_Reply_Message
*
* DESCRIPTION:
*    Sends an acknowledge message to the sender.
************************************************/
static void Send_Reply_Message
                (char               *message,
                 struct sockaddr_in to)

{
         int status;
         int flags = 0;
         int len;
         int addr_size;

   len = (int) strlen (message);

   addr_size = sizeof(to);

   status = sendto
               (the_socket,
                message,
                len,
                flags,
                (const struct sockaddr *) &to,
                addr_size);

   if (status == SOCKET_ERROR)
   {
       Show_Error ("Error sending reply");

       Shutdown ();

       exit (EXIT_FAILURE);
   }
}


/***********************************************
* FUNCTION: Receive_Message
*
* DESCRIPTION:
*    Receives an incoming message off the given
*    socket.
************************************************/
static void Receive_Message (void)

{
         char               message[2 * 1024];
         int                flags = 0;
         int                status;
         int                err_num;
         struct sockaddr_in addr_of_sender;
         socklen_t          sender_info_size = sizeof(addr_of_sender);
         char               ack[4 * 1024];

   memset (message, 0, sizeof(message));

   memset (&addr_of_sender, 0, sender_info_size);

   status = recvfrom
               (the_socket,
                message,
                sizeof(message),
                flags,
                (struct sockaddr *) &addr_of_sender,
                &sender_info_size);

   if (status == SOCKET_ERROR)
   {
       #ifdef WIN32

          err_num = WSAGetLastError ();

       #else

          err_num = errno;

       #endif

       switch (err_num)
       {
           case ECONNABORTED:
           case ECONNRESET:
           case ENOTCONN:
           case ESHUTDOWN:
           {
               printf("\t---> Connection to client is closed\n");

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

       sprintf(ack, "Your message was '%s'", message);

       Send_Reply_Message (ack, addr_of_sender);
   }
}

/***********************************************
* FUNCTION: Shutdown
*
* DESCRIPTION:
*    Issues both a 'shutdown' and a 'close' on
*    the specified socket.
************************************************/
static void Shutdown (void)

{
         int status;
         int how = /* disable both sends and receives */
                #ifdef WIN32
                   SD_BOTH;
                #else
                   SHUT_RDWR;
                #endif

   status = shutdown(the_socket, how);

   printf("---> shutdown status = %d\n", status);

   #ifdef WIN32

      closesocket (the_socket);

   #else

      close (the_socket);

   #endif

   the_socket = 0;
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

      err_num = WSAGetLastError();

      FormatMessageA
            (FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
             NULL,
             err_num,
             MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
             buffer,
             (DWORD) sizeof(buffer),
             NULL);

   #else

      perror (msg);

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
          "***>    UDP_server <port-num>\n"
          "***> EXAMPLE:\n"
          "***>    USP_server 25555\n");

   exit (EXIT_FAILURE);
}
