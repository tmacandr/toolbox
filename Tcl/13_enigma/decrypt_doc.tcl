#!C:/Tcl/bin/tclsh
# ************************************************************************
# FILE: decrypt_doc.tcl
#
# DESCRIPTION:
#    Tcl script that decrypts a "enigma" cipher on the specified document.
#
#    See DESCRIPTION in 'encrypt_doc.tcl'.
#
#    USAGE:
#      tclsh85 decrypt_doc.tcl <input-doc> <output-doc> <wheel> <key>
#
#    EXAMPLE:
#      tclsh85 encrypt_doc.tcl from.txt result.txt wheel.txt 4
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
  puts "***>    decrypt_doc.tcl <input-doc> <output-doc> <wheel-doc> <key>"
  puts "***> EXAMPLE:"
  puts "***>    encrypt_doc.tcl from.txt result.txt wheel.txt 4"
}


set wheel_0 ""
set wheel_1 ""
set wheel_2 ""


# ***********************************************
# PROCEDURE NAME: load_wheel_file
#
# DESCRIPTION:
#    Opens the specified "wheel" file and sets
#    the global "wheel_0", "wheel_1", and "wheel_2"
#    arrays.
# ***********************************************
proc load_wheel_file{ wheel_file_name } {

  puts "---> Load wheel file - not implemented"
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

      if { $tmp < $key } {
         set decrypt [expr 255 + $tmp - $key + 1]
      } else {
         set decrypt [expr $tmp - $key]
      }

      #puts "~~~>    $i) shift integer $decrypt to $tmp"

      set value [format %c $decrypt]

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

if { $argc != 4 } {

  show_usage

  exit
}

puts "---> Name of program..: $argv0"

set input_file   [lindex $argv 0]
set results_file [lindex $argv 1]
set wheel_file   [lindex $argv 3]
set key          [lindex $argv 2]

load_wheel $wheel_file

decrypt_file $input_file $results_file $key

puts "End - Decrypt Doc"

