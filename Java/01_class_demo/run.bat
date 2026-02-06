@echo off
rem *****************************************************************
rem *  FILE: run.bat
rem * 
rem *  DESCRIPTION:
rem *     DOS batch to run the "class_demo" Java program
rem ******************************************************************

set HERE=%cd%

rem ********************************************
rem * Use ';' to add more directories, when needed
rem ********************************************
set CLASSPATH=%HERE%

java class_demo 
