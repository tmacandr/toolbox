@echo off
rem ==========================================================================
rem = FILE: run.bat
rem =
rem = DESCRIPTION:
rem =    Script to start both the client and server demo apps.
rem ==========================================================================

set HERE=%cd%

cd .\TCP_client\VS_6.0\Debug

set CLIENT_DEBUG=%cd%

start "TCP Client" /D %CLIENT_DEBUG% cmd /K .\client.exe 127.0.0.1 25555

cd %HERE%

cd .\TCP_server\VS_6.0\Debug

set SVR_DEBUG=%cd%

start "TCP Server" /D %SVR_DEBUG% cmd /K .\server.exe  25555

cd %HERE%
