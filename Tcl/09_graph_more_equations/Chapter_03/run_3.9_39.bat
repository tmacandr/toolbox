@echo off
rem **************************************************************************
rem * FILE: run_3.9_39.bat
rem *
rem * DESCRIPTION:
rem *    DOS script to run the Tcl program:
rem *       graph_exercise_3.9_39.tcl    
rem **************************************************************************

set HERE=%cd%

set PATH=%PATH%;C:\Tcl\bin

set Tcl_Shell=wish85.exe

%Tcl_Shell% graph_exercise_3.9_39.tcl

rem %Tcl_Shell% graph_exercise_3.9_39b.tcl

echo Done
