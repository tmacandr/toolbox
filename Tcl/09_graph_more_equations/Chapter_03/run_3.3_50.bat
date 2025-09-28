@echo off
rem **************************************************************************
rem * FILE: run_3.3_50.bat
rem *
rem * DESCRIPTION:
rem *    DOS script to run the Tcl program:
rem *       graph_exercise_3.3_50.tcl    
rem **************************************************************************

set HERE=%cd%

set PATH=%PATH%;C:\Tcl\bin

set Tcl_Shell=wish85.exe

%Tcl_Shell% graph_exercise_3.3_50.tcl

echo Done
