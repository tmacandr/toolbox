@echo off
rem * *************************************************************************
rem * FILE: run_4.4_18.Inflections.bat
rem *
rem * DESCRIPTION:
rem *    DOS batch program to run the "exercise_4.4_18.Inflections.tcl" script
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

%Tcl_Shell% exercise_4.4_18.Inflections.tcl

:DONE

echo Done
