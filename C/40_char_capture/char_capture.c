/*****************************************************************************
* FILE: capture_char.c
*
* DESCRIPTION:
*    Uses LINUX utils to capture character input from the console before
*    echoing the character back to the console.
*
*    Password intercept might use something like this.
*
* COPYRIGHT:
*    Copyright (c) 2026, Tim MacAndrew (six_eight_squash@yahoo.com)
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

#include <curses.h>


/***************************************
* FUNCTION: main
*
* DESCRIPTION:
*    Main entry point of program.
****************************************/
int main (int argc, char **argv)

{
   initscr();

   printw("begin char capture\n");

   refresh();

   int c = 0;

   while (c != (int) 'x')
   {
       c = getch();

       printw(">%c<", (char) c);
   } 

   endwin();

   return 0;
}

/* EOF */

