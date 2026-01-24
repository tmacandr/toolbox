//------------------------------------------------------------------------------
// Date : 13-Sep-99
//        23-Jan-26 : Update to GNU g++
// File : exercise_8.cpp
//
// Description:
//    Chapter  : 2
//    Exercise : 8
//    From     : "The C++ Programming Language - 2nd Ed",
//               Bjarne Stroustrup, 1991 (reprint : 1995).
//    Comments : What, on your system, are the largest and the smallest values
//               of the following types:
//                       char
//                       short
//                       int
//                       long
//                       float
//                       double
//                       long double
//                       unsigned
//                       char *
//                       int *
//                       void *
//               Are there further restriction on the values?  For example, may
//               an int * have an odd value?  what is the alignment of objects
//               of those types?  For example, may an int have an odd address?
//------------------------------------------------------------------------------

#include <stdio.h>
#include <ctype.h>

//-----------------------
// The answers are all
// in these headers ...
//-----------------------
#include <float.h>
#include <limits.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>


// Need to look this up.  Disappeared
#define FLT_GUARD   (0.0f)


static void printLargestAndSmallestChar ();

static void printLargestAndSmallestShort ();

static void printLargestAndSmallestInt ();

static void printLargestAndSmallestLong ();

static void printLargestAndSmallestUnsigned ();

static void printLargestAndSmallestFloat ();

static void printLargestAndSmallestDouble ();

static void printLargestAndSmallestLongDouble ();

static void otherQuestions ();


int main ()

{
   printf("________________________________________\n");
   printf("Begin : Exercise 2.8\n");

   printLargestAndSmallestChar ();

   printLargestAndSmallestShort ();

   printLargestAndSmallestInt ();

   printLargestAndSmallestLong ();

   printLargestAndSmallestUnsigned ();

   printLargestAndSmallestFloat ();

   printLargestAndSmallestDouble ();

   printLargestAndSmallestLongDouble ();

   otherQuestions ();

   printf("End   : Exercise 2.8\n");
   printf("________________________________________\n");

   return 0;
}


//---------------------------------------------
// printLargestAndSmallestChar
//
// Description:
//    A "char" is one byte.  It can range from
//    0 .. 256 (unsigned) or -128 .. 127 (signed
//    two's complement).
//---------------------------------------------
static void printLargestAndSmallestChar ()

{
         // these will generate truncation
         // warnings from VC++ ... very good.
         // char minWrong = -129;
         // char maxWrong = 128;
         char minChar = SCHAR_MIN;
         char maxChar = SCHAR_MAX;

   printf("_________________________\n");
   printf("Min char = %.2x\n", minChar);
   printf("Max char = %.2x\n", maxChar);
}


//---------------------------------------------
// printLargestAndSmallestShort
//
// Description:
//    A "short" is two bytes.  It can range:
//              0 .. 65535
//    unsigned, or
//         -32768 .. 32767
//    for signed two's complement.
//---------------------------------------------
static void printLargestAndSmallestShort ()

{
         // these will generate truncation
         // warnings from VC++ ... very good.
         // short minShort = -32769;
         // short maxShort = 32768;
         short minShort = SHRT_MIN;
         short maxShort = SHRT_MAX;

   printf("_________________________\n");
   printf("Min short = %d (%.2x)\n", (int) minShort, minShort);
   printf("Max short = %d (%.2x)\n", (int) maxShort, maxShort);
}


//---------------------------------------------
// printLargestAndSmallestInt
//
// Description:
//    An "int" is 4 bytes.  It can range:
//              0 .. 4_294_967_297
//    unsigned.  Or using signed two's
//    complement:
//       -2_147_483_648 .. 2_147_483_647
//    Or for the most-significant bit is a
//    sign bit, the range is:
//       -2_147_483_647 .. 2_147_483_647
//---------------------------------------------
static void printLargestAndSmallestInt ()

{
         // VC++ compiler generates warning
         // that type was converted to unsigned
         // and the - operator ignored ... bad.
         //
         // int wrongMin = -2147483648;

         // ... this is simply converted to
         // an 'unsigned int' ... very bad
         //
         // int wrongMax = 2147483648;

         int x = 0x8fffffff;

         int min = INT_MIN;
         int max = INT_MAX;

   printf("_________________________\n");
   printf("Min int = %d (%.2x)\n", min, min);
   printf("Max int = %d (%.2x)\n", max, max);
   printf("X       = %d (%.2x)\n", x, x);
}


//---------------------------------------------
// printLargestAndSmallestLong
//
// Description:
//    To tell the truth, I don't really know
//    what the difference is between a "long int"
//    and an "unsigned int" ... or even an
//    "unsigned long int".
//
//    This is what I know:
//       1) VC++ implements "long int" as
//          4 bytes.
//       2) a "long int" can be signed.
//       3) the valid range of a "long int"
//          is no different than "int".
//          (-2_147_483_647 .. 2_147_483_647)
//
//    This is what I assume:
//       1) Some implementations may
//          actually implement a "long int"
//          as twice the size of an "int"
//          (e.g. 8 bytes).  VC++ does
//          not do this.  See "exercise 4".
//---------------------------------------------
static void printLargestAndSmallestLong ()

{
         // VC++ will generate a warning that
         // the "-" operator is ignored because
         // it is applied to an "unsigned" type.
         //
         // long badMin = -2147483648;

         // VC++ does NOTHING here.  The number
         // is too big to fit into "long" so
         // it is truncated ... and actually
         // becomes the negative number
         //
         //     -2147483648
         //
         // which from above is an invalid
         // "long int".  Very bad!
         // 
         long badMax = 2147483648;

         long min = LONG_MIN;
         long max = LONG_MAX;

   printf("_________________________\n");
   printf("Min long int = %ld (%.2lx)\n", min, min);
   printf("Max long int = %ld (%.2lx)\n", max, max);
   printf("Bad long int = %ld (%.2lx)\n", badMax, badMax);
}


//---------------------------------------------
// printLargestAndSmallestUnsigned
//
// Description:
//    An "unsigned int" is 4 bytes.  It can range:
//            0 .. 4_294_967_297
//---------------------------------------------
static void printLargestAndSmallestUnsigned ()

{
         unsigned min = 0;
         unsigned max = UINT_MAX;
         unsigned what = -1; // how can this be negative

   printf("_________________________\n");
   printf("Size of max-unsigned-int = %ld bytes\n",
          sizeof(UINT_MAX));
   printf("Min unsigned int = %u (%.2x)\n", min, min);
   printf("Max unsigned int = %u (%.2x)\n", max, max);
   printf("Bizarre uint     = %u (%.2x)\n", what, what);
}


//---------------------------------------------
// printLargestAndSmallestFloat
//
// Description:
//    After struggling with the above items
//    it was at this point that I discovered:
//
//           <float.h>
//           <limit.h>
//           <stdarg.h>
//
//    Things should be more staight-forward
//    from now on ...
//---------------------------------------------
static void printLargestAndSmallestFloat ()

{
         float min          = -FLT_MAX;
         float max          = FLT_MAX;
         float negEpsilon   = -FLT_MIN;
         float posEpsilon   = FLT_MIN;
         float absoluteZero = FLT_GUARD;

   unsigned long long int *minp = (unsigned long long int *) &min;
   unsigned long long int *maxp = (unsigned long long int *) &max;
   unsigned long long int *nep  = (unsigned long long int *) &negEpsilon;
   unsigned long long int *pep  = (unsigned long long int *) &posEpsilon;
   unsigned long long int *azp  = (unsigned long long int *) &absoluteZero;

   printf("_________________________\n");
   printf("Min float = %e (%llx)\n", min, *minp);
   printf("Max float = %e (%llx)\n", max, *maxp);
   printf("Negative number closest to zero : %e (%llx)\n",
          negEpsilon, *nep);
   printf("Positive number closest to zero : %e (%llx)\n",
          posEpsilon, *pep);
   printf("Absolute Zero = %e (%llx)\n",
          absoluteZero, *azp);
}


//---------------------------------------------
// printLargestAndSmallestDouble
//
// Description:
//---------------------------------------------
static void printLargestAndSmallestDouble ()

{
         double min          = -DBL_MAX;
         double max          = DBL_MAX;
         double negEpsilon   = -DBL_MIN;
         double posEpsilon   = DBL_MIN;
         double absoluteZero = (double) FLT_GUARD;

   unsigned long long int *minp = (unsigned long long int *) &min;
   unsigned long long int *maxp = (unsigned long long int *) &max;
   unsigned long long int *nep  = (unsigned long long int *) &negEpsilon;
   unsigned long long int *pep  = (unsigned long long int *) &posEpsilon;
   unsigned long long int *azp  = (unsigned long long int *) &absoluteZero;

   printf("_________________________\n");
   printf("Size of double : %ld bytes\n",
          sizeof(DBL_MAX));
   printf("Min double = %le (%llx)\n", min, *minp);
   printf("Max double = %le (%llx)\n", max, *maxp);
   printf("Negative double number closest to zero : %le (%llx)\n",
          negEpsilon, *nep);
   printf("Positive double number closest to zero : %le (%llx)\n",
          posEpsilon, *pep);
   printf("Absolute Zero = %le (%.llx)\n",
          absoluteZero, *azp);
}


//---------------------------------------------
// printLargestAndSmallestLongDouble
//
// Description:
//---------------------------------------------
static void printLargestAndSmallestLongDouble ()

{
         long double min          = -LDBL_MAX;
         long double max          = LDBL_MAX;
         long double negEpsilon   = -LDBL_MIN;
         long double posEpsilon   = LDBL_MIN;
         long double absoluteZero = (long double) FLT_GUARD;

   unsigned long long int *minp = (unsigned long long int *) &min;
   unsigned long long int *maxp = (unsigned long long int *) &max;
   unsigned long long int *nep  = (unsigned long long int *) &negEpsilon;
   unsigned long long int *pep  = (unsigned long long int *) &posEpsilon;
   unsigned long long int *azp  = (unsigned long long int *) &absoluteZero;


   printf("_________________________\n");
   printf("Size of long double : %ld bytes\n",
          sizeof(LDBL_MAX));
   printf("Min long double = %Le (%.llx)\n", min, *minp);
   printf("Max long double = %Le (%.llx)\n", max, *maxp);
   printf("Negative long double number closest to zero : %Le (%llX)\n",
          negEpsilon, *nep);
   printf("Positive long double number closest to zero : %Le (%llX)\n",
          posEpsilon, *pep);
   printf("Absolute Zero = %Le (%llx)\n",
          absoluteZero, *azp);
}


//---------------------------------------------
// otherQuestions
//
// Description:
//    This routine answers the following
//    questions:
//
//        1) may an int * have an odd value?
//        2) what is the alignment of objects
//           of those types (char, int, float, etc)?
//        3) For example, may an int have an
//           odd address?
//
//    This routine shows that the answers are:
//        1) yes
//        2) byte-alignment (uchar, int, float, double)
//        3) yes
//---------------------------------------------
static void otherQuestions ()

{
         const int     numBytes = 128;
         unsigned char byteBuffer[numBytes];
         int           i;
         //-----------------
         unsigned char *ucharPtr;
         int           *intPtr;
         float         *floatPtr;
         double        *doublePtr;

   printf("_________________________\n");

   for (i = 0; i < numBytes; i++)
      byteBuffer[i] = i;

   printf("Address of byte buffer : %p\n", byteBuffer);

   printf("Unsigned Char:\n");
   printf("--------------\n");

   ucharPtr = &byteBuffer[1];  // an odd address

   printf("   Address of 'ucharPtr'            : %p\n",
          &ucharPtr);
   printf("   Address pointed to by 'ucharPtr' : %p\n",
          ucharPtr);
   printf("   Contents of that address         : %x\n",
          *ucharPtr);

   printf("Integer:\n");
   printf("--------\n");

   intPtr = (int *) &byteBuffer[2];  // an odd address

   *intPtr = 123456;

   printf("   Address of 'intPtr'            : %p\n",
          &intPtr);
   printf("   Address pointed to by 'intPtr' : %p\n",
          intPtr);
   printf("   Contents of that address       : %d (%x)\n",
          *intPtr, *intPtr);

   printf("Float:\n");
   printf("--------\n");

   floatPtr = (float *) &byteBuffer[6];  // an odd address

   *floatPtr = 123.456f;  // use 'f' to force it to be regular 'float'

   printf("   Address of 'floatPtr'            : %p\n",
          &floatPtr);
   printf("   Address pointed to by 'floatPtr' : %p\n",
          floatPtr);

   unsigned long long int *fp = (unsigned long long int *) floatPtr;
   printf("   Contents of that address         : %f (%llx)\n",
          *floatPtr, *fp);

   printf("Double:\n");
   printf("--------\n");

   doublePtr = (double *) &byteBuffer[10];  // an odd address

   *doublePtr = 123.456;  // is a 'double' by default

   printf("   Address of 'doublePtr'            : %p\n",
          &doublePtr);
   printf("   Address pointed to by 'doublePtr' : %p\n",
          doublePtr);

   fp = (unsigned long long int *) doublePtr;
   printf("   Contents of that address          : %lf (%llX)\n",
          *doublePtr, *fp);
}
