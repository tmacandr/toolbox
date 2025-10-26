/*------------------------------------------------------------------
* FILE: serial_port.c
*
* DESCRIPTION:
*    Demo to do serial I/O via COM1 on PC or a serial device on
*    Linux.
*
*       From: MacAndrew, Tim -Gil <Tim.MacAndrew@itt.com>
*       To: surf_lump@netzero.net <surf_lump@netzero.net>
*       Subject: Serial Port I/O
*       Date: Monday, January 26, 2004 1:30 PM
*-------------------------------------------------------------------*/
#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef WIN32
   #include <io.h>
   #include <FCNTL.H>
#else
   #include <fcntl.h>
   #include <sys/select.h>
   #include <termios.h>
   #include <unistd.h>
#endif


static void send_message(int        serial_port,
                         const char *msg);

static void receive_response(int  serial_port,
                             char *response);


/*--------------------------------------------------
 * FUNCTION: main
 *
 * DESCRIPTION:
 *    Main entry of program.
 *--------------------------------------------------*/
int main (int argc, char **argv)
{
   int serial_port = -1;
   int s;

   if (argc != 2)
   {
       printf("***> ERROR - device not specified\n"
              "***> USAGE:\n"
              "***>    serial_port <device>\n"
              "***> EXAMPLE:\n"
              "***>    LINUX: serial_port /dev/ttyUSB1"
              "***>    WIndows: serial_port COM1\n");
       return EXIT_FAILURE;
   }

   printf("---> Device: %s\n", argv[1]);

   #ifdef WIN32 
   serial_port = _open (argv[1], _O_RDWR);
   #else
   serial_port = open(argv[1], O_RDWR | O_NOCTTY); 
   #endif

   if (serial_port == -1)
   {
       printf("***> FAIL - can't open serial device\n");

       return EXIT_FAILURE;
   }

   s = isatty(serial_port);

   if (s == 0)
   {
       printf("***> ERROR - Not a TTY device\n");
       close(serial_port);
       return EXIT_FAILURE;
   }

   struct termios tty;

   memset(&tty, 0, sizeof(struct termios));

   s = tcgetattr(serial_port, &tty);

   if (s != 0)
   {
       printf("***> ERROR - Get serial port setting fail\n");
       close(serial_port);
       return EXIT_FAILURE;
   }

   cfsetospeed(&tty, B115200); /* output baud rate */

   cfsetispeed(&tty, B115200); /* input baud rate */

   /* cflag settings */
   tty.c_cflag &= ~CSIZE;         // clear any 'size' setting
   tty.c_cflag |= CS8;            // set size to 8-bit chars
   tty.c_cflag &= ~PARENB;        // no parity
   tty.c_cflag &= ~CSTOPB;        // 1 stop bit
   tty.c_cflag &= ~CRTSCTS;       // software ctrl off
   tty.c_cflag |= CREAD | CLOCAL; // Enable rcvr, ignore model ctrl

   /* iflag settings */
   tty.c_iflag &= ~(IXON | IXOFF | IXANY); // hardware ctrl      - OFF
   tty.c_iflag &= ~INPCK;                  // input parity check - OFF

   /*
    * lflag settings
    *   ICANON  - canonical mode - allow <NL> <LF> <EOL>, ignore modem ctrl
    *   ISIG    - allow <ctrl>-c, <ctrl>-d, etc to generate OS signals
    *   ECHO    - send chars to terminal as they are received - OFF
    *   ECHOE   - map <erase> key as <back-space> key         - OFF    
    *   ECHONL  - echo <NL> to terminal even if ECHO is off   - OFF
    *   IEXTEN  - enable vendo extensions/functions           - OFF
    *   INCLR   - map <NL> to <CR>                            - OFF
    *   IGNCR   - ingore <CR>                                 - OFF
    *   IUCLC   - convert uppercase to lowercase              - OFF
    *   IMAXBEL - generate ASCII BEL on stream overflow       - OFF
    */
   tty.c_lflag |= (ICANON | ISIG); 
   tty.c_lflag &= ~(ECHO | ECHOE | ECHONL | IEXTEN);

   /*
    * oflag settings
    *   OPOST - perform post processing before send - OFF
    */
   tty.c_oflag &= ~OPOST;

   s = tcsetattr(serial_port, TCSANOW, &tty);

   if (s != 0)
   {
       printf("***> ERROR - Set serial port configuration fail\n");
       close(serial_port);
       return EXIT_FAILURE;
   }

   s = tcflush(serial_port, TCIOFLUSH);

   if (s != 0)
   {
       printf("***> ERROR - flush port fail\n");
       close(serial_port);
       return EXIT_FAILURE;
   }

   send_message(serial_port, "hello world\n");

   char answer[1024];

   memset(answer, 0, sizeof(answer));

   receive_response(serial_port, answer);

   printf("---> Response (size = %lu): %s\n",
          strlen(answer),
          answer);

   close (serial_port);

   printf("---> Test completed\n");

   return EXIT_SUCCESS;
}


/*--------------------------------------------------
 * FUNCTION: send_message
 *
 * DESCRIPTION:
 *    Send given message through serial port.
 *--------------------------------------------------*/
static void send_message(int        serial_port,
                         const char *msg)
{
    int n;

    size_t msg_len = strlen(msg);

    n = write(serial_port, msg, msg_len);

    if (n != (int) msg_len)
    {
        printf("***> ERROR - send fail\n"
               "***>       - actual count....: %d\n"
               "***>       - expected count..: %d\n",
               n,
               (int) msg_len);
    }
}


/*--------------------------------------------------
 * FUNCTION: receive_response 
 *
 * DESCRIPTION:
 *    Receive a message from the serial port.
 *--------------------------------------------------*/
static void receive_response(int  serial_port,
                             char *response)
{
    char           b;
    int            num_bytes;
    fd_set         rd_set;
    fd_set         wr_set;
    fd_set         ex_set;
    struct timeval timeout;
    int            s;
    int            nfds = serial_port + 1;
    unsigned int   i    = 0;

    for (;;)
    {
        FD_ZERO(&rd_set);
        FD_ZERO(&wr_set);
        FD_ZERO(&ex_set);

        FD_SET(serial_port, &rd_set);

        timeout.tv_sec  = 0;
        timeout.tv_usec = 50000;

        s = select(nfds, &rd_set, &wr_set, &ex_set, &timeout);

        if (s == -1)
        {
            printf("***> ERROR - select for read fail\n");

            return;
        }
        else if (s == 0)
        {
            break;
        }
        else
        {
            b = 0;

            #ifdef WIN32
            num_bytes = _read (serial_port, (void *) &b, 1);
            #else
            num_bytes = read(serial_port, &b, 1);
            #endif

            if (num_bytes > 0)
            {
                response[i++] = b;
            }
        }
    }

    response[i] = 0;
}

