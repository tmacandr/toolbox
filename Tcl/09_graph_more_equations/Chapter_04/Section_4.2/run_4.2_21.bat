@echo off
rem **************************************************************************
rem * FILE: run_4.2_21.bat
rem *
rem * DESCRIPTION:
rem *    DOS script to run the Tcl program:
rem *       graph_exercise_4.2_21.tcl    
rem **************************************************************************

set HERE=%cd%

set PATH=%PATH%;C:\Tcl\bin

set Tcl_Shell=wish85.exe

%Tcl_Shell% graph_exercise_4.2_21.tcl

echo Done
