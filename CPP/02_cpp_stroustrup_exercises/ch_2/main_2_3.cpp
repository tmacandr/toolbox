//-------------------------------------------------------------------------
// File : main_2_3.cpp
// Date : 04-Apr-00 : initial definition
//        26-Nov-00 : changed to use <stdio.h> instead of <iostream.h>
//
// Description:
//    Exercise 3 from Chapter 2 of:
//
//          "The C++ Programming Language, 2nd Ed.", B. Stroustroup,
//          Addison-Wesley Publishing Co., 1995.
//
//    Write declarations for the following:
//        a pointer to a character
//        an array of 10 integers
//        a reference to an array of 10 integers
//        a pointer to an array of character strings
//        a pointer to a pointer to a character
//        a constant integer
//        a pointer to a constant integer
//        a constant pointer to an integer
//    Initialize each one.
//-------------------------------------------------------------------------

#include <stdio.h>


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
         int       i;
         char      the_char = 'A';
         char      *ptr_to_char = &the_char;

         const int num_ints = 10;
         typedef int intArrayType[num_ints];

         intArrayType array_of_10_ints =
                            { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
         intArrayType &ref_to_int_array = array_of_10_ints;
         char      *ptr_to_string_array[] = { (char *) "string_1",
                                              (char *) "string_2",
                                              (char *) "string_3",
                                              (char *) "string_4",
                                              (char *) "string_5" };
         char      **ptr_to_char_ptr = &ptr_to_char;
         int const *ptr_to_const_int = &num_ints;
         const int *const_ptr_to_int = &num_ints;

   printf("pointer to a character : %c (address of pointer = %x)\n",
          *ptr_to_char,
          ptr_to_char);

   printf("array of ten integers:\n");

   for (i = 0; i < num_ints; i++)
      {
       printf("%d  ", array_of_10_ints[i]);
      }

   printf("\n");

   printf("reference to array of ten integers:\n");

   for (i = 0; i < num_ints; i++)
      {
       printf("%d  ", ref_to_int_array[i]);
      }

   printf("\n");

   printf("pointer to an array of strings:\n");

   for (i = 0; i < 5; i++)
      {
       printf("String %d : %s\n", i, ptr_to_string_array[i]);
      }

   printf("pointer to a character pointer :\n");
   printf("   ---> the char     : %c\n", *ptr_to_char_ptr[0]);
   printf("   ---> addr of char : %x\n", *ptr_to_char_ptr);
   printf("   ---> addr of ptr  : %x\n", ptr_to_char_ptr);

   printf("pointer to constant integer:\n");
   printf("   ---> the integer     : %d\n", *ptr_to_const_int);
   printf("   ---> addr of integer : %x\n", ptr_to_const_int);


   printf("constant pointer to integer:\n");
   printf("   ---> the integer     : %d\n", *const_ptr_to_int);
   printf("   ---> addr of integer : %x\n", const_ptr_to_int);

   return 0;
}

