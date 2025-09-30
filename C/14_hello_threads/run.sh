#!/bin/bash
# =============================================================================
# FILE: run.sh
#
# DESCRIPTION:
#    Bourne shell script to run the 'hello_threads' program.  This script
#    counts the number of CPUs defined in the file:
#
#                 /proc/cpuinfo
#
#    and passes that to the program as a command-line-argument.
#
# COPYRIGHT
#    (c) Raytheon Company 2010
#    All rights reserved
# =============================================================================

export CPU_FILE=/proc/cpuinfo

if test -e $CPU_FILE; then

   export NUM_CPUs=`cat $CPU_FILE | grep "processor" | wc -l`

   for ((cpu_id=0; cpu_id < $NUM_CPUs; cpu_id++)); do

      echo "---> to CPU $cpu_id"

      hello_threads.exe $cpu_id $NUM_CPUs &

   done

else

   echo "***> ERROR: file '$CPU_FILE' not found"
   echo "***> Unable to determine number of CPUs"

fi

