//-------------------------------------------------------------------------
// File : main_2_6.cpp
// Date : 17-Apr-00
//        23-Jan-26 : Update to GNU g++
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

#include <iostream>


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
            int                i;

   printf("__________________________\n");

   printf("Address of 'Null_Ptr'  = %p (hex)\n", &Null_Ptr);
   printf("Contents of 'Null_Ptr' = %.8X (hex)\n", *Null_Ptr);

   printf("Bit pattern of 'NULL'  = ");

   for (i = 0; i < 32; i++)
   {
       printf("%#.8X\n", (unsigned int) *Null_Ptr);
   }

   return 0;
}

