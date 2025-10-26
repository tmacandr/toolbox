/*------------------------------------------------------------------
* FILE: RS232_test.cpp
*
* DESCRIPTION:
*    Hello world to do serial I/O via COM1 on PC.
*
*       From: MacAndrew, Tim -Gil <Tim.MacAndrew@itt.com>
*       To: surf_lump@netzero.net <surf_lump@netzero.net>
*       Subject: Serial Port I/O
*       Date: Monday, January 26, 2004 1:30 PM
*-------------------------------------------------------------------*/
#include <stdio.h>
#include <io.h>
#include <FCNTL.H>


int main (int argc,
          char **argv)

{
         int           com1_fd = 0;
         unsigned char uchar;
         int           status;

   com1_fd = _open
               ("COM1",
                _O_RDWR);

   if (com1_fd == -1)
   {
       printf("***> FAIL - can't open COM1\n");

       return 0;
   }

   printf("---> OK - COM1 opened\n");

   /*
    * Do ioctl here, right?
    */

   printf("---> attempt read - ATTN will block here\n");

   status = _read
              (com1_fd,
               (void *) &uchar,
               sizeof(uchar));

   if (status == 0)
   {
       printf("***> ERROR - read EOF from COM1\n");

       close (com1_fd);

       return 0;
   }

   if (status == -1)
   {
       printf("***> FAIL - error reading from COM1\n");

       close (com1_fd);

       return 0;
   }

   printf("---> read %hu from COM1\n", uchar);

   close (com1_fd);

   printf("---> Test completed\n");

   return 0;
}

