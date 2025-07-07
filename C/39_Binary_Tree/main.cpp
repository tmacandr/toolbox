/*----------------------------------------------------------------------------
 * FILE: main.cpp
 *
 * DESCRIPTION:
 *    Program that uses the 'binary_tree' class to input a sequence of
 *    integers.  Contents are then printed as a sorted array ... and then
 *    as a 'faux' binary tree (though upside down).
 *
 *    Note - makes use of the 'Regular Expression' class from the
 *    'std' library to verify that only integers are inserted into the
 *    binary tree.  This is pretty cool ... needs to be investigated
 *    more.
 *
 * COPYRIGHT:
 *    Copyright (c) 2024
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
 *--------------------------------------------------------------------------*/

#include <iostream>
#include <regex>
#include <binary_tree.h>


static const unsigned int MAX_NUM_INTs = 64;


/*----------------------------------------------
 * FUNCTION: main
 *
 * DESCRIPTION:
 *    Program main entry point.
 *---------------------------------------------*/
int main (int argc, char **argv)

{
   int             next_int;
   std::string     in_string;
   Binary_Tree     tree;
   unsigned int    i;
   unsigned int    num_ints = 0;

   std::cout << "---> Begin: Question 14" << std::endl;

   const std::regex pattern("[a-z,A-Z]");

   for (i = 0; i < MAX_NUM_INTs; i++)
   {
       std::cout << "---> Enter number (x to end)......: ";
       std::cin >> in_string;

       if ( in_string.compare("x") == 0 )
       {
           break;
       }

       bool is_alpha = std::regex_match (in_string, pattern);

       if ( ! is_alpha )
       {
           next_int = std::stoi(in_string);

           tree.Add (next_int);

           std::cout << "--------------------------------------" << std::endl;
       }
       else
       {
           std::cout << "***> ERROR - invalid entry" << std::endl;
       }
   }

   num_ints = tree.Num_Nodes();

   if ( num_ints == 0 )
   {
       std::cout << "---> No elements" << std::endl;

       return 0;
   }

   std::cout << "---> Sorted List: " << std::endl;

   tree.Print();

   std::cout << "---> Binary Tree: " << std::endl;

   tree.Print_As_Treee();

   return 0;
}

/* EOF */

