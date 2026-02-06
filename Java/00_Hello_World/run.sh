#!/bin/sh
#=============================================================================
# FILE: run.sh
#
# DESCRIPTION:
#    Script to run the 'hello world' java program.  Java run-time-environment
#    is invoked by /usr/bin/java
#=============================================================================
CLASSPATH=`pwd`

CLASS=HelloWorld.class

if ! test -e $CLASS; then

   echo "---> Program $CLASS not found"

   exit

fi

echo "---> Run:"

java HelloWorld

echo "---> Done"

