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

   set wheel_fd [open "$wheel_file_name" rb+]

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
# PROCEDURE NAME: decrypt_file
#
# DESCRIPTION:
#    Applies a reverse of the "enigma" cipher to
#    the given encrypted file to return it to
#    plain text.
# ***********************************************
proc decrypt_file { fromfile tofile key1 key2 key3 } {

   puts "---> Procedure: decrypyt"
   puts "---> From....: $fromfile"
   puts "---> To......: $tofile"
   puts "---> Key1....: $key1"
   puts "---> Key2....: $key2"
   puts "---> Key3....: $key3"

   global wheel_1
   global wheel_2
   global wheel_3

   set from_fd [open $fromfile r]

   set in_bytes [read $from_fd]

   set len [string length $in_bytes]

   close $from_fd

   puts "---> Num bytes: $len"
   puts "---> in_bytes: $in_bytes"

   set in_data [split $in_bytes]

   set out_data ""

   set nxt_wheel 1
   set offset    0

   set len [string length $in_data]

   for { set i 0 } { $i < $len } { incr i } {
       set encrypt [lindex $in_data $i]

       puts "---> nxt num: $encrypt"

       #
       # c[i] = e[i] - wheel[j][Kj + i]
       #
       if { $nxt_wheel == 1 } {
          set offset [string index $wheel_1 $key1]
          incr $nxt_wheel
          incr $key1
          if { $key1 > 255 } {
             set key1 0
          }
       } else {
          if { $nxt_wheel == 2 } {
             set offset [string index $wheel_2 $key2]
             incr $nxt_wheel
             incr $key2
             if { $key2 > 255 } {
                set key2 0
             }
          } else {
             set offset [string index $wheel_3 $key3]
             set nxt_wheel 1
             incr $key3
             if { $key3 > 255 } {
                set key3 0
             }
          }
       }

       set plain_num [expr $encrypt - $offset]

       if { $plain_num < 0 } {
          puts "***> ERROR - Value $plain_num is NOT valid"
          break
          #exit
       }

       if { $plain_num > 255 } {
          puts "***> ERROR - Value $plain_num is not a valid char"
          exit
       }

       set plain_char [format %c $plain_num]

       puts "~~~>    $i) $encrypt to $plain_num to $plain_char"

       set out_data "$out_data$plain_char"
   }

   set to_fd [open "$tofile" wb+]

   puts $to_fd "$out_data"

   close $to_fd
}


# ***********************************************
# PROCEDURE NAME: main ... sort of ...
#
# DESCRIPTION:
#    Executing commands begins here ...
# ***********************************************
puts "Begin - Decrypt Doc"

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

decrypt_file $input_file $result_file $key_1 $key_2 $key_3

puts "End - Decrypt Doc"

