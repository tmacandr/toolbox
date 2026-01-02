#!C:/Tcl/bin/tclsh
# ************************************************************************
# FILE: encrypt_doc.tcl
#
# DESCRIPTION:
#    Tcl script that applies a Caesar cipher to the specified document.
#
#    USAGE:
#      tclsh85 encrypt_doc.tcl <input-doc> <output-doc> <key>
#
#    EXAMPLE:
#      tclsh85 encrypt_doc.tcl data.pdf result.txt 4
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
  puts "***>    encrypt_doc.tcl <input-doc> <output-doc> <key>"
  puts "***> EXAMPLE:"
  puts "***>    encrypt_doc.tcl data.pdf result.txt 4"
}


# ***********************************************
# PROCEDURE NAME: encrypt_file
#
# DESCRIPTION:
#    Applies Caesar cipher of <key> shift on the
#    specified file
# ***********************************************
proc encrypt_file { fromfile tofile key } {

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

      #puts "________________________________"
      #puts "---> $i) char $c to integer $tmp"

      set encrypt [expr $tmp + $key]

      if { $encrypt > 255 } {
         set adjust [expr $encrypt - 255]

         puts "+++> Wrap condition: from $tmp to $encrypt to $adjust"

         set encrypt $adjust
      }

      puts "~~~>    shift integer $tmp to $encrypt"

      set value [format %c $encrypt]

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
puts "Begin - Encrypt Doc"

if { $argc != 3 } {

  show_usage

  exit
}

puts "---> Name of program..: $argv0"

set input_file  [lindex $argv 0]
set result_file [lindex $argv 1]
set key        [lindex $argv 2]

encrypt_file $input_file $result_file $key

puts "End - Encrypt Doc"

