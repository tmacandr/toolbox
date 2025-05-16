@echo off
rem ==========================================================================
rem = FILE: run_svr.bat
rem =
rem = DESCRIPTION:
rem =    Script to start the server demo app.
rem ==========================================================================

set HERE=%cd%

cd .\Debug

set SVR_DEBUG=%cd%

start "TCP Server" /D %SVR_DEBUG% cmd /K .\server.exe  25555

cd %HERE%
