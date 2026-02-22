/*****************************************************************************
 * FILE: c_functions.c
 *
 * DESCRIPTION:
 *    Example of functions that are called from Tcl scipt.
 *****************************************************************************/
#include <stdio.h>
#include "c_functions.h"

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
int C_func_Init(Tcl_Interp *interp)
{
   const char *s = Tcl_InitStubs(interp, TCL_VERSION, 0);

   if (s == NULL)
   {
      printf("***> ERROR - Tcl init stubs fail\n");
      return TCL_ERROR;
   }

   /*
    * Provide the package "c_functions"
    */
   int r = Tcl_PkgProvide(interp, "c_functions", "1.0"); 

   if (r == TCL_ERROR)
   {
       printf("***> ERROR - Package Provide FAIL\n");
       return TCL_ERROR;
   }

   /*
    * Create the new Tcl command "get_integer" and link it to
    * the C function MyAddCmd
    */
   Tcl_CreateCommand
          (interp,
           "get_integer",
           get_integer,
           (ClientData) NULL,
           (Tcl_CmdDeleteProc *) NULL);

   Tcl_CreateCommand
          (interp,
           "get_float",
           get_float,
           (ClientData) NULL,
           (Tcl_CmdDeleteProc *) NULL);

   Tcl_CreateCommand
          (interp,
           "get_string",
           get_string,
           (ClientData) NULL,
           (Tcl_CmdDeleteProc *) NULL);

   return TCL_OK;
}


/************************************************
 * FUNCTION: get_integer
 *
 * DESCRIPTION:
 *   Function called by Tcl script to return
 *   an integer.
 ***********************************************/
int get_integer(ClientData clientData, 
                Tcl_Interp *interp, 
                int        argc,
                const char *argv[])
{
   int answer = 1234;

   printf("---> get_integer: %d\n", answer);

   return TCL_OK;
}

/************************************************
 * FUNCTION: get_float
 *
 * DESCRIPTION:
 *   Function called by Tcl script to return
 *   an float.
 ***********************************************/
int get_float(ClientData clientData, 
                Tcl_Interp *interp, 
                int        argc,
                const char *argv[])
{
   float answer = 3.14159f;

   printf("---> get_float: %f\n", answer);

   return TCL_OK;
}


/************************************************
 * FUNCTION: get_string
 *
 * DESCRIPTION:
 *   Function called by Tcl script to return
 *   an string.
 ***********************************************/
int get_string(ClientData clientData, 
                Tcl_Interp *interp, 
                int        argc,
                const char *argv[])
{
   char *answer = "The quick brown fox";

   printf("---> get_string: %s\n", answer);

   return TCL_OK;
}

/* EOF */

