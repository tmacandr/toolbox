/*****************************************************************************
* FILE: taylor_series.c
*
* DESCRIPTION:
*    Implements a Taylor approximation for the sin(x) function on the
*    domain -PI/2 .. PI/2.  The range will always be between -1.0 .. 1.0.
******************************************************************************/

#include <stdio.h>
#include <time.h>

static double start_time_ms = 0.0;
static double end_time_ms   = 0.0;

static void run_test
               (const unsigned int num_sample_points,
                const char         show_output);

static void set_time (double *to_ms);


/***************************************
* FUNCTION: main
*
* DESCRIPTION:
*    Main entry point of program.
****************************************/
int main (int argc, char **argv)

{
         unsigned int num_sample_points;
         char         show_output;

   set_time (&start_time_ms);

   printf("______________________\n");
   printf("Taylor Series\n");

   if (argc != 3)
   {
       printf("***> ERROR - invalid arguments\n"
              "***> Usage:\n"
              "        taylor_series.exe <num-sample-points> <show-output>\n"
              "***> Example:\n"
              "        taylor_series.exe 1024 Y\n");

       return 0;
   }

   sscanf (argv[1], "%u", &num_sample_points);
   sscanf (argv[2], "%c", &show_output);

   printf("---> Settings:\n"
          "     Number of sample points....: %u\n"
          "     Show sample points.........: %c\n",
          num_sample_points,
          show_output == 'Y' ? 'Y' : 'N');

   run_test (num_sample_points, show_output);

   set_time (&end_time_ms);

   printf("---> Elapsed time...: %6.4lf ms\n",
          end_time_ms - start_time_ms);

   printf("______________________\n");

   return 0;
}


/***********************************************
* FUNCTION: run_test
*
* DESCRIPTION:
*    Uses a Taylor approximation for the sin(x)
*    function on the domain -PI/2 .. PI/2.
*    Therefor the range will always be between
*    -1.0 .. 1.0.
************************************************/
static void run_test
               (const unsigned int num_sample_points,
                const char         show_output)

{
      unsigned int       i;
      double             x,
                         y,
                         sum;
      const double       three_factorial = 3.0 * 2.0;
      const double       five_factorial  = 5.0 * 4.0 * three_factorial;
      double             delta_x;
 
   printf("_______________________\n");
   printf("---> Begin test\n");

  /*
   * Use a Taylor series to the 5th degree to approximate
   * the sine function.  But it only approximates in the
   * domain -pi/2 .. pi/2.  Outside of that it goes very
   * bogus.  Now, to performa a total of ... say,
   * ... UINT_MAX operations ... then x needs to be
   * incremented is steps of:
   *
   *                  [pi/2 - (-pi/2)]
   *       delta_x = ------------------
   *                  number-of-samples
   */
   x = 3.14159;

   delta_x = x / (double) num_sample_points;

   x = x / 2.0;

   x = -x;

   sum = 0.0;

   for (i = 0; i <= num_sample_points; i++)
   {
       /*
        * Sine function as Taylor approximation to
        * degree 5 (i.e. to the fifth derivative) ...
        *                       3       5
        *                      x       x
        *       sin(x) = x - ----- + -----
        *                      3!      5!
        * Don't want to use any functions from the <math.h>
        * library ... so this is rather raw.
        *
        * Although ... a good optimizer should have a field-day
        * with the following statement ...
        */
       y = x - (x * x * x) / three_factorial + (x * x * x * x * x) / five_factorial;

       sum = sum + y;

       if (show_output == 'Y')
       {
           printf("---> (x, y) = (% 4.3lf, % 6.5lf)\n", x, y);
       }

       /*
        * x should max out at pi/2
        */
       x = x + delta_x;
   }

   /*
    * sum should be close to 0 when it's all
    * over with.  The higher the degree, the
    * more accurate.
    */
   printf("sum = %6.5lf (should be close to 0.0)\n",
          sum);
   printf("---> End: test\n");
   printf("_______________________\n");
}


/***********************************************
* FUNCTION: set_time
*
* DESCRIPTION:
*    Sets the item 'to_ms' to the current system
*    time as reported by 'sys_clock_gettime()'
*    which reports time in the data-structure
*    'struct timespec'.
************************************************/
static void set_time (double *to_ms)

{
         long   status;
         struct timespec time_obj = { 0, 0 };

   status = clock_gettime
               (CLOCK_REALTIME,
                &time_obj);

   if (status)
   {
       printf("***> ERROR - call to clock_gettime() failed\n"
              "    sec....: %u\n"
              "    nsec...: %u\n",
              (unsigned int) time_obj.tv_sec,
              (unsigned int) time_obj.tv_nsec);

       *to_ms = 0.0;
   }
   else
   {
       *to_ms = (double) time_obj.tv_sec * 1000.0 +
                (double) time_obj.tv_nsec * 1.0E-06;
   }
}

/* EOF */

