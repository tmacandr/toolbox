@echo off
rem --************************************************************************
rem -- FILE: run_server.bat
rem --
rem -- DESCRIPTION:
rem --    DOS script that starts the UDP server in a console window ... using
rem --    canned args.
rem --************************************************************************

set HERE=%cd%

if not exist Debug (

   echo ^*^*^*^> ERROR ^- Debug directory not found

   goto DONE
)

cd Debug

set EXE=UDP_server.exe

if not exist %EXE% (

   echo ^*^*^*^> ERROR ^- File %EXE% not found

   goto DONE
)

%EXE%  25555

:DONE

   cd %HERE%

   echo ^-^-^-^> Done

