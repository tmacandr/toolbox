#!/bin/bash
#----------------------------------------------------------------------
# File: buildAll.ksh
# Date: 04-Apr-00
#       23-Jan-26
#
# Description:
#    Script to compile/link the excercises for chapter 2 of
#    Stroustrup's "C++".
#----------------------------------------------------------------------

CC=g++

OPTS="-ggdb -Wall"

H_PATH="-I."

Files="main_2_1.cpp
       main_2_2.cpp
       main_2_3.cpp
       main_2_4.cpp
       main_2_5.cpp
       main_2_6.cpp
       main_2_7.cpp
       main_2_8.cpp
       main_2_10.cpp
       unix_test.cpp"

echo "________________________"

for eachFile in $Files; do

   EXE=`echo $eachFile | sed 's/\.cpp/\.exe/'`

   echo "---> Build $eachFile"
 
   $CC $OPTS $H_PATH $eachFile -o $EXE

   if ! test -x $EXE; then
      echo "Compile/Link $eachFile failed"

      break
   fi

done

