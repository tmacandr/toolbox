@echo off
rem --========================================================================
rem -- FILE: run.bat
rem --
rem -- DESCRIPTION:
rem --    Script to run the 'HelloWorld' java program.
rem --========================================================================
set CLASSPATH=%cd%

set CLASS=HelloWorld.class

if not exist %CLASS% (

   echo -^-^-^> Program %CLASS% not found

   exit

)

echo ^-^-^-^> Run:

java HelloWorld

echo -^-^-^> Done

