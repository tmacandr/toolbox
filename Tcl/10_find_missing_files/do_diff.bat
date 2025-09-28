@echo off
rem * *************************************************************************
rem * FILE: do_diff.bat
rem *
rem * DESCRIPTION:
rem *    DOS batch program that invokes the "Beyond Compare" tool to do a
rem *    binary diff against two specified files.  This script is intended
rem *    to be invoked by the 'find_missing_files.tcl' script.
rem *
rem *    The "issue" I've been wrestling with is how to handle file names
rem *    (and directory paths) that have 'special' characters in them ...
rem *    specifically names with one or more blanks (' ').
rem *
rem *    No matter how hard I tried, the command-line arguments coming
rem *    in had no quotes around them (") ... so the 'Beyond Compare'
rem *    was only getting fragments (sub-strings) of the full arguments.
rem *
rem *    So after much struggle, the implementation is for the Tcl script
rem *    to (simply) pass the file names/paths as:
rem *
rem *           [exec do_diff.bat $Left $Right]
rem *
rem *    So there's no adding (pre-pending, catenating) quotes (") to the
rem *    arguments.
rem *
rem *    Then, this script must access the arguments as "%~1%" and "%~2%".
rem *
rem *    And this bothers me to no end because the semantics of it confuse
rem *    me.  I thought (only recently) that the '~' operator tells DOS to
rem *    strip off quotes (") from the command line arguments ... so that
rem *    %~1 is just the first argument without quotes if they were there
rem *    or not.
rem *
rem *    But they're not.  So why wouldn't %1% work?
rem *
rem *    When I specify %1% then only the first sub-string comes in and
rem *    rest of the file name becomes the second argument.
rem *
rem *    But when I specify "%~1" then the whole string (including spaces)
rem *    comes in and this is how it has to be passed to 'Beyond Compare'.
rem *
rem *    How was DOS able to figure out where the first argument stopped
rem *    and the second argument began ... and that the blank in the
rem *    second argument was not the start of a third argument ... etc?
rem *    
rem *    Very frustrating ... by trial-n-error it works.  But worse, once 
rem *    I got it to work, I have no explanation as to why.
rem * *************************************************************************

set HERE=%cd%

set /p LEFT_IN=< left.txt

set /p RIGHT_IN=< right.txt

set LEFT="%LEFT_IN%"

set RIGHT="%RIGHT_IN%"

rem echo LEFT.: %LEFT%
rem echo RIGHT: %RIGHT%

if not exist %LEFT% (

   echo ^*^*^*^> ERROR
   echo ^*^*^*^>    Left diff file %LEFT% not found

   exit 200

)

if not exist %RIGHT% (

   echo ^*^*^*^> ERROR
   echo ^*^*^*^>    Right diff file %RIGHT% not found

   exit 300

)

set BC_DIR="C:\Program Files (x86)\Beyond Compare 3"

if not exist %BC_DIR% (

   echo ^*^*^*^> ERROR
   echo ^*^*^*^>    Beyond Compare tool not found
   echo ^*^*^*^>    %BC_DIR% not found

   exit 400

)

%BC_DIR%\BCompare.exe /qc=binary %LEFT% %RIGHT%

echo Binary Diff: %ERRORLEVEL%

cd %HERE%

