/*****************************************************************************
* FILE: ohms_law.c
*
* DESCRIPTION:
*    Demo prompting user for input.  User enters "Resistance" and "Voltage"
*    and "Current" is produced:
*
*                     V = IR
*
* COPYRIGHT:
*    Copyright (c) 2004, Sally Recuas (Sally_Recuas@yahoo.com)
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
int main (void)

{
   double V = 0.0;
   double R = 0.0;
   double I = 0.0;

   printf("Enter resistance:\n");
   scanf("%lf", &R);

   printf("Enter voltage:\n");
   scanf("%lf", &V);

   I = V / R;

   printf("For V = %4.3lf and R = %3.4lf the Currnt is: %4.3lf\n",
          V,
          R,
          I);

   return 0;
}

/* EOF */

