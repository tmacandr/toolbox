#!/bin/sh
#=============================================================================
# FILE: run.sh
#
# DESCRIPTION:
#    Script to run the 'button' java program.  Java run-time-environment
#    is invoked by /usr/bin/java
#=============================================================================
CLASSPATH=`pwd`

CLASS=ButtonExample.class

if ! test -e $CLASS; then

   echo "---> Program $CLASS not found"

   exit

fi

echo "---> Run:"

java ButtonExample

echo "---> Done"

