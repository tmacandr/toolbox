//-------------------------------------------------------------------------
// File : unix_test.cpp
// Date : 04-Apr-00 : initial definition
//        19-Apr-00 : add 'gethostname' test
//        23-Jan-26 : Update to GNU g++
//
// Description:
//    Expand 'hello-world' program to call UNIX function
//    'gethostname'.
//-------------------------------------------------------------------------

#include <iostream>
#include <netdb.h>

// MAXHOSTNAMELEN
#include <asm-generic/param.h>


extern "C"
   {
    int gethostname(char *name, int namelen);
   }



//------------------------------------------------------------
// getNameOfHost 
//
// Description:
//    Experiment.  Similar to a chunk of RTSD code that I want
//    to make sure works ... doesn't seg-fault.
//------------------------------------------------------------
static void getNameOfHost
               (char **theName);


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
   std::cout << "Hello, world\n";

   std::cout << "___________________________\n";
   std::cout << "Some extra stuff ...\n";

   {
             char *nameOfHost;

    getNameOfHost (&nameOfHost);

    std::cout << "Name of this CPU = " << nameOfHost << "\n";
   }

   return 0;
}




//------------------------------------------------------------
// getNameOfHost
//
// Description:
//    Experiment.  Similar to a chunk of RTSD code that I want
//    to make sure works ... doesn't seg-fault.
//------------------------------------------------------------
static void getNameOfHost
               (char **theName)

{
            int status;

   *theName = new char[MAXHOSTNAMELEN];

   status = gethostname
               (*theName,
                MAXHOSTNAMELEN);

   if (status == -1)
   {
       printf("***> ERROR : 'gethostname' fail\n");

       delete [] *theName;
   }
}

