//-------------------------------------------------------------------------
// File : main_2_4.cpp
// Date : 11-Apr-00 : initial definition
//        26-Nov-00 : use <stdio.h> instead of <iostream.h>.  SUN allowed?
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
   printf("---> 'char'          = %d\n", sizeof(char) );
   printf("---> 'unsigned char' = %d\n", sizeof(unsigned char) );
   printf("---> 'signed char'   = %d\n", sizeof(signed char) );

   printf("---> 'bool'          = %d\n", sizeof(bool) );

   //-------------------//

   printf("---> 'int'           = %d\n", sizeof(int) );
   printf("---> 'short int'     = %d\n", sizeof(short int) );
   printf("---> 'long int'      = %d\n", sizeof(long int) );
   printf("---> 'unsigned int'  = %d\n", sizeof(unsigned int) );
   printf("---> 'signed int'    = %d\n", sizeof(signed int) );
   printf("---> 'unsigned short int' = %d\n", sizeof(unsigned short int) );
   printf("---> 'signed short int'   = %d\n", sizeof(signed short int) );
   printf("---> 'unsigned long int'  = %d\n", sizeof(unsigned long int) );
   printf("---> 'signed long int'    = %d\n", sizeof(signed long int) );

   //-------------------//

   printf("---> 'float'         = %d\n", sizeof(float));
   printf("---> 'double'        = %d\n", sizeof(double));
   printf("---> 'long double'   = %d\n", sizeof(long double));

   //-------------------//

   printf("---> 'char *'        = %d\n", sizeof(char *) );
   printf("---> 'int *'         = %d\n", sizeof(int *) );
   printf("---> 'float *'       = %d\n", sizeof(float *) );
   printf("---> 'double *'      = %d\n", sizeof(double *) );
   printf("---> 'bool *'        = %d\n", sizeof(bool *) );

   return 0;
}

