//----------------------------------------------------------------------------
// File : main_3_1.cpp
// Date : 30-Jul-00 : initial definition
//        23-Jan-26 : Update to GNU g++
//
// Description:
//    Exercise 3.1 from:
//
//       "The C++ Programming Language, 2nd Ed.",
//       B. Stroustroup, 1991 (1995).
//
//----------------------------------------------------------------------------

#include <iostream>
#include <string.h>

//------------------------------------------------
// main
//
// Description:
//    Rewrite the following 'for' statement as an
//    equivalent 'while' statement:
//
//       for (i = 0; i < max_length; i++)
//          if (input_line[i] == '?')
//             quest_count++;
//
//    Rewrite it to use a pointer as the controlled
//    variable, that is, so that the test is of the
//    form *p == '?'.
//------------------------------------------------
int main
      (int  argc,
       char **argv)

{
         int       i;
         int       max_length;
         char      *input_line = argv[argc - 1];
         int       quest_count = 0;

   max_length = strlen (input_line);

   //
   // Using 'for' loop
   //
   for (i = 0; i < max_length; i++)
      if (input_line[i] == '?')
         quest_count++;

   std::cout << "Number of question marks = " << quest_count << "\n";

   //
   // Using 'while' loop
   //
   quest_count = 0;

   i = 0;

   while (i < max_length)
      {
       if (input_line[i] == '?')
          quest_count++;

       i++;
      }

   std::cout << "Number of question marks = " << quest_count << "\n";

   //
   // Using a pointer as control variable
   //
   quest_count = 0;

   while ( *input_line )
      if ( *input_line++ == '?' )
         quest_count++;

   std::cout << "Number of question marks = " << quest_count << "\n";

   return 0;
}
