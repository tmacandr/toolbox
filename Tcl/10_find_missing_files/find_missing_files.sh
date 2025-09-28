#!/bin/sh
#=============================================================================
# FILE: find_missing_files.sh
#
# DESCRIPTION:
#    Script that traverses every file in a 'From' directory and tries to
#    find a match (i.e. duplicate) in a 'To' directory.  If a match is not
#    found, then the file from the 'From' directory' is COPIED to a tempory
#    directory where it can be manually merged into the 'To' directory.
#
#    Usage:
#
#       find_missing_files.sh <from-dir> <to-dir> <temp-dir>
#
#    Example:
#
#       find_missing_files.sh From_Dir/jpegs To_Dir/new  Temp_Dir
#
#=============================================================================

#===============================================
# FUNCTION: Show_Usage
#
# DESCRIPTION:
#    Invoked when invalid arg(s) are used.
#===============================================
Show_Usage()
{
   echo "***> ERROR - invalid argument(s)"
   echo "***>"
   echo "***> USAGE:"
   echo "***>    find_missing_files.sh <from-dir> <to-dir> <temp-dir>"
   echo "***> EXAMPLE:"
   echo "***>    find_missing_files.sh From_Dir To_Dir Temp_Dir"
   echo ""

   exit 1
}


if test $# -ne 3; then
   Show_Usage
fi

FROM_DIR=$1

TO_DIR=$2

TMP_DIR=$3


#===============================================
# FUNCTION: Check_Args 
#
# DESCRIPTION:
#    Verifies the specified directories are
#    valid.
#===============================================
Check_Args ()
{
   if test ! -d $FROM_DIR; then

      echo ""
      echo "***> ERROR - Source directory not found"
      echo "***>       - $FROM_DIR not found"
      echo ""

      Show_Usage

   fi

   if test ! -d $TO_DIR; then

      echo ""
      echo "***> ERROR - Destination directory not found"
      echo "***>       - $TO_DIR not found"
      echo ""

      Show_Usage

   fi

   if test ! -d $TMP_DIR; then

      echo ""
      echo "***> ERROR - Staging directory not found"
      echo "***>       - $TMP_DIR not found"
      echo ""

      Show_Usage

   fi
}


Check_Args

TMP_FILES_LIST=`ls -1R $FROM_DIR`

#
# Clean out any directory path markers '/'
#
FROM_FILES_LIST=`echo $TMP_FILES_LIST | sed 's/\// /g'`

TOTAL_COUNT=0

MATCH_COUNT=0

DIFF_COUNT=0

for i in $FROM_FILES_LIST; do

   echo "__________________________"
   echo "---> Check: $i"

   TOTAL_COUNT=$((TOTAL_COUNT + 1))

   FROM_FILE=`find $FROM_DIR -name $i -print`

   if test -z "$FROM_FILE"; then

      echo "---> Item $i not found - skip"

      continue

   fi

   #
   # Ug ... there could be more than one file
   # in the 'From' directory with the same name.
   #
   for j in $FROM_FILE; do

      echo "   ~~~~~~~~~~~~~~~~~~~~~~"
      echo "   ~~~> From file: $j"

      if test ! -f $j; then

         echo "   ~~~>    $j not a file - skip"

         continue

      fi

      FULL_FROM_INFO=`ls -l --time-style=full-iso $j`

      FROM_DATE_INFO=`echo $FULL_FROM_INFO | awk '{ print $6 }'`

      FROM_FILE_SIZE=`echo $FULL_FROM_INFO | awk '{ print $5 }'`

      TO_SAME_DATE_LIST=`ls -Rl --time-style=full-iso $TO_DIR | \
                         grep "$FROM_DATE_INFO"               | \
                         awk '{ print $9 }'`

      if test -z "$TO_SAME_DATE_LIST"; then

         echo "   ***> ATTENTION ATTENTION <***"
         echo "   ***>    File $i with date $FROM_DATE_INFO"
         echo "   ***>    not found in $TO_DIR"
         echo "   ***>    Must copy $j to $TMP_DIR"

         DIFF_COUNT=$((DIFF_COUNT + 1))

         #mv -b $j $TMP_DIR

         #
         # Very important "-p" keep timestamps, etc
         #
         cp -b -p $j $TMP_DIR

         echo "   ~~~~~~~~~~~~~~~~~~~~~~"

         continue

      fi

      #
      # File(s) with same date found.  Check size.
      #
      FOUND_MATCH=0

      for k in $TO_SAME_DATE_LIST; do

         echo "      +++++++++++++++++++++++"
         echo "      +++> Begin check $i for size match to: $k"

         TO_FILE_LIST=`find $TO_DIR -name $k -print`

         #
         # More ug ... could be more than one file
         # with the same name in different dirs.
         #
         for m in $TO_FILE_LIST; do

            echo "         ^^^^^^^^^^^^^^^^^^^^^^"
            echo "         ^^^> Check $i for size match to: $m"

            FULL_TO_INFO=`ls -l --time-style=full-iso $m`

            TO_FILE_SIZE=`echo $FULL_TO_INFO | awk '{ print $5 }'`

            if test $TO_FILE_SIZE -eq $FROM_FILE_SIZE; then 

               echo "         ^^^>    MATCH - date and size match"
               echo "         ^^^>    From: $j"
               echo "         ^^^>    To..: $m"

               #
               # Date and size match.  Are they truly different?
               #
               IS_DIFFERENT=`diff -q $m $j`

               if test -z "$IS_DIFFERENT"; then

                  echo "      ~~~>    Files are equal"
                  echo "      ~~~>    From: $j"
                  echo "      ~~~>    To..: $m"

                  FOUND_MATCH=1;

                  MATCH_COUNT=$((MATCH_COUNT + 1))

                  break

                  echo "         ^^^^^^^^^^^^^^^^^^^^^^"

               else

                  echo "***> WARNING WARNING <***"
                  echo "***> Files with same date and size but are different"
                  echo "***> From: $j"
                  echo "***> To..: $m"
                  echo "***>    Date...: $FROM_DATE_INFO"
                  echo "***>    Size...: $TO_FILE_SIZE"

               fi

            fi

            echo "         ^^^^^^^^^^^^^^^^^^^^^^"

         done

         if test $FOUND_MATCH -eq 1; then

            echo "      +++> Match was found - break"
            echo "      +++++++++++++++++++++++"

            break;

         fi

         echo "      +++> Continue search"
         echo "      +++++++++++++++++++++++"

      done

      if test $FOUND_MATCH -eq 0; then

         echo "   ***> ATTENTION"
         echo "   ***> No match found"
         echo "   ***> Move $j to $TMP_DIR"

         #mv -b $j $TMP_DIR

         #
         # Very important "-p" keep timestamps, etc
         #
         cp -b -p $j $TMP_DIR

         DIFF_COUNT=$((DIFF_COUNT + 1))

         continue

      else

         echo "---> $j matches $i"

      fi

      echo "   ~~~~~~~~~~~~~~~~~~~~~~"

   done

   echo "---> Match Count..: $MATCH_COUNT"
   echo "---> Diff Count...: $DIFF_COUNT"
   echo "__________________________"

done

echo "---> Total Count..: $TOTAL_COUNT"
echo "---> DONE"

