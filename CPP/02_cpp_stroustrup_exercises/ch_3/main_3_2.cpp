//----------------------------------------------------------------------------
// File : main_3_2.cpp
// Date : 30-Jul-00 : initial definition
//
// Description:
//    Exercise 3.2 from:
//
//       "The C++ Programming Language, 2nd Ed.",
//       B. Stroustroup, 1991 (1995).
//
//----------------------------------------------------------------------------

#include <iostream>


static int f(int x, int y)

{
   return x + y;
}


//------------------------------------------------
// main
//
// Description:
//    Fully parenthesize the following expressions:
//
//       a = b + c * d << 2 & 8
//       a & 077 != 3
//       a == b || a == c && c < 5
//       c = x != 0
//       0 <= i < 7
//       f(1,2)+3
//       a = -1 + + b -- - 5
//       a = b == c ++
//       a = b = c = 0
//       a[4][2] *= * b ? c : * d * 2
//       a-b,c=d
//------------------------------------------------
int main
      (int  argc,
       char **argv)

{
         int  a;
         int  b = 2, c = 3, d = 4, x = 5, i = 6;

   a = ( (b + c * d) << (2 & 8) );

   std::cout << "a = " << a << "\n";

   void ( (a & 077) != 3);

   std::cout << "a = " << a << "\n";

   // not sure if intent was default precedence or && priority.
   //
   // g++ compiler says (i.e. "warning") it recommends parens
   // around && op.  I guess just for emphasis
   void ( (a == b) || ( (a == c) && (c < 5)) );

   c = (int) (x != 0);

   void ( (int) (0 <= i) < 7);

   void (f(1,2)+3);

   return 0;
}
