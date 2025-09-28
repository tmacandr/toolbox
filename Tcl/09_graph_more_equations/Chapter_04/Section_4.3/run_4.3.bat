@echo off
rem **************************************************************************
rem * FILE: run_4.3.bat
rem *
rem * DESCRIPTION:
rem *    DOS script to run the Tcl program specified by comman-line option
rem *    Operator inputs which Tcl program to run:
rem *
rem *       graph_exercise_4.3_<N>.tcl    
rem **************************************************************************

set WHICH_GRAPH=%~1

echo ^-^-^-^> %~1

if "%WHICH_GRAPH%"=="" (

   goto SHOW_USAGE

)

echo ^-^-^-^> %WHICH_GRAPH%

set HERE=%cd%

set PATH=%PATH%;C:\Tcl\bin

set Tcl_Shell=wish85.exe

%Tcl_Shell% graph_exercise_4.3_%WHICH_GRAPH%.tcl

goto DONE

:SHOW_USAGE

   echo *^*^*^> ERROR ^- Invalid argument
   echo *^*^*^>
   echo *^*^*^> USAGE:
   echo *^*^*^>    run_4.3.bat ^<which^-graph^>
   echo *^*^*^>
   echo *^*^*^> EXAMPLE:
   echo *^*^*^>    run_4.3.bat 03
   echo *^*^*^>

:DONE
   echo Done
