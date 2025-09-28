#!/bin/sh
# * *************************************************************************
# * FILE: run.sh
# *
# * DESCRIPTION:
# *    Bourne-shell batch program to run the "find_missing_files" Tcl script
# * *************************************************************************

export HERE=`pwd`

/usr/bin/tclsh find_missing_files.tcl  From To Tmp

