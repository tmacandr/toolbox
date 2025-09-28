@echo off
rem **************************************************************************
rem * FILE: run_4.2_16.bat
rem *
rem * DESCRIPTION:
rem *    DOS script to run the Tcl program:
rem *       graph_exercise_4.2_16.tcl    
rem **************************************************************************

set HERE=%cd%

set PATH=%PATH%;C:\Tcl\bin

set Tcl_Shell=wish85.exe

%Tcl_Shell% graph_exercise_4.2_16.tcl

echo Done
