@echo off
rem --************************************************************************
rem -- FILE: run_client.bat
rem --
rem -- DESCRIPTION:
rem --    DOS script that starts the UDP client in a console window ... using
rem --    canned args.
rem --
rem --    The term 'client' is a bit of a misnomer in that there really is
rem --    no client-server when using UDP.  It's better described as
rem --    peer-to-peer.  There's no 'listening' socket ... connection
rem --    requests, etc.  Messages are 'sentTo()' and 'recvFrom()' between
rem --    peers.
rem --************************************************************************

set HERE=%cd%

if not exist Debug (

   echo ^*^*^*^> ERROR ^- Debug directory not found

   goto DONE
)

cd Debug

set EXE=UDP_client.exe

if not exist %EXE% (

   echo ^*^*^*^> ERROR ^- File %EXE% not found

   goto DONE
)

%EXE% 127.0.0.1 25555 25556

:DONE

   cd %HERE%

   echo ^-^-^-^> Done

