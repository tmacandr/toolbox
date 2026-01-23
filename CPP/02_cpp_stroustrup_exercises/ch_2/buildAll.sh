#!/bin/ksh
#----------------------------------------------------------------------
# File: buildAll.ksh
# Date: 04-Apr-00
#
# Description:
#    Script that uses the SUNWspro C++ compiler to compile and
#    link the excercises for chapter 2.
#----------------------------------------------------------------------

export SUNSPRO=/opt/cots/SUNWspro

export SUN_CPP=$SUNSPRO/bin/CC

export CPP=$SUN_CPP;

#export CC=$SUNSPRO/bin/cc;

export Base=$HOME/CPP_dir/hello_world

export Src=$Base/source

export SUN_H_PATH="-I$SUNSPRO/SC4.2/include/CC
                   -I$SUNSPRO/SC4.2/include/cc";

export H_PATH="$SUN_H_PATH
               -I/opt/cots/local/include
               -I/project/cots/simpact/v2.0/freeway/include
               -I$Base/include";

export OPTIONS=""

export Files=`ls *.cpp`;

echo "________________________";

for eachFile in $Files; do

   export Temp=`echo $eachFile | sed 's/\.cpp//'`;

   export Exe=$Temp.exe;

   echo "---> Build $eachFile";
 
   $CPP $OPTIONS $H_PATH $eachFile -o $Exe;

   if ! test -x $Exe; then

      echo "Compile/Link failed";

   fi

done

