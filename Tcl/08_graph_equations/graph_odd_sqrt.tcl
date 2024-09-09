#!/usr/bin/wish
# ************************************************************************
# FILE: simple_graphics.tcl
#
# DESCRIPTION:
#    Tcl script that graphs the equation:
#                     ______
#              4 - \/16 + h
#          y = --------------
#                   h
#
#    This is a 'Exercise' from "Calculus with Analytic Geometry", by
#    E. W. Swokowski.  Chapter 2, Section 2.3.
#
#    For more Tcl examples see:
#
#      http://pages.cpsc.ucalgary.ca/~saul/personal/archives/ \
#           Tcl-Tk_stuff/tcl_examples/
#*************************************************************************


# ***********************************************
# PROCEDURE NAME: main ... sort of ...
#
# DESCRIPTION:
#    Executing commands begins here ...
# ***********************************************
set width 500
set height 500

canvas .the_canvas -width $width -height $height

pack .the_canvas

set horiz_xi 50
set horiz_yi 250

set horiz_xf 450
set horiz_yf 250

set x_axis [.the_canvas create line $horiz_xi $horiz_yi $horiz_xf $horiz_yf -fill blue -width 1]
set x_label [.the_canvas create text 455 $horiz_yf -text "X"]

set vert_xi 250
set vert_yi 50

set vert_xf 250
set vert_yf 450

set y_axis [.the_canvas create line $vert_xi $vert_yi $vert_xf $vert_yf -fill blue -width 1]
set y_label [.the_canvas create text $vert_xi 45 -text "Y"]

set pi     [expr 3.14159]
set max_x  [expr 16.0 ]
set max_x  [expr 0.00005 ]
set min_x  [expr -$max_x]

set rel_domain_dist [expr $max_x - $min_x]

set max_y [expr 0.5]
set min_y [expr -$max_y]

set rel_range_dist [expr $max_y - $min_y]

set abs_domain_dist [expr $horiz_xf - $horiz_xi]
set abs_range_dist  [expr $vert_yf - $vert_yi]

for { set x $min_x } { $x <= $max_x } { set x [expr $x + 0.0000001] } {

   #
   # Draw:
   #                     ______
   #              4 - \/16 + h
   #          y = ------------
   #                   h
   #
   set y [ tcl::mathfunc::sqrt [ expr { 16 + $x } ] ]
   set y [expr 4 - $y ]
   set y [expr $y / $x ]

   set x1 [expr ($horiz_xi + ((($x - $min_x) / $rel_domain_dist) * $abs_domain_dist))]
   set y1 [expr ($vert_yi + (((($rel_range_dist / 2) - $y) / $rel_range_dist)  * $abs_range_dist))]

   if { [expr ($x > 0.0) ] } {

      set red_equation [.the_canvas create rectangle $x1 $y1 $x1 $y1 -width 0 -fill red]
      #puts "---> ($x, $y) ==> pixels ($x1, $y1)"

   } else {

      puts "---> ($x, $y) "

      set blue_equation [.the_canvas create rectangle $x1 $y1 $x1 $y1 -width 0 -fill blue]
   }

} 

button .exit -text "Exit" -command { exit }

grid .the_canvas -row 0 -column 0
grid .exit       -row 1 -column 0
