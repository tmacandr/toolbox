//-------------------------------------------------------------------------
// File : main_2_6.cpp
// Date : 17-Apr-00
//
// Description:
//    Exercise 6 from Chapter 2 of:
//
//          "The C++ Programming Language, 2nd Ed.", B. Stroustroup,
//          Addison-Wesley Publishing Co., 1995.
//
//    Print out the bit pattern used to represent the pointer 0 on
//    your system.  Hint: see section 2.6.2. 
//-------------------------------------------------------------------------

#include <iostream.h>


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
            char               *Null_Ptr = NULL;
            const unsigned int mask = 0x1;
            int                i;

   printf("__________________________\n");

   printf("Mask                   = %.4x (hex)\n", mask);
   printf("Address of 'Null_Ptr'  = %x (hex)\n", &Null_Ptr);
   printf("Contents of 'Null_Ptr' = %.4x (hex)\n", Null_Ptr);

   printf("Bit pattern of 'NULL'  = ");

   for (i = 0; i < 32; i++)
      {
       printf("%d", (unsigned int) Null_Ptr & mask);

       (int) Null_Ptr >> 1;
      }

   printf("\n");

   return 0;
}

