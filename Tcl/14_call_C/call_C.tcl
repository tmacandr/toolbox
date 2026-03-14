#!C:/Tcl/bin/tclsh
# ************************************************************************
# FILE: call_C.tcl
#
# DESCRIPTION:
#    Tcl script that demos how to call C functions from a .a library.
#*************************************************************************


# ***********************************************
# PROCEDURE NAME: some_procedure 
#
# DESCRIPTION:
#    A procedure in Tcl
# ***********************************************
proc some_procedure { first_arg second_arg } {

   puts "---> Proedure: some_procedure"
   puts "---> Arg 1...: $first_arg"
   puts "---> Arg 2...: $second_arg"
}


# ***********************************************
# PROCEDURE NAME: main ... sort of ...
#
# DESCRIPTION:
#    Executing commands begins here ...
# ***********************************************
puts "Begin - hello Tcl"

load lib/libc_func[info sharedlibextension]

set answer [get_integer 123 456 789]

puts "Integer answer: $answer"

set answer [get_float 3.14 2.718 10.0]

puts "Float answer: $answer"

set answer [get_string 1 3.1 "blah"]

puts "String answer: $answer"

for { set i 0 } { $i < 10 } { incr i } {

   puts "---> i = $i"

}

some_procedure hello Tcl

puts "End - hello Tcl"

# EOF

