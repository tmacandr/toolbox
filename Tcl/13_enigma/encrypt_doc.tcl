#!C:/Tcl/bin/tclsh
# ************************************************************************
# FILE: encrypt_doc.tcl
#
# DESCRIPTION:
#    Tcl script that applies an 'enimga' cipher to the specified document.
#
#    The "wheel.bin" mimics the wheel used in the enigma machine to
#    encrypt a plain-text message.  In the "enigma" machine the wheel would
#    encrypt three characters at a time.  But in that case, each position
#    was encrypted by 26 random character positions.  But for this
#    program each wheel is 256 random (8-bit) numbers. 
#
#    The three 'keys' are the starting position of each wheel.  After
#    each character from the plaintext input, the wheel position is
#    simply incremented and used to encrypt the next character.
#
#    As with the "enigma" machine, three characters are input from the
#    plain-text file and encrypted by each of the three "wheels" (of
#    256 characters).
#
#    The encryption equation is:
#
#       e[i] = c[i] + wheel[j][Kj + i]
#
#    where:
#       c[i] = ith plain-text character 
#       e[i] = ith encrypted number
#       j    = the jth wheel (0, 1, or 2)
#       Kj   = the key used to start the indexing into the jth wheel
#
#    Note that each e[i] written out to the results file is an unsigned
#    short (not an ASCII character).  Each character read from the
#    plain-text file is 0 .. 255.  And each value from any of the three
#    wheels is 0 .. 255.  So the maximum value calculated can be
#    255 + 255 = 260, well smaller than 0xFFFF.  Thus, the results file
#    of encrypted data is binary, unsigned short values.
#
#    The encryption (and decryption) will have the following "corner
#    cases" to consider:
#
#       If the input (plain-text) file:
#
#       (a) has exactly mod 3 characters, then no special
#           handling is performed.
#
#       (b) has one left over character, then the last 
#           two values will be 0xFFFF 0xFFFF.
#
#       (c) has two left over characters, then the last
#           value will be 0xFFFF.
#
#    USAGE:
#
#       Invokd via 'tclsh' (e.g. tclsh85)
# 
#   encrypt_doc.tcl <input-doc> <output-doc> <wheel> <key1> <key2> <key3>
#
#    EXAMPLE:
#
#   encrypt_doc.tcl plain.txt result.txt wheel.bin 17 182 13 
#
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

      set encrypt [expr $tmp + $key]

      if { $encrypt > 255 } {
         set encrypt [expr $encrypt - 256]
      }

      #puts "~~~>    $i) shift integer $tmp to $encrypt"

      set value [format %c $encrypt]

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

if { $argc != 4 } {

  show_usage

  exit
}

puts "---> Name of program..: $argv0"

set input_file  [lindex $argv 0]
set result_file [lindex $argv 1]
set wheel_file  [lindex $argv 2]
set key         [lindex $argv 3]

load_wheel_file $wheel_file

encrypt_file $input_file $result_file $key

puts "End - Encrypt Doc"

