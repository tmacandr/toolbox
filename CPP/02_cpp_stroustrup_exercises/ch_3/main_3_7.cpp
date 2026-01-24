//----------------------------------------------------------------------------
// File : main_3_5.cpp
// Date : 03-Dec-00 : initial definition
//        23-Jan-26 : Tried some more implementation
//
// Description:
//    Exercise 3.5 from:
//
//       "The C++ Programming Language, 2nd Ed.",
//       B. Stroustroup, 1991 (1995).
//
//    Write functions "strlen" that returns the length of a string, "strcpy"
//    that copies a string into another, and "strcmp" that compares two
//    strings.  Consider what the argument types and return types ought to
//    be, then compare with the standard versions as declared in <string.h>
//    and specified in your manual.
//----------------------------------------------------------------------------

#include <iostream>  // if <iostream.h> is used, then don't need "std::"
#include <string.h>


static unsigned int my_strlen
                       (const char *str);

static char *my_strcpy
                (char       *to_str,
                 const char *from_str);

static int my_strcmp
              (const char *str_1,
               const char *str_2);


//------------------------------------------------
// main
//
// Description:
//------------------------------------------------
int main
      (int  argc,
       char **argv)

{
   std::string from = "the quick brown fox jumps over the lazy dog";
   std::string to   = "The Quick Brown Fox Jumps Over The Lazy Dog";

   char       *str_1 = (char *) from.c_str();
   const char *str_2 = to.c_str();
   int   num;

   num = my_strlen (str_1);

   std::cout << "str_1: " << str_1 << std::endl;
   std::cout << "str_2: " << str_2 << std::endl;
   std::cout << "Num chars in str_1 = " << num << "\n";

   int r = my_strcmp(str_1, str_2);

   std::cout << "'str_1' is " << (r > 0 ? "greater" : "less")
             << " than 'str_2'" << std::endl;

   char *a = my_strcpy(str_1, str_2);

   std::cout << "Copy: " << a << std::endl;

   return 0;
}


//------------------------------------------------
// my_strlen
//
// Description:
//    This function calculates the length of the
//    specified string ... except the null char-
//    acter.  The number of characters is returned.
//
//    The ANSI signature is:
//
//       size_t strlen( const char *string );
//
//    where "size_t" is "unsigned int".
//------------------------------------------------
static unsigned int my_strlen
                       (const char *str)

{
         unsigned count = 0;

   while (str[count++]);

   return count;
}


//------------------------------------------------
// my_strcpy
//
// Description:
//    This function copies the characters of the
//    "from_str" to the "to_str".  A pointer to
//    the destination string is returned.
//
//    The ANSI signature is:
//
//       char *strcpy
//                (char       *strDestination,
//                 const char *strSource);
//
//    and the behavior is defined to be:
//
//       "The strcpy function copies strSource,
//       including the terminating null character,
//       to the location specified by
//       strDestination. No overflow checking is
//       performed when strings are copied or
//       appended. The behavior of strcpy is
//       undefined if the source and destination
//       strings overlap."
//------------------------------------------------
static char *my_strcpy
                (char       *to_str,
                 const char *from_str)

{
   if ( ! to_str ) return NULL;

   if ( ! from_str ) return NULL;

   unsigned int to_len   = my_strlen(to_str);
   unsigned int from_len = my_strlen(from_str);

   if (to_len < from_len) return NULL;

   memset(to_str, 0, to_len);

   for (unsigned int i = 0; i < from_len; i++)
   {
       to_str[i] = from_str[i];
   }
 
   return to_str;
}


//------------------------------------------------
// my_strcmp
//
// Description:
//    This function compares the two given strings.
//    A value less than zero is returned if "str_1"
//    is lexicographically less than "str_2".  A
//    value greater than zero is returned if "str_1"
//    is lexicographically greater than "str_2".
//    A value of zero is returned if both strings
//    are lexicographically equivalent.
//
//    Lexicographically means that each of the
//    characters of the given strings are compared
//    to one another.  The comparison is based
//    on each character's position in the ASCII
//    table.  Therefore, upper and lower case
//    matter.  Also, non alphnumeric characters
//    are considered based on their position in
//    the ASCII table.  For example, the following
//    applies:
//
//          "ABC" > "abc"
//          "AB^" > "ABC"
//
//    The ANSI signature is:
//
//       int strcmp
//              (const char *string1,
//               const char *string2);
//
//------------------------------------------------
static int my_strcmp
              (const char *str_1,
               const char *str_2)

{
         int result = 0;

   result = str_1 > str_2;

   return result;
}

/* EOF */

