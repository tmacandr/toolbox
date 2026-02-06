@echo off
rem *****************************************************************
rem *  FILE: build.bat
rem * 
rem *  DESCRIPTION:
rem *     This DOS batch program that Java compiles the "Hello World"
rem *     program.
rem ******************************************************************

set HERE=%cd%

rem ********************************************
rem * Use ';' to add more directories, when needed
rem ********************************************
set CLASSPATH=%HERE%;.\

set PATH=%PATH%;C:\Program Files\Android\Android Studio\jre\bin

set SRC=HelloWorld.java
set OBJ=HelloWorld.class

IF EXIST %OBJ% (

    echo ^-^-^-^> Delete old %OBJ%

    del %OBJ%
)

echo ^-^-^-^> Compile: %SRC%

javac %SRC%

cd %HERE%

echo Done ...
