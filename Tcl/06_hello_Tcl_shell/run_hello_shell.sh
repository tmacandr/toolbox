#!/bin/bash
# * *************************************************************************
# * FILE: run_hello_shell.bat
# *
# * DESCRIPTION:
# *    DOS batch program to run the "hello" Tcl script
# * *************************************************************************

export HERE=`pwd`

/usr/bin/wish hello_shell.tcl

echo "Done"
