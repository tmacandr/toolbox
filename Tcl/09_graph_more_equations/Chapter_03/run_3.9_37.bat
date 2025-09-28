@echo off
rem **************************************************************************
rem * FILE: run_3.9_37.bat
rem *
rem * DESCRIPTION:
rem *    DOS script to run the Tcl program:
rem *       graph_exercise_3.9_37.tcl    
rem **************************************************************************

set HERE=%cd%

set PATH=%PATH%;C:\Tcl\bin

set Tcl_Shell=wish85.exe

%Tcl_Shell% graph_exercise_3.9_37.tcl

echo Done
