/*****************************************************************************
 * FILE: c_functions.h
 *
 * DESCRIPTION:
 *    Example of functions that are called from Tcl scipt.
 *****************************************************************************/
#ifndef Tcl_C_FUNCITONS

#define Tcl_C_FUNCITONS

#include <tcl.h>

/************************************************
 * FUNCTION: C_func_Init 
 *
 * DESCRIPTION:
 *    Function called by Tcl script to initialize
 *    the interface between the Tcl interpreter
 *    (vis-a-vis Tcl shell) and the C functions
 *    defined by this package.
 *
 *    Once this initialization function is
 *    invoked from the Tcl script, the functions
 *    below can be invoked.
 ***********************************************/
int C_func_Init(Tcl_Interp *interp);


/************************************************
 * FUNCTION: get_integer
 *
 * DESCRIPTION:
 *   Function called by Tcl script to return
 *   an integer.
 *
 *   No args
 *
 *   Returns int
 ***********************************************/
int get_integer(ClientData clientData,
                Tcl_Interp *interp,
                int        argc,
                const char *argv[]);

/************************************************
 * FUNCTION: get_float
 *
 * DESCRIPTION:
 *   Function called by Tcl script to return
 *   an float.
 *
 *   No args
 *
 *   Returns float
 ***********************************************/
int get_float(ClientData clientData, 
              Tcl_Interp *interp, 
              int        argc,
              const char *argv[]);


/************************************************
 * FUNCTION: get_string
 *
 * DESCRIPTION:
 *   Function called by Tcl script to return
 *   an string.
 *
 *   No args
 *
 *   Returns char *
 ***********************************************/
int get_string(ClientData clientData, 
               Tcl_Interp *interp, 
               int        argc,
               const char *argv[]);

#endif

/* EOF */

