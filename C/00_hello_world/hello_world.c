/*****************************************************************************
* FILE: hello_world.c
*
* DESCRIPTION:
*    Hello world ... used for showing how to build/run in a particular
*    tools/dev environment.
*
* COPYRIGHT:
*    Copyright (c) 2004, Tim MacAndrew (six_eight_squash@yahoo.com)
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
******************************************************************************/

#include <stdio.h>


/***************************************
* FUNCTION: main
*
* DESCRIPTION:
*    Main entry point of program.
****************************************/
int main (int argc, char **argv)

{
   printf("hello world\n");
   printf("   Sizes of scalars:\n");
   printf("      char.....................: %lu\n", sizeof(char));
   printf("      uchar....................: %lu\n", sizeof(unsigned char));
   printf("      short....................: %lu\n", sizeof(short int));
   printf("      unsigned short...........: %lu\n", sizeof(unsigned short int));
   printf("      int......................: %lu\n", sizeof(int));
   printf("      unsigned int.............: %lu\n", sizeof(unsigned int));
   printf("      long int.................: %lu\n", sizeof(long int));
   printf("      unsigned long int........: %lu\n", sizeof(unsigned long int));
   printf("      long long int............: %lu\n", sizeof(long long int));
   printf("      unsigned long long int...: %lu\n",
          sizeof(unsigned long long int));
   printf("      float....................: %lu\n", sizeof(float));
   printf("      double...................: %lu\n", sizeof(double));
 
   return 0;
}

/* EOF */

