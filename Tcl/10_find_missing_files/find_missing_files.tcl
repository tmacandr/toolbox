#!C:/Tcl/bin/tclsh
#=============================================================================
# FILE: find_missing_files.tcl
#
# DESCRIPTION:
#    Script that traverses every file in a 'From' directory and tries to
#    find a match (i.e. duplicate) in a 'To' directory.  If a match is not
#    found, then the file from the 'From' directory' is COPIED to a tempory
#    directory where it can be manually merged into the 'To' directory.
#
#    Usage:
#
#       find_missing_files.tcl <from-dir> <to-dir> <temp-dir>
#
#    Example:
#
#       find_missing_files.tcl From_Dir/jpegs To_Dir/new  Temp_Dir
#
#=============================================================================

#===============================================
# FUNCTION: Show_Usage
#
# DESCRIPTION:
#    Invoked when invalid arg(s) are used.
#===============================================
proc Show_Usage { } {

   puts "***> ERROR - invalid argument(s)"
   puts "***>"
   puts "***> USAGE:"
   puts "***>    find_missing_files.sh <from-dir> <to-dir> <temp-dir>"
   puts "***> EXAMPLE:"
   puts "***>    find_missing_files.sh From_Dir To_Dir Temp_Dir"
   puts ""

   exit 1
}


#===============================================
# FUNCTION: Check_Args 
#
# DESCRIPTION:
#    Verifies the specified directories are
#    valid.
#===============================================
proc Check_Args { From_Dir To_Dir Tmp_Dir } {

   set is_dir [file isdirectory $From_Dir]

   if { $is_dir == 0 } {

      puts ""
      puts "***> ERROR - Source directory not found"
      puts "***>       - $From_Dir not found"
      puts ""

      Show_Usage

   }

   set is_dir [file isdirectory $To_Dir]

   if { $is_dir == 0 } {

      puts ""
      puts "***> ERROR - Destination directory not found"
      puts "***>       - $To_Dir not found"
      puts ""

      Show_Usage

   }

   set is_dir [file isdirectory $Tmp_Dir]

   if { $is_dir == 0 } {

      puts ""
      puts "***> ERROR - Staging directory not found"
      puts "***>       - $Tmp_Dir not found"
      puts ""

      Show_Usage

   }
}


#===============================================
# FUNCTION: Run_Diff_Script
#
# DESCRIPTION:
#    Invokes the DOS batch script 'do_diff.bat',
#    which in turn runs the tool 'Beyond Compare'
#    against the two specified files.
#
#    See:
#      C:\Program Files (x86)\Beyond Compare 3\BCompare.exe
#    Run -help for invoking command-line.
#
#    Tool returns:
#       1  : Files are binary equal
#       11 : Files are binary different
#
#    Script returns:
#       "Binary Diff: <num>"
#===============================================
proc Run_Diff_Script { Left Right } {

   #regsub -all "^" $Left "\"" Tmp_Left

   #regsub -all "$" $Tmp_Left "\"" Left

   #regsub -all "^" $Right "\"" Tmp_Right

   #regsub -all "$" $Tmp_Right "\"" Right

   exec cmd.exe /c "echo $Left  > left.txt"

   exec cmd.exe /c "echo $Right > right.txt"

   set RESULT [ exec do_diff.bat ]

   set ANSWER [lindex $RESULT 2]

   return $ANSWER
}


#===============================================
# FUNCTION: Get_Num_Strings_In_List
#
# DESCRIPTION:
#    Uses 'llength' to count the number of
#    strings in the given 'List'.
#===============================================
proc Get_Num_Strings_In_List { List } {

   set len [llength $List]

   return $len
}


#===============================================
# FUNCTION: Safe_Copy_File
#
# DESCRIPTION:
#    Copies the specified file to the specified
#    directory.  If there is already a file
#    with the same name in the destination
#    directory, then this function will append
#    a count to the name of the given file so
#    there are no collisions.
#===============================================
proc Safe_Copy_File { File_Name Full_Path_Name To_Dir } {

   set To_File_Name $File_Name

   set Full_To "$To_Dir/$To_File_Name"

   set File_Exists [file isfile $Full_To]

   set COUNT 0

   while { $File_Exists == 1 } {

       puts "      ~~~> File '$To_File_Name' exists in '$To_Dir'"

       set To_File_Name ""

       append To_File_Name "$File_Name" "_$COUNT"

       puts "      ~~~> Attempt: $To_File_Name"

       set Full_To "$To_Dir/$To_File_Name"

       set File_Exists [file isfile $Full_To]

       set COUNT [ expr ($COUNT + 1) ]
   }

   puts "   +++> Copy:"
   puts "   +++> From: $Full_Path_Name"
   puts "   +++> To..: $Full_To"

   set STAT [ file copy $Full_Path_Name $Full_To ]

   puts "RESULT: $STAT"
}


#===============================================
# FUNCTION: Search_For_File_Match
#
# DESCRIPTION:
#    Loops over the given 'To_Files_List' to
#    find a match to the given 'From_File'.
#    The search is, for each file in the
#    'To_Files_List':
#
#       (a) Find any file from the 'To'
#           list with the same specified
#           'Date' ... and ...
#
#       (b) If the size of the files
#           are the same ... and ...
#
#       (c) If (BeyondCompare) diff is
#           the same ...
#
#    then return 1 (match found) ... otherwise,
#    if no match is found, then return 0.
#
# RETURN:
#    0 : no match found
#    1 : match found
#===============================================
proc Search_For_File_Match { To_Files_List From_File_Name From_Date_Info From_File_Size } {

   puts "   ~~~~~~~~~~~~~~~~~~~~~~"

   set MATCH_FOUND 0

   foreach j $To_Files_List {

      puts "   ________________________________"
      puts "   ~~~> Next To File: $j"

      #
      # Verify that the file actually 'exists' ... and
      # is not a directory ... or worse ... that it's
      # some sort of conglomeration of jack-ass
      # characters like (c) copyright ... (r) registered-
      # trade-mark ... that Windows allows ... but makes
      # the Tcl file I/O tools puke.
      #
      set is_file [file isfile $j]

      if { $is_file == 0 } {

         #
         # big problem here ... if it's not a diretory
         # then assume it's some sort of jack-ass file
         # that I copied over from something like 'job'
         # records and contains
         # jack-ass Windows characters ... and I won't
         # miss it if it doesn't get copied over.
         #
         # If it's a so-named file that I created ... then
         # "ug!" on me.
         #
         # skip ...
         #
         continue;

      }

      set TO_FILE_NAME [file tail $j]

      set TO_DATE_INFO [file mtime $j]

      if { "$TO_DATE_INFO" != "$From_Date_Info" } {

          #
          # dates don't match
          #
          continue
      }

      set TO_FILE_SIZE [file size $j]

      puts "   ~~~> To Size: $TO_FILE_SIZE"

      if { $From_File_Size ne $TO_FILE_SIZE } {

          #
          # sizes don't match
          #
          continue
      }

      #
      # Date and size match.  Are they truly different?
      #
      #
      # Back to DOS
      #
      regsub -all "\/" $From_File_Name "\\\\" DOS_FROM_FILE_NAME

      regsub -all "\/" $j "\\\\" DOS_TO_FILE_NAME

      puts "---> Do DIFF"
      puts "---> Left.: $DOS_FROM_FILE_NAME"
      puts "---> Right: $DOS_TO_FILE_NAME"

      set DIFF_STATUS [ Run_Diff_Script "$DOS_FROM_FILE_NAME" "$DOS_TO_FILE_NAME" ]

      if { $DIFF_STATUS eq 1 } {

         puts "      ~~~>    Files are equal"
         puts "      ~~~>    From: $DOS_FROM_FILE_NAME"
         puts "      ~~~>    To..: $DOS_TO_FILE_NAME"

         set MATCH_FOUND 1

         break

      } else {

         puts "   ***> WARNING WARNING <***"
         puts "   ***> Files with same date and size but are binary different"
         puts "   ***> From: $From_File_Name"
         puts "   ***> To..: $DOS_TO_FILE_NAME"
         puts "   ***>    Date...: $From_Date_Info"
         puts "   ***>    Size...: $From_File_Size"
         puts "   ***>    Diff...: $DIFF_STATUS"

      }
   }

   puts "   ~~~~~~~~~~~~~~~~~~~~~~"

   return $MATCH_FOUND
}


if { $argc ne 3 } {

   Show_Usage

}

set FROM_DIR [lindex $argv 0]

set TO_DIR   [lindex $argv 1]

set TMP_DIR  [lindex $argv 2]

puts "---> Check args"

Check_Args $FROM_DIR $TO_DIR $TMP_DIR

set FROM_FILES_LIST [ exec cmd.exe /c "dir /b /s $FROM_DIR" ]

#
# Replace all DOS "\" directory separators with
# UNIX separators "/"
#
regsub -all "\\\\" $FROM_FILES_LIST "\/" TEMP_DATA

set FROM_FILES_LIST $TEMP_DATA

regsub -all "^" $FROM_FILES_LIST "\"" FROM_FILES_LIST

regsub -all "\n" $FROM_FILES_LIST "\"\n\"" FROM_FILES_LIST

regsub -all "$" $FROM_FILES_LIST "\"" FROM_FILES_LIST

set TO_FILES_LIST [ exec cmd.exe /c "dir /b /s $TO_DIR" ]

#
# Replace all DOS "\" directory separators with
# UNIX separators "/"
#
regsub -all "\\\\" $TO_FILES_LIST "\/" TEMP_DATA

set TO_FILES_LIST $TEMP_DATA

regsub -all "^" $TO_FILES_LIST "\"" TO_FILES_LIST

regsub -all "\n" $TO_FILES_LIST "\"\n\"" TO_FILES_LIST

regsub -all "$" $TO_FILES_LIST "\"" TO_FILES_LIST

set NUM_FROM_ITEMS [Get_Num_Strings_In_List $FROM_FILES_LIST]

puts "+++> From Count: $NUM_FROM_ITEMS"

set NUM_TO_ITEMS [Get_Num_Strings_In_List $TO_FILES_LIST]

puts "+++> To Count..: $NUM_TO_ITEMS"

#
# Replace all DOS "\" directory separators with
# UNIX separators "/"
#
regsub -all "\\\\" $TMP_DIR "\/" TEMP_DATA

set TMP_DIR $TEMP_DATA

set MATCH_COUNT 0

set DIFF_COUNT  0

set TOTAL_COUNT 0

#puts "FROM LIST:"
#puts "-------------------------------------"
#puts "$FROM_FILES_LIST"

#puts "TO LIST:"
#puts "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
#puts "$TO_FILES_LIST"

foreach i $FROM_FILES_LIST {

   puts "__________________________"
   puts "---> Nxt: $i"

   set is_file [file isfile $i]

   if { $is_file == 0 } {

      #
      # Assume directory and skip.
      #
      # But could be some weird named
      # file.  This could be a 'miss'.
      #
      continue

   }

   set TOTAL_COUNT [ expr ($TOTAL_COUNT + 1) ]

   set FROM_FILE_NAME [file tail $i]

   set FROM_DATE_INFO [file mtime $i]

   set FROM_FILE_SIZE [file size $i]

   set MATCH_FOUND [ Search_For_File_Match $TO_FILES_LIST $i $FROM_DATE_INFO $FROM_FILE_SIZE ]

   if { $MATCH_FOUND eq 0 } {

      puts "   ***> ATTENTION"
      puts "   ***> No match found"
      puts "   ***> Copy:"
      puts "   ***>    From: $i"
      puts "   ***>    To..: $TMP_DIR"

      Safe_Copy_File $FROM_FILE_NAME $i $TMP_DIR

      set DIFF_COUNT [expr ($DIFF_COUNT + 1)]

   } else {

      puts "---> Found match for: $i"

      set MATCH_COUNT [expr ($MATCH_COUNT + 1) ]

   }

   puts "---> Match Count..: $MATCH_COUNT"
   puts "---> Diff Count...: $DIFF_COUNT"
   puts "__________________________"

}

puts "---> Total Count..: $TOTAL_COUNT"
puts "---> DONE"
