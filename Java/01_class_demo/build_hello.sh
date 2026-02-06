#!/bin/sh
# *****************************************************************
# *  FILE: build_hello.bat
# * 
# *  DESCRIPTION:
# *     This DOS batch program that Java compiles the "hello_world"
# *     program.
# ******************************************************************

export HERE=`pwd`

# ********************************************
# * Use ';' to add more directories, when needed
# ********************************************
set CLASSPATH=$HERE

export SRC=hello_world.java
export OBJ=hello_world.class

if test -e $OBJ; then

    echo "Delete old $OBJ"

    rm $OBJ

fi

javac $SRC

cd $HERE

echo "Done ..."
