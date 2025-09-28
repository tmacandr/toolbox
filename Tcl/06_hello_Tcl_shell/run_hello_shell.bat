@echo off
rem * *************************************************************************
rem * FILE: run_hello_shell.bat
rem *
rem * DESCRIPTION:
rem *    DOS batch program to run the "hello" Tcl script
rem * *************************************************************************

set HERE=%cd%

C:\Tcl\bin\wish hello_shell.tcl

echo Done
