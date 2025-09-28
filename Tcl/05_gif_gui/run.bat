@echo off
rem * *************************************************************************
rem * FILE: run.bat
rem *
rem * DESCRIPTION:
rem *    DOS batch program to run the load GIF script
rem *
rem *    First tried JPEG.  But Tcl/Tk does not support JPEG without
rem *    extensions.  Switched to GIF.
rem * *************************************************************************

set HERE=%cd%

set TCL_SHELLS=C:\Tcl\bin\wish84.exe ^
               C:\Tcl\bin\wish.exe

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

%Tcl_Shell% load_gif.tcl

:DONE

echo Done
