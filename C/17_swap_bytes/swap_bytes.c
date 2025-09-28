/*-------------------------------------------------------------------
 * File: swap_bytes.c
 * Date: 04-Apr-08
 *
 * Description:
 *    Gives an example of how the Floating Point Unit (FPU) of a
 *    machine (CPU) can change the 'expected' value of a byte-swapped
 *    double.
 *
 *    Modified from example from:
 *
 *           http://www.dmh2000.com/cpp/dswap.shtml
 *
 *    No copyright ...
 *
 *    Can also happen to 'float', not just 'double'.
 *
 *    Note - 14-May-2008
 *    ------------------
 *       Set the "Floating point model" to each of the 3 allowed
 *       settings:
 *                /fp:precise
 *                /fp:strict
 *                /fp:fast
 *       This had no effect on the results ... i.e. the defect in
 *       byte-swapping still exists for all 3 options.
 *-------------------------------------------------------------------*/
#include <stdio.h>


/*-----------------------------------------------
 * FUNCTION: charSwap
 *
 * DESCRIPTION:
 *    Copied from 'dfl_serialize.c'.
 *-----------------------------------------------*/
void charSwap(char *c1, char *c2)
{
	char temp;
	temp = *c1;
	*c1 = *c2;
	*c2 = temp;
}


/*-----------------------------------------------
 * FUNCTION: Dpl_Serialize_byteReverseDouble
 *
 * DESCRIPTION:
 *    Copied from 'dfl_serialize.c'.
 *-----------------------------------------------*/
static double Dpl_Serialize_byteReverseDouble(double _d)
{
	union 
	{
		char c[4];
		double d;
	}x;
	x.d = _d;
	charSwap(&x.c[0], &x.c[7]);
	charSwap(&x.c[1], &x.c[6]);
	charSwap(&x.c[2], &x.c[5]);
	charSwap(&x.c[3], &x.c[4]);
	return x.d;
}


/*-----------------------------------------------
 * FUNCTION: main
 *
 * DESCRIPTION:
 *    Main function.
 *-----------------------------------------------*/
int main(int argc,char *argv[])
{
       double        a;
       double        b;
       unsigned char *tmp;
       unsigned char expected_flip[8];
       unsigned char *actual_flip;
       unsigned int  i;

   /*
    * When 'byte-swapped', this becomes NaN.
    */
   a = 3.469999999999970000L;

   tmp = (unsigned char *) &a;

   expected_flip[7] = tmp[0];
   expected_flip[6] = tmp[1];
   expected_flip[5] = tmp[2];
   expected_flip[4] = tmp[3];
   expected_flip[3] = tmp[4];
   expected_flip[2] = tmp[5];
   expected_flip[1] = tmp[6];
   expected_flip[0] = tmp[7];

   b = Dpl_Serialize_byteReverseDouble(a);

   actual_flip = (unsigned char *) &b;

   for (i = 0; i < sizeof(double); i++)
   {
       if (expected_flip[i] != actual_flip[i])
       {
           printf("Byte swap failed:\n");
           printf("Byte........: %u\n", i);
           printf("expected....: 0x%.1x\n", expected_flip[i]);
           printf("actual......: 0x%.1x\n", actual_flip[i]);
       }
   }

   return 0;
}
