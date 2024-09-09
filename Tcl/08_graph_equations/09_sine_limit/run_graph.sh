#!/bin/sh
# * *************************************************************************
# * FILE: run_graph.sh
# *
# * DESCRIPTION:
# *    UNIX script to run the simple graphics Tcl script
# * *************************************************************************

HERE=`pwd`

/usr/bin/wish graph_sine_limit.tcl

echo "Done"
