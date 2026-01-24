/*****************************************************************************
 * FILE: c_functions.c
 *
 * DESCRIPTION:
 *    Example of functions that are called from Tcl scipt.
 *****************************************************************************/
#include <stdio.h>
#include "c_functions.h"


/************************************************
 * FUNCTION: get_integer
 *
 * DESCRIPTION:
 *   Function called by Tcl script to return
 *   an integer.
 ***********************************************/
int get_integer(void)
{
   return 1234;
}

/************************************************
 * FUNCTION: get_float
 *
 * DESCRIPTION:
 *   Function called by Tcl script to return
 *   an float.
 ***********************************************/
float get_float(void)
{
   return 3.14159f;
}


/************************************************
 * FUNCTION: get_string
 *
 * DESCRIPTION:
 *   Function called by Tcl script to return
 *   an string.
 ***********************************************/
int get_string(void)
{
   return "The quick brown fox";
}

/* EOF */

