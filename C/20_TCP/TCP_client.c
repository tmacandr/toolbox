/*****************************************************************************
* FILE: TCP_client.c
*
* DESCRIPTION:
*    Implements a bare-bones network client.  Creates a TCP socket and
*    issues a connection request to the specified server.
*
*    User types an ASCII text message, which is then sent to the server.  The
*    client then waits for the favor of a reply.  On command, the socket is
*    closed.
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

   #define SOCKET_ERROR (-1)

   #define WSAEWOULDBLOCK     EWOULDBLOCK
   #define WSAECONNABORTED    ECONNABORTED
   #define WSAECONNRESET      ECONNRESET
   #define WSAENOTCONN        ENOTCONN
   #define WSAESHUTDOWN       ESHUTDOWN

   #define min(a,b) ( ( (a) < (b)) ? (a) : (b) )

   #define Sleep(t)   sleep(t / 1000)

#endif

static void Initialize (char **argv);
static void Request_Connection (void);
static void Service (void);
static void Shutdown (void);
static void Show_Error (const char *msg);
static void Show_Usage_And_Exit (void);
static int  Get_Last_Error (void);

static SOCKET the_socket = 0;

static unsigned short port_num = 0;

static char svr_IP_addr_name[16] = "000.000.000.000";


/***********************************************
* FUNCTION: main
*
* DESCRIPTION:
*    Main entry point of program.
************************************************/
int main (int argc, char **argv)

{
   printf("_____________TCP Client________________________\n");

   if (argc != 3)
   {
       Show_Usage_And_Exit ();
   }

   Initialize (argv);

   Request_Connection ();

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

   #else

   #endif

   memset (svr_IP_addr_name, 0, sizeof(svr_IP_addr_name));

   len = min((int)strlen(argv[1]), sizeof(svr_IP_addr_name) - 1);

   strncpy(svr_IP_addr_name, argv[1], len);

   sscanf(argv[2], "%hu", &port_num);

   printf("Server:\n"
          "   IP-address...: %s\n"
          "   port.........: %hu\n",
          svr_IP_addr_name,
          port_num);
}


/***********************************************
* FUNCTION: Request_Connection
*
* DESCRIPTION:
*    Creates a TCP socket and requests a connection
*    to the server.
************************************************/
static void Request_Connection (void)

{
         struct sockaddr_in svr_IP_address_info;
         int                addr_info_len = sizeof(svr_IP_address_info);
         unsigned long      svr_IP_addr;
         int                status;

   the_socket = socket
                  (AF_INET,      /* domain   */
                   SOCK_STREAM,  /* type     */
                   IPPROTO_TCP); /* protocol */

   if (the_socket == SOCKET_ERROR)
   {
       Show_Error ("Create of socket failed");

       exit (EXIT_FAILURE);
   }

   svr_IP_addr = inet_addr(svr_IP_addr_name);

   svr_IP_address_info.sin_family      = AF_INET;
   svr_IP_address_info.sin_addr.s_addr = svr_IP_addr;
   svr_IP_address_info.sin_port        = htons(port_num);

   status = connect
               (the_socket,
                (const struct sockaddr *) &svr_IP_address_info,
                addr_info_len);

   if (status == SOCKET_ERROR)
   {
       Show_Error ("Connect request to svr failed");

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
         char           message[1024];
         int            msg_size;
         int            flags = 0;
         int            is_set;
         int            err_num;
         unsigned int   timeout_count = 0;

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
       memset (message, 0, sizeof(message));

       printf("\tType message to send (type 'exit' to end)...: ");
       scanf ("%s", message);

       //printf("you typed...: %s\n", message);

       if ( strncmp (message, "exit", 4) == 0 )
       {
           break;
       }

       msg_size = (int) strlen(message);

       message[msg_size + 0] = '\r';
       message[msg_size + 1] = '\n';
       message[msg_size + 2] = '\r';
       message[msg_size + 3] = '\n';

       msg_size = msg_size + 4;

       status = send (the_socket, message, msg_size, flags);

       if (status == SOCKET_ERROR)
       {
           Show_Error ("Error sending message\n");

           break;
       }

       FD_ZERO(&read_fds); 

       FD_SET(the_socket, &read_fds);

       #ifdef WIN32

          num_fds = 0;  /* In Win API 'nfds' is ignored */

       #else

          num_fds = the_socket;

          num_fds++; /* see 'man' page for select() */

       #endif

       for (;;)
       {
           /*
            * Have to set 'timeout' each time because
            * the select() resets it to "how much time
            * was left", which is 0 on a timeout.
            */
           timeout_val.tv_sec  = 2;
           timeout_val.tv_usec = 0;

           status = select (num_fds,
                            &read_fds,
                            &write_fds,
                            &except_fds,
                            &timeout_val);

           if (status == SOCKET_ERROR)
           {
               Show_Error ("Error from 'select'\n");

               Sleep (5000);
           }
           else if (status == 0)
           {
               printf("\t---> Timeout %u (no msg rcv'd)\n", timeout_count++);

               if (timeout_count == 15)
               {
                   printf("***> No traffic\n");

                   break;
               }
           }
           else
           {
               is_set = FD_ISSET(the_socket, &read_fds);

               if (is_set)
               {
                   memset (message, 0, sizeof(message));

                   status = recv (the_socket, message, sizeof(message), flags);

                   if ( status == SOCKET_ERROR )
                   {
                       err_num = Get_Last_Error ();

                       switch (err_num)
                       {
                           case WSAECONNABORTED:
                           case WSAECONNRESET:
                           case WSAENOTCONN:
                           case WSAESHUTDOWN:
                           {
                               printf("\t---> Connection to server is closed\n");

                               Shutdown ();

                               return;
                           }
       
                           default:
                           {
                               Show_Error ("Error receiving message");
                           }
                       }
                   }
                   else
                   {
                       printf("\tMessage received...: %s\n", message);
                   }
               
                   break;
               }
               else
               {
                   printf("***> UNKNOWN ERROR\n"
                          "***> 'select' triggered ... but no message\n");

                   return;
               }
           }
       }
   }

   printf("\t__________________________________________\n");
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
         int how =  /* disable both sends and receives */
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

   err_num = Get_Last_Error();

   #ifdef WIN32

      FormatMessageA
            (FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
             NULL,
             err_num,
             MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
             buffer,
             (DWORD) sizeof(buffer),
             NULL);

   #else

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
          "***>    client <svr-IP-addr> <port-num>\n"
          "***> EXAMPLE:\n"
          "***>    client 127.0.0.1 25555\n");

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


