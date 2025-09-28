#!/usr/bin/wish
# ************************************************************************
# FILE: simple_graphics.tcl
#
# DESCRIPTION:
#    Tcl script that demos some graphics features.
#
#    For other examples, see:
#
#      http://pages.cpsc.ucalgary.ca/~saul/personal/archives/ \
#           Tcl-Tk_stuff/tcl_examples/
#
#    Tcl/Tk does not support JPEG by default.  Needs extensions?
#    switched to GIF.
#*************************************************************************

package require Tk
#package require Img

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

button .hello -text "Hello Tcl" -command "some_procedure .msg"

button .exit -text "Exit" -command { exit }

canvas .the_canvas -width 250 -height 100

set orange_oval [.the_canvas create oval 0 0 50 50 -fill orange]
set blue_line [.the_canvas create line 50 50 100 100 -fill blue -width 2]

set gif_image [image create photo -file tcpip_arch.gif ]

label .volcano_img -image $gif_image -bd 1 -relief sunken

grid .the_canvas  -row 0 -column 0
grid .msg         -row 1 -column 0
grid .hello       -row 1 -column 1
grid .exit        -row 2 -column 0
grid .volcano_img -row 3 -column 0

puts "End - hello Tcl"

