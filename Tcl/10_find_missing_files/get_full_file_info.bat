@echo off
rem * *************************************************************************
rem * FILE: get_full_file_info.bat
rem *
rem * DESCRIPTION:
rem *    DOS batch program that does a simple "dir" on the specified file.
rem *    This is because the file might have special characters and a simple
rem *    dir \b <file-name> invoked from Tcl without quotes (") will fail.
rem *
rem *    And I can't figure out how to build a command string that has quotes
rem *    around the file-name.
rem *
rem *    So after much struggle, wheter the file name/path has 'special
rem *    characters in its name or not, the rule/protocol is that the Tcl
rem *    script must write the name of the file to a text file called
rem *    'in.txt' ... and then the Tcl script must'exec' this .bat script.
rem *    This batch script will input the filename from the 'in.txt' file
rem *    and then perform the 'dir' by putting the quotes (") around the
rem *    name of the file.
rem * *************************************************************************

set /p IN=< in.txt

set FILE="%IN%"

dir %FILE%
