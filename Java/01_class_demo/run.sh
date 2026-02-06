#!/bin/sh
# *****************************************************************
# *  FILE: run.bat
# * 
# *  DESCRIPTION:
# *     Bourne script to run the "class_demo" Java program
# ******************************************************************

export HERE=`pwd`

# ********************************************
# * Use ';' to add more directories, when needed
# ********************************************
export CLASSPATH=$HERE

java class_demo
