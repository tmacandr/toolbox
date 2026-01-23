//------------------------------------------------------------------------------
// Date : 14-Sep-99
// File : exercise_10.cpp
//
// Description:
//    Chapter  : 2
//    Exercise : 10
//    From     : "The C++ Programming Language - 2nd Ed",
//               Bjarne Stroustrup, 1991 (reprint : 1995).
//    Comments : Write a function  that swaps (exchanges the values of) two
//               integers.  Use 'int *' as the argument type.  Write another
//               swap unction using 'int &' as the argument type.
//------------------------------------------------------------------------------

#include <stdio.h>


static void firstSwap
               (int *int_1,
                int *int_2);

static void secondSwap
               (int &int_1,
                int &int_2);


int main ()

{
         int firstInt = 1;
         int secondInt = 2;

   printf("________________________________________\n");
   printf("Begin : Exercise 2.10\n");

   //
   // First Swap ...
   //
   printf("Before swap 1 :\n");
   printf("   ---> first int  = %d\n", firstInt);
   printf("   ---> second int = %d\n", secondInt);

   firstSwap
      (&firstInt,
       &secondInt);

   printf("After swap 1 :\n");
   printf("   ---> first int  = %d\n", firstInt);
   printf("   ---> second int = %d\n", secondInt);

   //
   // Seond Swap ...
   //
   printf("Now do swap 2 :\n");

   secondSwap
      (firstInt,
       secondInt);

   printf("After swap 2 :\n");
   printf("   ---> first int  = %d\n", firstInt);
   printf("   ---> second int = %d\n", secondInt);

   printf("End   : Exercise 2.10\n");
   printf("________________________________________\n");

   return 0;
}


//-----------------------------------------------------------
// firstSwap
//
// Description:
//-----------------------------------------------------------
static void firstSwap
               (int *int_1,
                int *int_2)

{
      int temp;

   temp = *int_2;

   *int_2 = *int_1;

   *int_1 = temp;
}


//-----------------------------------------------------------
// secondSwap
//
// Description:
//-----------------------------------------------------------
static void secondSwap
               (int &int_1,
                int &int_2)

{
      int temp;

   temp = int_2;

   int_2 = int_1;

   int_1 = temp;

   //
   // This works too ...
   //
   // firstSwap
   //   (&int_1,
   //    &int_2);
}
