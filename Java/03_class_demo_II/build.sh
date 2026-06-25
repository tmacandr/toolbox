#!/bin/bash
#=============================================================================
# FILE: build.sh
#
# DESCRIPTION:
#    Builds the 'something' class/object Java demo.
#
#    Using bash script instead of Makefile because I wasn't sure how to
#    traverse the clas/sub-directory trees.
#=============================================================================

HERE=`pwd`

CLASSPATH="$HERE;src"

cd src

echo "---> Build something"

javac something.java

cd ..

echo "---> Build main"

javac main.java

echo "---> Done"

