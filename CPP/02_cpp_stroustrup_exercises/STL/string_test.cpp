//----------------------------------------------------------------------------
// File : string_test.cpp
// Date : 06-Apr-00 : initial defintion
//
// Description:
//    This is a console application that uses the "string" class from the
//    C++ Library.
//
//    The "string" class is defined in C++ Standard Template Library
//    (STL):
//
//               typedef basic_string<char> string;
//
//    Thus, it is actually an instantiation of the template "basic_string"
//    whose data type is simply "char".  The template "basic_string" is also
//    from the STL.  Although its interface is rather ugly, it offers a
//    series of powerful methods (i.e. functions) to manipulate the given
//    data structure.  The component "string" is not a template, but it is
//    defined in the STL ... usually right after the declaration of the
//    "basic_string" template.
//
//    The "basic_string" template can be instantiated using any data structure
//    that does not require "construction" and/or "destruction".  Such items
//    are called "plain-old data structures (POD)".  Regular C structs fall
//    into this category whereas C++ classes do not (because they require a
//    constructor/destructor).
//
//    The basic power in using the "string" type is that you don't have to
//    worry about allocating and deallocating chars to build a string.  Also,
//    the assignment and re-assignment of strings to an object is very simple,
//    as this code demonstrates.
//----------------------------------------------------------------------------

#include <stdio.h>

//
// The following statement is different from
// the typical #include from ANSI C.  Most noticable
// is there is no ".h" in the name.  The statement
// means that you need a component from the "C++ Standard
// Library (aka : std)".  Note that the STL is a part of
// the C++ Standard Library.  In this case, the component
// "string" is needed.
//
// This is different from ANSI C.  A #include statement
// means "insert a copy of the specified file right here".
//
#include <string>


//-----------------------------------------------
// main
//
// Description:
//    main function.
//-----------------------------------------------
int main
       (int  argc,
        char **argv)

{
         //
         // Declare an object from the
         // class "string"
         //
         std::string theString;

   theString = "Hello World";

   printf("%s\n", theString.c_str () );

   //
   // Notice, no re-allocation, new, delete, etc
   //
   theString = "Another String that is much longer";

   printf("%s\n", theString.c_str () );

   theString = "Short";

   printf("%s\n", theString.c_str () );

   //
   // Demonstrate pointer semantics
   //
         std::string *ptrToString;

   ptrToString = new std::string();

   *ptrToString = "String pointed to by pointer";

   printf("%s\n", ptrToString->c_str () );

   *ptrToString = "Same pointer, but a different string that is much longer";

   printf("%s\n", ptrToString->c_str () );

   //
   // Demonstrate 'append' method
   //
   theString = "First Part";

   *ptrToString = " : Second Part";

   theString.append (*ptrToString);

   printf("%s\n", theString.c_str() );

   //
   // Demonstrate string parsing:
   //    Let's parse the integer values from a string
   //    whose format is:
   //
   //          ddd:mm:ss.ss
   //
   //    To do this, the methods "find" and "substr"
   //    will be used ...
   //
         int         theDegrees = -1;
         int         theMinutes = -1;
         float       theSeconds = -1.0f;
         int         startPosition = 0;
         int         endPosition;
         std::string sliceOfString;

   theString = "135:32:24.35";

   //
   // Extract degrees
   //
   endPosition = theString.find(":", startPosition);

   sliceOfString = theString.substr (startPosition, endPosition);

   sscanf(sliceOfString.c_str(), "%d", &theDegrees);

   //
   // Extract minutes
   //
   startPosition = endPosition + 1;

   endPosition = theString.find(":", startPosition);

   sliceOfString = theString.substr (startPosition, endPosition);

   sscanf(sliceOfString.c_str(), "%d", &theMinutes);

   //
   // Extract seconds
   //
   startPosition = endPosition + 1;

   endPosition = theString.length();

   sliceOfString = theString.substr (startPosition, endPosition);

   sscanf(sliceOfString.c_str(), "%f", &theSeconds);

   //
   // And the answer is ...
   //
   printf("Degrees = %d\n", theDegrees);
   printf("Minutes = %d\n", theMinutes);
   printf("Seconds = %.2f\n", theSeconds);

   //
   // But don't forget that the Standard I/O library
   // is powerful too.  You can reduce 14 lines of
   // code down to 1!
   //
   sscanf(theString.c_str(), "%d:%d:%f",
          &theDegrees,
          &theMinutes,
          &theSeconds);

   //
   // Did we get the same answer?
   //
   printf("Degrees = %d\n", theDegrees);
   printf("Minutes = %d\n", theMinutes);
   printf("Seconds = %.2f\n", theSeconds);

   return 0;
}
