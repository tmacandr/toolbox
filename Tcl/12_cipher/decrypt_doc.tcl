#!C:/Tcl/bin/tclsh
# ************************************************************************
# FILE: decrypt_doc.tcl
#
# DESCRIPTION:
#    Tcl script that decrypts a Caesar cipher on the specified document.
#
#    USAGE:
#      tclsh85 decrypt_doc.tcl <input-doc> <output-doc> <key>
#
#    EXAMPLE:
#      tclsh85 encrypt_doc.tcl from.txt result.txt 4
#*************************************************************************


# ***********************************************
# PROCEDURE NAME: show_usage
#
# DESCRIPTION:
#    Invoked when wrong command-line args
#    are given.
# ***********************************************
proc show_usage { } {

  puts "***> ERROR - Invalid args"
  puts "***> USAGE:"
  puts "***>    decrypt_doc.tcl <input-doc> <output-doc> <key>"
  puts "***> EXAMPLE:"
  puts "***>    encrypt_doc.tcl from.txt result.txt 4"
}


# ***********************************************
# PROCEDURE NAME: decrypt_file
#
# DESCRIPTION:
#    Reverses Caesar cipher of <key> shift on the
#    specified file.
# ***********************************************
proc decrypt_file { fromfile tofile key } {

  puts "---> Procedure: encrypt"
  puts "---> From....: $fromfile"
  puts "---> To......: $tofile"
  puts "---> Key.....: $key"

  set from_fd [open "$fromfile" rb]

  set data [read $from_fd]

  set len [string length $data]

  puts "---> Num chars: $len"

  set shift ""

  for { set i 0 } { $i < $len } { incr i } {
      set c [string index $data $i]

      scan $c %c tmp

      #puts "---> $i) char $c to integer $tmp"

      if { $tmp <= $key } {
         set adjust [expr 255 + $tmp - $key]
         puts "+++> Back condition: from $tmp to $adjust"
         set decrypt $adjust
      } else {
         set decrypt [expr $tmp - $key]
      }

      puts "~~~>    shift integer $decrypt to $tmp"

      set value [format %c $decrypt]

      #puts "---> $i) char $c is now char $value"

      set shift "$shift$value"
  }

  set to_fd [open "$tofile" wb+]

  puts $to_fd "$shift"

  close $to_fd

  close $from_fd
}


# ***********************************************
# PROCEDURE NAME: main ... sort of ...
#
# DESCRIPTION:
#    Executing commands begins here ...
# ***********************************************
puts "Begin - Decrypt Doc"

if { $argc != 3 } {

  show_usage

  exit
}

puts "---> Name of program..: $argv0"

set input_file  [lindex $argv 0]
set results_file [lindex $argv 1]
set key          [lindex $argv 2]

decrypt_file $input_file $results_file $key

puts "End - Decrypt Doc"

