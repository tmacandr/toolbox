#!/bin/sh
# * *************************************************************************
# * FILE: run.bat
# *
# * DESCRIPTION:
# *    Unix script to run the load GIF script
# *
# *    First tried JPEG.  But Tcl/Tk does not support JPEG without
# *    extensions.  Switched to GIF.
# * *************************************************************************

export HERE=`pwd`

/usr/bin/wish load_gif.tcl

echo "Done"

