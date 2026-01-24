//-------------------------------------------------------------------------
// File : main_2_5.cpp
// Date : 17-Apr-00 : initial defintion
//        23-Apr-26 : Update to GNU g++
//
// Description:
//    Exercise 5 from Chapter 2 of:
//
//          "The C++ Programming Language, 2nd Ed.", B. Stroustroup,
//          Addison-Wesley Publishing Co., 1995.
//
//    Write a program that prints out the letters 'a' .. 'z' and the
//    digits '0' .. '9' and their integer values.  Do the same for other
//    printable characters.  Do the same, but use hexadecimal notation.
//-------------------------------------------------------------------------

#include <iostream>


typedef struct
   {
    char theChar;
    char *name;
   } specialCharRecType;

//------------------------------------------------------------
// print_ASCII_char 
//
// Description:
//    Function that prints ascii char to stdout.
//------------------------------------------------------------
static void print_ASCII_char (unsigned char whichChar)

{
         int                       i;
         static const int          Num_Special_Char = 9;
         static specialCharRecType special_chars[Num_Special_Char] =
                      { {'\n', (char *) "LF"},   // Line-feed
                        {'\t', (char *) "HT"},   // Horiz tab
                        {'\v', (char *) "VT"},   // Vert tab
                        {'\b', (char *) "BS"},   // Back-space
                        {'\r', (char *) "CR"},   // Carriage-return
                        {'\f', (char *) "FF"},   // Form-feed
                        {'\a', (char *) "BL"},   // Bell
                        {'\\', (char *) "SL"},   // Back-slash
                        {'\0', (char *) "NL"} }; // Null

   for (i = 0; i < Num_Special_Char; i++)
      {
       if (whichChar == special_chars[i].theChar)
          {
           printf("%s  ", special_chars[i].name);

           return;
          }
      }

   if (isprint(whichChar))
      printf("'%c' ", whichChar);
   else
      printf("%.2x  ", whichChar);
}


//------------------------------------------------------------
// main
//
// Description:
//    main function.
//------------------------------------------------------------
int main
        (int argc,
         char **argv)

{
         char theChar;

   printf("__________________________________\n");

   for (theChar = 'a'; theChar <= 'z'; theChar++)
      print_ASCII_char (theChar);

   printf("\n------\n");

   for (theChar = '0'; theChar <= '9'; theChar++)
      print_ASCII_char (theChar);

   printf("\n------\n");

         unsigned char uChar = 0x00;
         int           i = 0;

   while (uChar < 0xff)
      {
       print_ASCII_char (uChar);

       uChar++;

       i++;

       if (i > 15)
          {
           printf("\n");

           i = 0;
          }
      }

   print_ASCII_char (uChar);

   printf("\n");

   return 0;
}

