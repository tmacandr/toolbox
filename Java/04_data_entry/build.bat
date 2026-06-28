@echo off
rem *****************************************************************
rem *  FILE: build.bat
rem * 
rem *  DESCRIPTION:
rem *     This DOS batch program that Java compiles the "data_entry"
rem *     program.
rem ******************************************************************

set HERE=%cd%

rem ********************************************
rem * Java compiler 'javac' is included in the
rem * Android SDK.  Otherwise, have to download
rem * a Java SDK from some place else.
rem ********************************************

set PATH=%PATH%;C:\Program Files\Android\Android Studio\jre\bin

rem ********************************************
rem * Use ';' to add more directories, when needed
rem ********************************************

set CLASSPATH=%HERE%;.\src

cd src

set SRC=data_entry.java
set OBJ=data_entry.class

IF EXIST %OBJ% (

    echo ^-^-^-^> Delete old %OBJ%

    del %OBJ%
)

echo ^-^-^-^> Compile: %SRC%

javac %SRC%

cd %HERE%

set SRC=main.src
set OBJ=main.class

IF EXIST %OBJ% (

    echo ^-^-^-^> Delete old %OBJ%

    del %OBJ%
)

echo ^-^-^-^> Compile: %SRC%

javac %SRC%

echo Done ...

