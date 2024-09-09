@echo off
rem **************************************************************************
rem * FILE: run_graph.bat
rem *
rem * DESCRIPTION:
rem *    DOS batch program to run the simple graphics script
rem **************************************************************************

set HERE=%cd%

C:\Tcl\bin\wish graph_sine_limit.tcl

echo Done
