//----------------------------------------------------------------------------
// File : main_3_5.cpp
// Date : 03-Dec-00 : initial definition
//        09-Dec-00 : implement divide-by-zero
//        10-Dec-00 : implement overflow
//        23-Jan-26 : Update for GNU gcc
//
// Description:
//    Exercise 3.5 from:
//
//       "The C++ Programming Language, 2nd Ed.",
//       B. Stroustroup, 1991 (1995).
//
//    What happens if you divide by zero on your system?  What happens in
//    case of overflow and underflow?
//----------------------------------------------------------------------------

#include <iostream>
#include <limits.h>
#include <float.h>
#include <math.h>


static void doDivideByZero ();

static void doOverflow ();

static void doUnderflow ();



//------------------------------------------------
// main
//
// Description:
//------------------------------------------------
int main
      (int  argc,
       char **argv)

{
         int whichTest = 10;

   whichTest -= 5;

   std::cout << whichTest << "\n";

   whichTest = 10;

   whichTest =- 5;

   std::cout << whichTest << "\n";
   
   while (true)
      {
       std::cout << "Which error do you want to induce\n";
       std::cout << "   1) Divide by zero\n";
       std::cout << "   2) Overflow\n";
       std::cout << "   3) Underflow\n";

       std::cin >> whichTest;

       if (whichTest == 1)

          doDivideByZero ();

       else if (whichTest == 2)

          doOverflow ();

       else if (whichTest == 3)

          doUnderflow ();

       else

          std::cout << "---> Unknown selection - try again\n";
      }

   return 0;
}


//------------------------------------------------
// doDivideByZero
//
// Description:
//    This causes the program to fail.  For the
//    "Windows" operating system, if the program
//    was linked in debug mode, then a dialog is
//    presented that allows the operator to either
//    simply terminate the application or to start
//    the debugger (if it is installed).  In
//    either case, the program is terminated
//    "ungracefully".
//
//    For this function, I'm actually surprised
//    that the compiler did not detect that a
//    divide by zero error will occur ... since
//    the variable 'd' is simply set to zero.  If
//    the expression is "b / 0.0", then a warning is
//    posted.  Also, if 'd' is declared as a const
//    that is equal to zero, then a warning is
//    also issued by the compiler.
//------------------------------------------------
static void doDivideByZero ()

{
      int a,
          b = 20;
      int d = 0;

   a = b / d;

   std::cout << "---> doDivideByZero: " << a << std::endl;
}


//------------------------------------------------
// doOverflow
//
// Description:
//    This function exercises "overflow" behavior.
//    The description applies to the "Windows 9X"
//    operating system.
//
//    For the case of "integer", a variable is
//    assigned the system MAX value and then it
//    is incremented by MAX.  The behavior is
//    not fatal, but an invalid value is
//    generated.  The result is actually one
//    less than MAX ... as if a subtract 1
//    operation was performed.
//
//    For the case of "float" and "double", a
//    variable is assigned the system MAX and then
//    that value is incremented by MAX.  The
//    behavior is not fatal but invalid values
//    are generated.  The value is indicated by
//
//                  1.#inf
//
//    which is probably the representation for
//    "NaN".
//
//    Make use of utility "isnan" from <float.h>
//    to check ... but it's not giving the answer
//    I want.  It says the values are valid even
//    though "cout" can't handle them.
//------------------------------------------------
static void doOverflow ()

{
         unsigned long the_int    = ULONG_MAX; // from <limits.h>
         float         the_float  = FLT_MAX;   // from <float.h>
         double        the_double = DBL_MAX;   // from <float.h>

   //
   // For integer
   //
   std::cout << "int before : " << the_int << "\n";

   the_int += ULONG_MAX;

   std::cout << "int after  : " << the_int << "\n";

   //
   // For "float"
   //
   std::cout << "float before : " << the_float << "\n";

   the_float += FLT_MAX;

   std::cout << "float after  : " << the_float << "\n";

   if ( isnan ((double) the_float) )
      std::cout << "float Is Not-a-Number (NaN)\n";
   else
      std::cout << "float Is a valid number\n";

   //
   // For "double"
   //
   std::cout << "double before : " << the_double << "\n";

   the_double += LDBL_MAX;

   std::cout << "double after  : " << the_double << "\n";

   if ( isnan (the_double) )
      std::cout << "double Is Not-a-Number (NaN)\n";
   else
      std::cout << "double Is a valid number\n";
}


//------------------------------------------------
// doUnderflow
//
// Description:
//    This function induces "underflow" ... at
//    least for integer.  The most negative
//    integer value is defined ... and then the
//    MAX value is subtracted from it.  The
//    result is not fatal but an erroneous value.
//
//    For "float" and "double" I'm not sure an
//    underflow can be generated.  The smallest
//    values that the compiler will represent
//    are FLT_EPSILON for "float" and DBL_EPSILON
//    for "double".  Therefore, any attempt to
//    write or calculate a smaller value will
//    simply result in rounding.  For this test
//    the values are rounded to zero.  Therefore
//    the results are not only not fatal, but
//    a valid value is generated, although it may
//    not be to the needed accuracy.  If that's
//    the case, deal with it or ... get a bigger
//    computer!
//------------------------------------------------
static void doUnderflow ()

{
         long   the_int    = - LONG_MAX;    // from <limits.h>
         float  the_float  = FLT_EPSILON;   // from <float.h>
         double the_double = DBL_EPSILON;   // from <float.h>

   //
   // For integer
   //
   std::cout << "int before : " << the_int << "\n";

   the_int -= LONG_MAX;

   std::cout << "int after  : " << the_int << "\n";

   //
   // For "float", divide by 2.0 to get a smaller number
   //
   std::cout << "float before : " << the_float << "\n";

   the_float /= FLT_MAX;

   std::cout << "float after  : " << the_float << "\n";

   if ( isnan ((double) the_float) )
      std::cout << "float Is Not-a-Number (NaN)\n";
   else
      std::cout << "float Is a valid number\n";

   //
   // For "double" ... do the same as "float"
   //
   std::cout << "double before : " << the_double << "\n";

   the_double /= DBL_MAX;

   std::cout << "double after  : " << the_double << "\n";

   if ( isnan (the_double) )
      std::cout << "double Is Not-a-Number (NaN)\n";
   else
      std::cout << "double Is a valid number\n";
}
