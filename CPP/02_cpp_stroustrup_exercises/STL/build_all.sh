#!/bin/bash
#----------------------------------------------------------------------
# File: buildAll.ksh
# Date: 04-Apr-00 : initial definition
#       30-May-00 : point to SUNWspro 5.0 compiler
#       23-Jan-26 : Point to Linux g++
#
# Description:
#    Script that builds uses the SUNWspro C++ compiler each of the
#    demos of the Standard-Template-Library (STL).
#----------------------------------------------------------------------

CC=g++

OPTS="-ggdb -Wall"

INCL_PATH="-I."

Files="deque_test.cpp     \
       iostream_test.cpp  \
       list_test.cpp      \
       map_test.cpp       \
       string_test.cpp"

echo "________________________"

for eachFile in $Files; do

   EXE=`echo $eachFile | sed 's/\.cpp/\.exe/'`

   echo "---> Build $eachFile"
 
   $CC $OPTS $H_PATH $eachFile -o $EXE

   if ! test -x $EXE; then

      echo "Compile/Link $eachFile failed"

   fi

done

