#!/usr/bin/wish
# ************************************************************************
# FILE: hello.tcl
#
# DESCRIPTION:
#    Tcl script that demos some features.
#
#    For other examples, see:
#
#      http://pages.cpsc.ucalgary.ca/~saul/personal/archives/ \
#           Tcl-Tk_stuff/tcl_examples/
#*************************************************************************

set count 0

# ***********************************************
# PROCEDURE NAME: some_procedure 
#
# DESCRIPTION:
#    A procedure in Tcl
# ***********************************************
proc some_procedure { label } {

   global count

   $label configure -text "count...: $count"

   set count [expr $count + 1]

}


# ***********************************************
# PROCEDURE NAME: main ... sort of ...
#
# DESCRIPTION:
#    Executing commands begins here ...
# ***********************************************
puts "Begin - hello Tcl"

label .msg -text "  "

pack .msg 

button .hello -text "Hello Tcl" -command "some_procedure .msg"

pack .hello

button .exit -text "Exit" -command { exit }

pack .exit

puts "End - hello Tcl"
