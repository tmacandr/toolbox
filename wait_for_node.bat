@echo off
rem #=========================================================================
rem # FILE: wait_for_node.bat 
rem #
rem # DESCRIPTION:
rem #    Pings a node to determine it it's up and connected to the network.
rem #=========================================================================
 
set HERE=%cd%

set NODE=192.168.1.1

set WAIT_SECS=10

:KEEP_TRYING

   Set REPLY=””

   echo ^-^-^-^> Ping node: %NODE%

   for /f “delims=” %%i in (‘ping -n 1 %NODE% ^| find “Request timed out”’) do (
      set REPLY=%%i
   )

   If “%REPLY%”==”Request timed out.” (
      timeout /t %WAIT_SECS%
      goto KEEP_TRYING
   )

echo ^-^-^-^> Node %NODE% is detected

cd /D %HERE%

^-^-^-^> Done

