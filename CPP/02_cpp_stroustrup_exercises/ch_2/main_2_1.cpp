//----------------------------------------------------------------------------
// File : main_2_1.cpp
// Date : 25-Jul-99 : initial definition
//        30-Jul-00 : re-organize exercises for each chapter
//
// Description:
//    Exercise 2.1 from:
//
//       "The C++ Programming Language, 2nd Ed.",
//       B. Stroustroup, 1991 (1995).
//
//----------------------------------------------------------------------------

#include <stdio.h>
#include <iostream.h>

//------------------------------------------------
// main
//
// Description:
//    "Get the 'hello world' program (1.3.1) to
//    to run.
//------------------------------------------------
int main ()

{
         const unsigned short oneScan = (unsigned short) (1<<15);

   cout << "Hello, World!\n";

   printf("oneScan = %u (0x%.4x)\n", oneScan, oneScan);

   return 0;
}
