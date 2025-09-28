#!/bin/sh
# * *************************************************************************
# * FILE: run_hello_gui.bat
# *
# * DESCRIPTION:
# *    DOS batch program to run the "hello" Tcl script
# * *************************************************************************

export HERE=`pwd`

/usr/bin/wish hello_gui.tcl

echo "Done"
