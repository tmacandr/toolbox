#!/bin/bash
# * *************************************************************************
# * FILE: run_format.bat
# *
# * DESCRIPTION:
# *    DOS batch program to run the Tcl script that #oves certain lines
# *    from the test file 'before.txt'
# * *************************************************************************

export HERE=`pwd`

export PROFILE=before.txt

if test -e $PROFILE; then

   /usr/bin/tclsh format_file.tcl $PROFILE

else

   echo "***> ERROR - no input file $PROFILE found"

fi

echo "Done"

