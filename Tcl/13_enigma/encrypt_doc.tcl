#!C:/Tcl/bin/tclsh
# ************************************************************************
# FILE: encrypt_doc.tcl
#
# DESCRIPTION:
#    Tcl script that applies an 'enimga' cipher to the specified document.
#
#    The "wheel.txt" mimics the wheel used in the enigma machine to
#    encrypt a plain-text message.  In the "enigma" machine the wheel was 
#    three rolls of randomly manufactured character sequences.  Each
#    character typed would be mapped to one character on one of the
#    rolls.  The roll would advance and then the next character position
#    would move to the next roll, and then repeat.
#
#    The "key" to an enigma machine corresponded to the starting position
#    of each roll on the wheel.
#
#    Thus, the wheel used to encrypt a message must be the same as the
#    wheel on a machine to decrypt the message.  And the "key" used to
#    encrypt must be the same as used to decrypt the message.
#
#    Therefore, not only must a "key" be secret, but the wheels must also
#    be protected.
#
#    Nonetheless, the British were able to capture several Engima machines
#    from German U-boats.  Using several machines in parallel at the
#    Bletchley Park facilities, they were able to use a sort of brute-force
#    procedure to decrypt messages, sometimes in less than 24 hours.
#
#    Each character from a plain-text message was encrypted by 26 random
#    character positions from each of the three rolls on the wheel.  But
#    for this Tcl program each wheel is mimic'd by three sets of 256 random
#    (8-bit) numbers. 
#
#    The three 'keys' are the starting position of into each wheel (i.e
#    array).  After each character from the plaintext input, the wheel
#    position is simply incremented and used to encrypt the next character.
#
#    As with the "Enigma" machine, each character from the plain-text file
#    is encrypted from a value from a "wheel" (array) and the index advanced
#    to the next character in the "wheel".  When the bottom of the "wheel"
#    is reached, the index is set to the top.  After one character is
#    encrypted, the next wheel is selected to encrypt the next character.
#    After the third "wheel" is used, the next first "wheel" is then
#    selected to continue with the next encryption.
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
#    255 + 255 = 560, well smaller than 0xFFFF.  Thus, the results file
#    of encrypted data is unsigned short values.
#
#    USAGE:
#
#       Invokd via 'tclsh' (e.g. tclsh85)
# 
#   encrypt_doc.tcl <input-doc> <output-doc> <wheel> <key1> <key2> <key3>
#
#    EXAMPLE:
#
#   encrypt_doc.tcl plain.txt result.txt wheel.txt 17 182 13 
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
  puts "***>    encrypt_doc.tcl <input-doc> <output-doc> <key1> <key2> <key3>"
  puts "***> EXAMPLE:"
  puts "***>    encrypt_doc.tcl data.pdf result.txt 17 182 13"
}


set wheel_1 ""
set wheel_2 ""
set wheel_3 ""


# ***********************************************
# PROCEDURE NAME: load_wheel_file
#
# DESCRIPTION:
#    Opens the specified "wheel" file and sets
#    the global "wheel_0", "wheel_1", and "wheel_2"
#    arrays.
# ***********************************************
proc load_wheel_file { wheel_file_name } {

   puts "---> Load wheel file:"

   global wheel_1
   global wheel_2
   global wheel_3

   if { ! [file exists $wheel_file_name] } {
      puts "***> ERROR - File $wheel_file_name not found"
      exit
   }

   set wheel_fd [open "$wheel_file_name" rb]

   set next_value ""
   set start 0
   set len   256

   for { set i $start } { $i < $len } { incr i } {
      set s [gets $wheel_fd next_value]
      if { $s <= 0 } {
         puts "***> ERROR - Wheel 1 - EOF at $i"
         exit
      }
      set wheel_1 "$wheel_1$next_value "
   }

   set wheel_1 [split $wheel_1]

   set start $len
   set len [expr $len + 256 ]

   for { set i $start } { $i < $len } { incr i } {
      set s [gets $wheel_fd next_value]
      if { $s <= 0 } {
         puts "***> ERROR - Wheel 2 - EOF at $i"
         exit
      }
      set wheel_2 "$wheel_2$next_value "
   }

   set wheel_2 [split $wheel_2]

   set start $len
   set len [expr $len + 256 ]
 
   for { set i $start } { $i < $len } { incr i } {
      set s [gets $wheel_fd next_value]
      if { $s <= 0 } {
         puts "***> ERROR - Wheel 3 - EOF at $i"
         exit
      }
      set wheel_3 "$wheel_3$next_value "
   }

   set wheel_3 [split $wheel_3]

   #puts "---> Wheel 1:"
   #puts "$wheel_1"
   #puts "----------------------------------"

   #puts "---> Wheel 2:"
   #puts "$wheel_2"
   #puts "----------------------------------"

   #puts "---> Wheel 3:"
   #puts "$wheel_3"
   #puts "----------------------------------"

   close $wheel_fd 
}


# ***********************************************
# PROCEDURE NAME: encrypt_file
#
# DESCRIPTION:
#    Applies "enigma" cipher described in prolog
#    to the given 'tofile'.
# ***********************************************
proc encrypt_file { fromfile tofile key1 key2 key3 } {

   puts "---> Procedure: encrypt"
   puts "---> From....: $fromfile"
   puts "---> To......: $tofile"
   puts "---> Key1....: $key1"
   puts "---> Key2....: $key2"
   puts "---> Key3....: $key3"

   global wheel_1
   global wheel_2
   global wheel_3

   set from_fd [open "$fromfile" rb]

   set in_data [read $from_fd]

   set len [string length $in_data]

   puts "---> Num chars: $len"

   set out_data ""

   set nxt_wheel 1
   set offset    0

   for { set i 0 } { $i < $len } { incr i } {
       set plain_char [string index $in_data $i]

       scan $plain_char "%c" one_num

       #
       # e[i] = c[i] + wheel[j][Kj + i]
       #
       if { $nxt_wheel == 1 } {
          set offset [lindex $wheel_1 $key1]
          incr $nxt_wheel
          incr $key1
          if { $key1 > 255 } {
             set key1 0
          }
       } else {
          if { $nxt_wheel == 2 } {
             set offset [lindex $wheel_2 $key2]
             incr $nxt_wheel
             incr $key2
             if { $key2 > 255 } {
                set key2 0
             }
          } else {
             set offset [lindex $wheel_3 $key3]
             set nxt_wheel 1
             incr $key3 
             if { $key3 > 255 } {
                set key3 0
             }
          }
       }

       set encrypt [expr $one_num + $offset]

       puts "~~~>    $i) $plain_char to $one_num to $encrypt"

       set out_data "$out_data$encrypt "
   }

   set to_fd [open "$tofile" wb+]

   puts $to_fd "$out_data"

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

if { $argc != 6 } {

  show_usage

  exit
}

puts "---> Name of program..: $argv0"

set input_file  [lindex $argv 0]
set result_file [lindex $argv 1]
set wheel_file  [lindex $argv 2]
set key_1       [lindex $argv 3]
set key_2       [lindex $argv 4]
set key_3       [lindex $argv 5]

if { ! [file exists $input_file] } {
   puts "***> ERROR - File $input_file not found"
   exit
}

if { ! [file exists $wheel_file] } {
   puts "***> ERROR - File $wheel_file not found"
   exit
}

load_wheel_file $wheel_file

encrypt_file $input_file $result_file $key_1 $key_2 $key_3

puts "End - Encrypt Doc"

