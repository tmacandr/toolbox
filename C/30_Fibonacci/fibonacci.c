/*****************************************************************************
* FILE: fibonacci.c
*
* DESCRIPTION:
*    Implements a function to calculate Fibonacci numbers.  The function
*    takes an index and calculates the corresponding Fibonacci number, using
*    the index as the position of the number in the Fibonacci series.
*    For example, given 'n', the Fibonacci numbers are:
*
*            n        Fibonacci
*         ---------------------------
*            0           -
*            1           1
*            2           2
*            3           3 (2 + 1)
*            4           5 (3 + 2)
*            5           8 (5 + 3)
*            6          13 (8 + 5)
*
*    Right back at ya, Dr DeVore ...
*
* COPYRIGHT:
*    Copyright (c) 2016, Tim MacAndrew
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


static int Fibonacci(const unsigned int n);


/***************************************
* FUNCTION: main
*
* DESCRIPTION:
*    Main entry point of program.
****************************************/
int main (int argc, char **argv)

{
   int          f = -1;
   unsigned int n = 0;

   if (argc != 2)
   {
       printf("***> ERROR - invalid argument(s)\n"
              "***> Usage:\n"
              "***>    fibonacci <n>\n"
              "***> Example:\n"
              "***>    fibonacci 5\n");

       return -1;
   }

   sscanf(argv[1], "%u", &n);

   f = Fibonacci(n);

   printf("---> The %uth Fibonacci number is...: %d\n", n, f);

   return 0;
}


/***************************************
* FUNCTION: Fibonacci
*
* DESCRIPTION:
*    Calculates the nth Fibonacci number.
****************************************/
static int Fibonacci(const unsigned int n)

{
   int f;

   if ( ( n == 0 ) ||
        ( n == 1 ) ||
        ( n == 2 ) ||
        ( n == 3 ) )
   {
       return n;
   }

   f = Fibonacci(n - 1) + Fibonacci(n - 2);

   return f;
}

/* EOF */
