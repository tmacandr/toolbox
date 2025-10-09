@echo off
rem #=========================================================================
rem # FILE: build.bat
rem #
rem # DESCRIPTION:
rem #    Script that invokes Visual Studio NMAKE on 'build.mak' to compile and
rem #    link TCP_client.c and TCP_server.c
rem #
rem #    It attempts to find an installation of Visual Studio and use the
rem #    paths to tools, headers, and link libraries for the build.  It
rem #    assumes certain versions for particular releases, which may not match
rem #    an actual installation.
rem #
rem # RUN:
rem #    build.bat
rem #=========================================================================
set HERE=%cd%

set VS_VER="not found"
set VS_ROOT="not found"
set VS_BIN_DIR="not found"
set INCL="not found"
set LPATH="not found"
set TMP_VAR="not found"

call :Find_VS_Root

if %VS_ROOT% == "not found" (
   echo ^*^*^*^> ERROR ^- Visual Studio installation not found
   goto DONE
)

if not exist %VS_ROOT% (
   echo ^*^*^*^> ERROR ^- Visual Studio installation appears invalid
   goto DONE
)

call :Find_VS_Bin_Dir

if %VS_BIN_DIR% == "not found" (
   echo ^*^*^*^> ERROR ^- Visual Studio binaries not found
   goto DONE
)

if not exist %VS_BIN_DIR% (
   echo ^*^*^*^> ERROR ^- Visual Studio binaries area is invalid
   echo ^*^*^*^>      ^- %VS_BIN% not valid
   goto DONE
)

if not exist %VS_BIN_DIR%\nmake.exe (
   echo ^*^*^*^> ERROR ^- Visual Studio NMAKE not found
   echo ^*^*^*^>      ^- nmake not found int %VS_BIN%
   goto DONE
)

if not exist %VS_BIN_DIR%\cl.exe (
   echo ^*^*^*^> ERROR ^- Visual Studio CL.exe not found
   echo ^*^*^*^>      ^- cl not found int %VS_BIN%
   goto DONE
)

call :Set_Include_Path

call :Set_Link_Path

rem ==================================================
rem = Perform build
rem ==================================================

cd %HERE%

%VS_BIN_DIR%\nmake.exe /f build.mak clean

if %ERRORLEVEL% neq 0 (
   echo ^*^*^*^> ERROR - clean failed
   goto DONE
)

%VS_BIN_DIR%\nmake.exe /f build.mak

if %ERRORLEVEL% neq 0 (
   echo ^*^*^*^> ERROR - build failed
   goto DONE
)

:DONE
   cd %HERE%
   echo ^-^-^-^> Done
   goto :EOF


rem #=========================================================================
rem # SUBPROGRAM: Find_VS_Root
rem #
rem # DESCRIPTION:
rem #    Searches for a base installation of Visual Studio.
rem #=========================================================================
:Find_VS_Root

   echo ^-^-^-^-^-^-^-^-Find_VS_Root^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-

   rem =====================================
   rem = Check for "Professional" installation
   rem = of version 2019.
   rem =====================================
   set LOC="C:\Program Files (x86)\Microsoft Visual Studio"\2019\Professional

   if exist %LOC% (
       set VS_VER=VC2019
       set VS_ROOT=%LOC%
       goto FIND_ROOT_DONE
   )

   rem ==========================================
   rem = Check for Version 14.0, which corresponds
   rem = to release from 2015
   rem ==========================================
   set LOC="C:\Program Files (x86)\Microsoft Visual Studio 14.0"

   if exist %LOC% (
       set VS_VER=VC2015
       set VS_ROOT=%LOC%
       goto FIND_ROOT_DONE
   )

   set LOC="C:\Program Files\Microsoft Visual Studio"\VC98

   if exist %LOC% (
       set VS_VER=VC98
       set VS_ROOT=%LOC%
       goto FIND_ROOT_DONE
   )

   :FIND_ROOT_DONE

   call :Convert_To_Short_Path_Form %VS_ROOT%

   set VS_ROOT=%TMP_VAR%

   echo ^-^-^-^> VS Version: %VS_VER%
   echo ^-^-^-^> VS_ROOT  : %VS_ROOT%
   echo ^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-

   goto :EOF


rem #=========================================================================
rem # SUBPROGRAM: Find_VS_Bin_Dir
rem #
rem # DESCRIPTION:
rem #    Searches for base 'bin' installation of Visual Studio.
rem #=========================================================================
:Find_VS_Bin_Dir

   echo ^-^-^-^-^-^-^-^-Find_VS_Bin_Dir^-^-^-^-^-^-^-^-^-^-^-^-

   if "%VS_VER%" == "VC2019" (
       rem =========================================
       rem = Assumes particular version "14.29.30133"
       rem =========================================
       set VS_BIN_DIR=%VS_ROOT%\VC\Tools\MSVC\14.29.30133\bin\Hostx86\x64
       goto FIND_BIN_DONE
   )

   if "%VS_VER%" == "VC2015" (
       set VS_BIN_DIR=%VS_ROOT%\VC\bin
       goto FIND_BIN_DONE
   )

   if "%VS_VER%" == "VC98" (
       set VS_BIN_DIR=%VS_ROOT%\Bin
       goto FIND_BIN_DONE
   )

   :FIND_BIN_DONE

   echo ^-^-^-^> VS BIN: %VS_BIN_DIR%
   echo ^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-

   goto :EOF


rem #=========================================================================
rem # SUBPROGRAM: Set_Include_Path
rem #
rem # DESCRIPTION:
rem #    Sets the base include path parameters needed to compile.
rem #=========================================================================
:Set_Include_Path

   echo ^-^-^-^-^-^-^-^-Set_Include_Path^-^-^-^-^-^-^-^-^-^-^-^-

   if "%VS_VER%" == "VC2019" (
       set INCL=/I%VS_ROOT%\VC\Tools\MSVC\14.29.30133\include        ^
                /I%VS_ROOT%\SDK\ScopeCppSDK\vc15\SDK\include\um      ^
                /I%VS_ROOT%\SDK\ScopeCppSDK\vc15\SDK\include\shared  ^
                /I%VS_ROOT%\SDK\ScopeCppSDK\vc15\SDK\include\ucrt

       goto SET_INCL_DONE
   )

   if "%VS_VER%" == "VC2015" (
       set KIT_DIR="C:\Program Files (x86)\Windows Kits"\10\Include\10.0.10240.0

       set INCL=/I%KIT_DIR%\include  ^
                /I%KIT_DIR%\um       ^
                /I%KIT_DIR%\shared   ^
                /I%KIT_DIR%\ucrt

       goto SET_INCL_DONE
   )

   if "%VS_VER%" == "VC98" (
       set INCL=/I%VS_ROOT%\include

       goto SET_INCL_DONE
   )

   :SET_INCL_DONE

   echo ^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-

   goto :EOF


rem #=========================================================================
rem # SUBPROGRAM: Set_Link_Path
rem #
rem # DESCRIPTION:
rem #    Sets the base library paths needed for linking.
rem #=========================================================================
:Set_Link_Path

   echo ^-^-^-^-^-^-^-^-Set_Link_Path^-^-^-^-^-^-^-^-^-^-^-^-

   if "%VS_VER%" == "VC2019" (
       set LPATH=/LIBPATH:%VS_ROOT%\SDK\ScopeCppSDK\vc15\SDK\lib      ^
                 /LIBPATH:%VS_ROOT%\VC\Tools\MSVC\14.29.30133\lib\x64
       goto SET_LPATH_DONE
   )

   if "%VS_VER%" == "VC2015" (
       set KIT_DIR="C:\Program Files (x86)\Windows Kits"\10\lib\10.0.10240.0
       set LPATH=/LIBPATH:%KIT_DIR%\lib        ^
                 /LIBPATH:%KIT_DIR%\lib\x64    ^
                 /LIBPATH:%KIT_DIR%\lib\um\x64
       goto SET_LPATH_DONE
   )

   if "%VS_VER%" == "VC98" (
       set LPATH=/LIBPATH:%VS_ROOT%\Lib
       goto SET_LPATH_DONE
   )

   :SET_LPATH_DONE

   echo ^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-

   goto :EOF


rem #=========================================================================
rem # SUBPROGRAM: Increment_Counter
rem #
rem # DESCRIPTION:
rem #    Adds one to %1.  Invoked by 'for' loop not using delayed expansion
rem #=========================================================================
:Increment_Counter

   rem echo ^-^-^-^> Increment: %COUNT%

   set /a COUNT=COUNT+1

   goto :EOF


rem #=========================================================================
rem # SUBPROGRAM: Set_Dir_Loop_Param
rem #
rem # DESCRIPTION:
rem #    Sets the global variable TMP_VAR to the value in %1 if the global
rem #    variable COUNT is 0.  Nominally invoked from a 'for' loop to set
rem #    the first value in the overall iteration.
rem #=========================================================================
:Set_Dir_Loop_Param

   rem echo ^-^-^-^> Set Dir Loop
   rem echo ^-^-^-^>    Count: %COUNT%
   rem echo ^-^-^-^>    Dir  : %1

   if %COUNT% equ 0 (

       rem echo ^-^-^-^> Setting dir: %1

       set TMP_VAR=%1
   )

   goto :EOF


rem #=========================================================================
rem # SUBPROGRAM: Convert_To_Short_Path_Form
rem #
rem # DESCRIPTION:
rem #    Converts the given directory path from 'full' format to 'short'
rem #    path, i.e. to eliminate blanks and/or special characters from the
rem #    path.
rem #
rem #    The result is placed in the global variable %TMP_VAR%
rem #=========================================================================
:Convert_To_Short_Path_Form

   set TO=%HERE%\short.txt

   echo %1 > %TO%

   set TMP_VAR="not found"

   set COUNT=0

   for /f "delims=$" %%i in (%TO%) do (
       call :Set_Dir_Loop_Param %%~si
   )

   del /f /q %TO%

   rem echo ^-^-^-^> Convert:
   rem echo ^-^-^-^>    From: %1
   rem echo ^-^-^-^>    to  : %TMP_VAR%

   goto :EOF

