/*----------------------------------------------------------------------------
 * File: bin_2_ascii.c
 * Date: 03-Apr-16
 *
 * Description:
 *    Converts a specified file of binary data to ASCII readable
 *    hex format.  Output is dumped to the screen (i.e. <stdout>).
 *
 * COPYRIGHT:
 *    Copyright (c) 2016
 *        Tim MacAndrew (six_eight_squash@yahoo.com)
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
*---------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void Read_File
               (const char *filename,
                unsigned char **buf,
                unsigned int  *length);

static void Save_As_ASCII_Hex
               (const unsigned char *buf,
                const unsigned int  length);


/*----------------------------------------------
 * main
 *
 * Description:
 *    Main entry point of program.
 *--------------------------------------------*/
int main (int argc, char **argv)

{
         unsigned char *buffer = NULL;
         unsigned int  length = 0;

   if (argc != 2)
   {
       printf("\n\nUsage\n");
       printf("    bin_2_ascii <full-path-to-file>\n\n");

       return -1;
   }

   printf("________________\n");

   printf("File Name...: %s\n", argv[1]);

   Read_File (argv[1], &buffer, &length);

   Save_As_ASCII_Hex (buffer, length);

   free (buffer);

   printf("________________\n");

   return 0;
}


/*----------------------------------------------
 * FUNCTION: Read_File
 *
 * Description:
 *    Open, read, and load the contents of the
 *    specified file into a buffer.  The buffer
 *    is allocated here.
 *
 *    It is the responsibility of the caller
 *    to free the buffer when done.
 *--------------------------------------------*/
static void Read_File
               (const char    *filename,
                unsigned char **buf,
                unsigned int  *length)

{
         FILE *fd;

   fd = fopen (filename, "rb");

   if (fd == NULL)
   {
       printf("***> File '%s' not found\n", filename);

       exit (EXIT_FAILURE);
   }

   fseek(fd, 0L, SEEK_END);

   *length = ftell(fd);

   printf("---> File size...: %u\n", *length);

   rewind (fd);

   *buf = (unsigned char *) malloc(*length);

   memset(*buf, 0, *length);

   fread (*buf, *length, 1, fd);

   fclose (fd);
}


/*----------------------------------------------
 * FUNCTION: Save_As_ASCII_Hex
 *
 * Description:
 *    Open, read, and load the contents of the
 *    specified file into a buffer.  The buffer
 *    is allocated here.
 *
 *    It is the responsibility of the caller
 *    to free the buffer when done.
 *--------------------------------------------*/
static void Save_As_ASCII_Hex
               (const unsigned char *buf,
                const unsigned int  length)

{
   unsigned int i;

   for (i = 0; i < length; i++)
   {
       printf("%#.2x ", buf[i]);

       if ( i != 0 )
       {
           if ( ( i % 8 ) == 7 )
           {
               printf("\n");
           }
       }
   }

   printf("\n");
}

/* EOF */
