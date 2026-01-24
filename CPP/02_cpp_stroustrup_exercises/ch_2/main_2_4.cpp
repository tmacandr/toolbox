//-------------------------------------------------------------------------
// File : main_2_4.cpp
// Date : 11-Apr-00 : initial definition
//        26-Nov-00 : use <stdio.h> instead of <iostream.h>.  SUN allowed?
//        23-Jan-26 : Updates per GNU g++
//
// Description:
//    Exercise 4 from Chapter 2 of:
//
//          "The C++ Programming Language, 2nd Ed.", B. Stroustroup,
//          Addison-Wesley Publishing Co., 1995.
//
//    Write a program that prints the sizes of the fundemental and
//    pointer types.  Use the sizeof operator.
//-------------------------------------------------------------------------

#include <stdio.h>


//------------------------------------------------------------
// main
//
// Description:
//    main function.
//------------------------------------------------------------
int main
        (int argc,
         char **argv)

{
   printf("Sizes of fundamental types (bytes):\n");
   printf("-----------------------------------\n");
   printf("---> 'char'          = %ld\n", sizeof(char) );
   printf("---> 'unsigned char' = %ld\n", sizeof(unsigned char) );
   printf("---> 'signed char'   = %ld\n", sizeof(signed char) );

   printf("---> 'bool'          = %ld\n", sizeof(bool) );

   //-------------------//

   printf("---> 'int'           = %ld\n", sizeof(int) );
   printf("---> 'short int'     = %ld\n", sizeof(short int) );
   printf("---> 'long int'      = %ld\n", sizeof(long int) );
   printf("---> 'unsigned int'  = %ld\n", sizeof(unsigned int) );
   printf("---> 'signed int'    = %ld\n", sizeof(signed int) );
   printf("---> 'unsigned short int' = %ld\n", sizeof(unsigned short int) );
   printf("---> 'signed short int'   = %ld\n", sizeof(signed short int) );
   printf("---> 'unsigned long int'  = %ld\n", sizeof(unsigned long int) );
   printf("---> 'signed long int'    = %ld\n", sizeof(signed long int) );

   //-------------------//

   printf("---> 'float'         = %ld\n", sizeof(float));
   printf("---> 'double'        = %ld\n", sizeof(double));
   printf("---> 'long double'   = %ld\n", sizeof(long double));

   //-------------------//

   printf("---> 'char *'        = %ld\n", sizeof(char *) );
   printf("---> 'int *'         = %ld\n", sizeof(int *) );
   printf("---> 'float *'       = %ld\n", sizeof(float *) );
   printf("---> 'double *'      = %ld\n", sizeof(double *) );
   printf("---> 'bool *'        = %ld\n", sizeof(bool *) );

   return 0;
}

