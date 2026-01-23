//******************************************************
// File : main.cpp
//
// Description:
//    Run and exercise 'someClass'.
//******************************************************

#include <iostream>
#include "someClass.h"

/***********************************************
* FUNCTION: main
*
* DESCRIPTION:
*    Main entry point of program.
************************************************/
int main (int argc, char* argv[])

{
   int   i = 0;
   float f = 0.0f;

   std::cout << "_________________________"   << std::endl;
   std::cout << "---> Begin : Test someClass" << std::endl;

   someClass sc(i, f);

   sc.print();

   sc.setAttribute_1(1234);

   sc.setAttribute_2(3.14159);

   sc.print();

   std::cout << "---> End : Test someClass" << std::endl;
   std::cout << "_________________________" << std::endl;

   return 0;
}

/* EOF */

