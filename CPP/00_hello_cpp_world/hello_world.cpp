/*******************************************************
 * FILE: hello_world.cpp
 *
 * DESCRIPTION:
 *    Hello world in C++.
 *
 *    Looks like I added a test to use the <vector> from
 *    the Standard-Template-Library (STL).
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
 ********************************************************/

#include <stdio.h>
#include <vector>


/***************************************
* FUNCTION: main
*
* DESCRIPTION:
*    Main entry point of program.
****************************************/
int main (int argc, char **argv)

{
      std::vector<int> vec;

   printf("______________________\n");
   printf("hello C++ world\n");
   printf("______________________\n");

   vec.push_back(1);
   vec.push_back(2);
   vec.push_back(3);

   for (unsigned int i = 0; i < vec.size(); i++)
   {
       printf("   vec[%d]....: %d\n", i, vec[i]);
   }

   return 0;
}
