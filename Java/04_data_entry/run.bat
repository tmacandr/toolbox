@echo off
rem *****************************************************************
rem *  FILE: run.bat
rem * 
rem *  DESCRIPTION:
rem *     DOS batch to run the "JScrollPanes" Java program
rem ******************************************************************

set HERE=%cd%

rem ********************************************
rem * Use ';' to add more directories, when needed
rem ********************************************
set CLASSPATH=%HERE%;.\src

java main

echo ^-^-^-^> Done

