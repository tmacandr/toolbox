/*****************************************************************************
 * FILE: c_functions.h
 *
 * DESCRIPTION:
 *    Example of functions that are called from Tcl scipt.
 *****************************************************************************/
#ifndef Tcl_C_FUNCITONS

#define Tcl_C_FUNCITONS

/************************************************
 * FUNCTION: get_integer
 *
 * DESCRIPTION:
 *   Function called by Tcl script to return
 *   an integer.
 ***********************************************/
int get_integer(void);

/************************************************
 * FUNCTION: get_float
 *
 * DESCRIPTION:
 *   Function called by Tcl script to return
 *   an float.
 ***********************************************/
float get_float(void);


/************************************************
 * FUNCTION: get_string
 *
 * DESCRIPTION:
 *   Function called by Tcl script to return
 *   an string.
 ***********************************************/
int get_string(void);

#endif

/* EOF */

