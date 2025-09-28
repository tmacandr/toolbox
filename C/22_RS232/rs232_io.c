From: MacAndrew, Tim -Gil <Tim.MacAndrew@itt.com>
To: surf_lump@netzero.net <surf_lump@netzero.net>
Subject: Serial Port I/O
Date: Monday, January 26, 2004 1:30 PM


/*----------------------------------------------------------------------
--
* FILE: RS232_test.cpp
*
* DESCRIPTION:
*    Hello world to do serial I/O via COM1 on PC.
*-----------------------------------------------------------------------
--*/
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


       

************************************
This email and any files transmitted with it are proprietary and intended solely for the use of the individual or entity to whom they are addressed. If you have received this email
in error please notify the sender. Please note that any views or opinions presented in this email are solely those of the author and do not necessarily represent those of ITT Industries, Inc.
The recipient should check this email and any attachments for the presence of viruses. ITT Industries accepts no liability for any damage caused by any virus transmitted by this
email.
************************************
