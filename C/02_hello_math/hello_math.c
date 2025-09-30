/*******************************************************
* FILE: hello_math.c
*
* DESCRIPTION:
*    Hello world to verify availability of the <math>
*    library in CYGWIN.
********************************************************/

#include <stdio.h>
#include <math.h>


/***************************************
* FUNCTION: main
*
* DESCRIPTION:
*    Main entry point of program.
****************************************/
int main (int argc, char **argv)

{
         double x = 1.0L,
                y = 2.0,
                z;

   printf("______________________\n");
   printf("hello math world\n");

   z = sqrt (x * x + y * y);

   printf("z = %3.4lf\n", z);

   z = pow (y, 2.0);

   printf("z = %4.3lf\n", z);

   printf("______________________\n");

   return 0;
}

