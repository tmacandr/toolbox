@echo off
rem * *************************************************************************
rem * FILE: run_hello_Tcl.bat
rem *
rem * DESCRIPTION:
rem *    DOS batch program to run the "hello" Tcl script
rem * *************************************************************************

set HERE=%cd%

set TCL_SHELLS=C:\Tcl\bin\tclsh84.exe ^
               C:\Tcl\bin\tclsh85.exe ^
               C:\cygwin\bin\tclsh84.exe

FOR %%i IN ( %TCL_SHELLS% ) DO (

   IF EXIST %%i. (

      echo TCL shell...: %%i

      set Tcl_Shell=%%i

      goto RUN
   )

)

echo Can NOT find bin directory for Tcl

goto DONE

:RUN

%Tcl_Shell% hello.tcl

:DONE

echo Done
