/*****************************************************************************
* FILE: UDP_client.c
*
* DESCRIPTION:
*    Implements a bare-bones network client.  Creates a UDP socket and
*    issues a connection request to the specified server.
*
*    User types an ASCII text message, which is then sent to the server.  The
*    client then waits for the favor of a reply.  On command, the socket is
*    closed.
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

   #define min(x, y)  ( ( (x) < (y) ? (x) : (y) ) )

#endif

static void Initialize (char **argv);
static void Setup_Socket (void);
static void Service (void);
static void Receive_Message (void);
static void Shutdown (void);
static void Show_Error (const char *msg);
static void Show_Usage_And_Exit (void);


static SOCKET the_socket = 0;

static unsigned short svr_port_num = 0;

static unsigned short client_port_num = 0;

static char svr_IP_addr_name[16] = "000.000.000.000";


/***********************************************
* FUNCTION: main
*
* DESCRIPTION:
*    Main entry point of program.
************************************************/
int main (int argc, char **argv)

{
   printf("_____________UDP Client________________________\n");

   if (argc != 4)
   {
       Show_Usage_And_Exit ();
   }

   Initialize (argv);

   Setup_Socket ();

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
static void Initialize (char **argv)

{
            unsigned int len;

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

   memset (svr_IP_addr_name, 0, sizeof(svr_IP_addr_name));

   len = min((int)strlen(argv[1]), sizeof(svr_IP_addr_name) - 1);

   strncpy(svr_IP_addr_name, argv[1], len);

   sscanf(argv[2], "%hu", &svr_port_num);

   printf("Server info:\n"
          "   IP-address...: %s\n"
          "   port.........: %hu\n",
          svr_IP_addr_name,
          svr_port_num);
}


/***********************************************
* FUNCTION: Setup_Socket
*
* DESCRIPTION:
*    Creates a UDP socket and requests a connection
*    to the server.
************************************************/
static void Setup_Socket (void)

{
         struct sockaddr_in address_info;
         int                addr_info_len = sizeof(address_info);
         int                status;

   the_socket = socket
                  (AF_INET,      /* domain   */
                   SOCK_DGRAM,   /* type     */
                   IPPROTO_UDP); /* protocol */

   if (the_socket == SOCKET_ERROR)
   {
       Show_Error ("Create of socket failed");

       exit (EXIT_FAILURE);
   }

   /*
    * Bind the socket to this ethernet card (or
    * whichever device has the IP address).
    */
   address_info.sin_family      = AF_INET;
   address_info.sin_addr.s_addr = INADDR_ANY;
   address_info.sin_port        = htons ( client_port_num );

   status = bind
              (the_socket, 
               (const struct sockaddr *) &address_info, 
               addr_info_len);

   if (status == SOCKET_ERROR)
   {
       Show_Error ("bind failed");

       Shutdown ();

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
         int                status;
         int                num_fds = 0;
         fd_set             read_fds,
                            write_fds,
                            except_fds;
         struct timeval     timeout_val =
                               {
                                   (long) 2, /* seconds      */
                                   (long) 0  /* microseconds */
                               };
         struct sockaddr_in addr_of_svr;
         int                addr_info_len = sizeof(addr_of_svr);
         unsigned long      svr_IP_addr;
         char               message[1024];
         int                len;
         int                flags = 0;
         unsigned int       counter = 0;
         int                is_set;

   printf("\t_____________Begin Service________________\n");

   FD_ZERO(&write_fds); 
   FD_ZERO(&except_fds); 

   for (;;)
   {
       memset (message, 0, sizeof(message));

       printf("\t---> Enter message to send...: ");
       scanf ("%s", message);
       printf("\n");

       if ( strncmp(message, "exit", 4) == 0 )
       {
           return;
       }

       len = (int) strlen (message);

       svr_IP_addr = inet_addr(svr_IP_addr_name);

       addr_of_svr.sin_family      = AF_INET;
       addr_of_svr.sin_addr.s_addr = svr_IP_addr;
       addr_of_svr.sin_port        = htons(svr_port_num);

       status = sendto
                   (the_socket,
                    message,
                    len,
                    flags,
                    (const struct sockaddr *) &addr_of_svr,
                    addr_info_len);

       if (status == SOCKET_ERROR)
       {
           Show_Error ("Error sending message'\n");

           Shutdown ();

           exit (EXIT_FAILURE);
       }

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

               Shutdown ();

               exit (EXIT_FAILURE);
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

                   break;
               }
           }
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
static void Receive_Message (void)

{
         char               message[2 * 1024];
         int                flags = 0;
         int                status;
         int                err_num;
         struct sockaddr_in addr_of_sender;
         socklen_t          sender_info_size = sizeof(addr_of_sender);

   memset (message, 0, sizeof(message));

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
   }
}


/***********************************************
* FUNCTION: Shutdown
*
* DESCRIPTION:
*    Issues both a 'shutdown' and a 'close' on
*    the socket.
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
          "***>    client <svr-IP-addr> <svr-port-num> <client-port-num>\n"
          "***> EXAMPLE:\n"
          "***>    client 127.0.0.1 25555  25556\n");

   exit (EXIT_FAILURE);
}
