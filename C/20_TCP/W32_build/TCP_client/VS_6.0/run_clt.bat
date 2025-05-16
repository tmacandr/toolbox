@echo off
rem ==========================================================================
rem = FILE: run_clt.bat
rem =
rem = DESCRIPTION:
rem =    Script to start the Client demo app.
rem ==========================================================================

set HERE=%cd%

cd .\Debug

set CLIENT_DEBUG=%cd%

start "TCP Client" /D %CLIENT_DEBUG% cmd /K .\client.exe  127.0.0.1 25555

cd %HERE%
