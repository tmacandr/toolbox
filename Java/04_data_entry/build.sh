#!/bin/bash
#=============================================================================
# FILE: build.sh
#
# DESCRIPTION:
#    Uses the Java compiler 'javac' to build the 'data entry' program.
#=============================================================================

HERE=`pwd`

CLASSPATH="$HERE;src"

cd src

SRC=data_entry.java

echo "---> Compile $SRC"

javac $SRC

cd ..

SRC=main.java

echo "---> Compile $SRC"

javac $SRC

echo "---> Done"

