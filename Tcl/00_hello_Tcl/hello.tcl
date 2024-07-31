#!C:/Tcl/bin/tclsh
# ************************************************************************
# FILE: hello.tcl
#
# DESCRIPTION:
#    Tcl script that demos some features.
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


for { set i 0 } { $i < 10 } { incr i } {

   puts "---> i = $i"

}

some_procedure hello Tcl

puts "End - hello Tcl"
