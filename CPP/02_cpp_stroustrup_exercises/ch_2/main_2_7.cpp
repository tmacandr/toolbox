//-------------------------------------------------------------------------
// File : main_2_7.cpp
// Date : 24-Apr-00 : initial definition
//        23-Jan-26 : Update to GNU g++
//
// Description:
//    Exercise 7 from Chapter 2 of:
//
//          "The C++ Programming Language, 2nd Ed.", B. Stroustroup,
//          Addison-Wesley Publishing Co., 1995.
//
//    Write a function that prints the exponent and mantissa of a double
//    argument. 
//-------------------------------------------------------------------------

#include <iostream>
#include <math.h>


static void printExpAndMantissa
               (double someVar);

static void doesThisWork
               (double theDouble);


//------------------------------------------------------------
// main
//
// Description:
//    main function.
//------------------------------------------------------------
int main
        (int  argc,
         char **argv)

{
   printExpAndMantissa(1.1);

   printExpAndMantissa(33.2);

   doesThisWork(3.14159);

   return 0;
}


//------------------------------------------------------------
// printExpAndMantissa 
//
// Description:
//------------------------------------------------------------
static void printExpAndMantissa
               (double someVar)

{
            unsigned int *dblPtr;
            double       theMantissa = 0.0;
            double       theExp = 0.0;
            int          i;
            unsigned int temp;

   dblPtr = (unsigned int *) &someVar;

   printf("Value = %lf :  Ints = %x-%x\n",
          someVar,
          dblPtr[1],
          dblPtr[0]);

   for (i = 0; i < 32; i++)
   {
       temp = dblPtr[0] & 0x00000001;

       printf("%d ", temp);

       theMantissa = theMantissa + temp * pow(2, i); 

       dblPtr[0] = dblPtr[0] >> 1;
   }

   printf("\n");

   for (i = i; i < 52; i++)
   {
       temp = dblPtr[1] & 0x00000001;

       printf("%d ", temp);

       dblPtr[1] = dblPtr[1] >> 1;
   }

   printf("\n");
 
   printf("---> Mantissa = %lf\n", theMantissa);

   for (i = i; i < 62; i++)
   {
       temp = dblPtr[1] & 0x00000001;

       printf("%d ", temp);

       dblPtr[1] = dblPtr[1] >> 1;
   }

   printf("\n");

   printf("---> Exponent = %lf\n", theExp);
}


//-----------------------------------------------------------
// doesThisWork
//
// Description:
//    Utility that prints the exponent and the mantissa of
//    the specified "double" argument.  The format of a double
//    is 8 bytes (64-bits):
//
// Sign--                 -- 51                          -- 0
//      |                 |                              |
//      V                 V                              V
//      __________________________________________________
//     | | 11 bits - exp |    52 bits - mantissa          |
//     |_|_______________|________________________________|
//        ^            ^
//        |            |
//       62           52
//-----------------------------------------------------------
static void doesThisWork
               (double theDouble)

{
         char          charBuffer[256];
         unsigned int  index;
         //-----------------------//
         unsigned char *ptrToDouble = (unsigned char*) &theDouble;
         unsigned char doubleAsChars[sizeof(double)];

   sprintf(charBuffer, "%e", theDouble);

   printf("The double value  = %s\n", charBuffer);

   printf("     The Mantissa = ");

   index = 0;

   while (charBuffer[index] != 'e')
      printf("%c", charBuffer[index++]);

   printf("\n");

   printf("     The Exponent = ");

   index++;

   while (charBuffer[index] != '\0')
      printf("%c", charBuffer[index++]);

   printf("\n");

   //-------------------
   // Screwing around ...
   //-------------------
   printf("Double-as-Chars:\n");

   for (index = 0; index < sizeof(double); index++)
   {
       doubleAsChars[index] = ptrToDouble[index];

       printf("%.2x ", doubleAsChars[index]);
   }

   printf("\n");

   unsigned long long int *td = (unsigned long long int *) &theDouble;

   printf("Double         : %.16llX\n", *td);
}

