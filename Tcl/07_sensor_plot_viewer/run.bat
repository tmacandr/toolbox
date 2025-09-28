@echo off
rem * *************************************************************************
rem * FILE: run.bat
rem *
rem * DESCRIPTION:
rem *    DOS batch program to run the 'radar plot' viewer.
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

%Tcl_Shell% sensor_plot_viewer.tcl plot_list.01.txt

:DONE

echo Done
