#!/usr/bin/wish
# ************************************************************************
# FILE: graph_exercise_4.1_26.tcl
#
# DESCRIPTION:
#    Tcl script to graph the equation from:
#       Section 4.1
#       Exercise 17
#
#       "Calculus with Analytic Geometry", E. W. Swokowski,
#       2nd Edition, 1979
#
#    For other examples, see:
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
set y_label [.the_canvas create text $vert_xi 40 -text "Y"]

set max_x  [expr 5.0 ]
set min_x  [expr -$max_x]

set rel_domain_dist [expr $max_x - $min_x]

set max_y [expr 15.0]
set min_y [expr -$max_y]

set rel_range_dist [expr $max_y - $min_y]

set abs_domain_dist [expr $horiz_xf - $horiz_xi]
set abs_range_dist  [expr $vert_yf - $vert_yi]

#
# Draw three cubic functions.  One with two critical numbers,
# one with one critical number, and one with no critical
# numbers.
#
# This has no critical numbers:
#
#            3    2
#    f(x) = x  + x + x + 1
#
for { set x $min_x } { $x <= $max_x } { set x [expr $x + 0.001] } {

   set x2 [ expr ($x * $x) ]

   set x3 [ expr ($x2 * $x) ]

   set y [expr ($x3 + $x2 + $x + 1)]

   set x1 [expr ($horiz_xi + ((($x - $min_x) / $rel_domain_dist) * $abs_domain_dist))]
   set y1 [expr ($vert_yi + (((($rel_range_dist / 2) - $y) / $rel_range_dist)  * $abs_range_dist))]

   set red_equation [.the_canvas create rectangle $x1 $y1 $x1 $y1 -width 0 -fill red ]

   #puts "---> ($x, $y) ==> pixels ($x1, $y1)"

}

# These have one critical number:
#
#            3     /--   2
#    f(x) = x  + \/ 3  x   + x + 1
#
#            3
#    f(x) = x
#

set root3 [::tcl::mathfunc::sqrt [expr 3.0] ]

for { set x $min_x } { $x <= $max_x } { set x [expr $x + 0.001] } {

   set x2 [ expr ($x * $x) ]

   set x3 [ expr ($x2 * $x) ]

   set y [expr ($x3 + $root3 * $x2 + $x + 1)]

   set x1 [expr ($horiz_xi + ((($x - $min_x) / $rel_domain_dist) * $abs_domain_dist))]
   set y1 [expr ($vert_yi + (((($rel_range_dist / 2) - $y) / $rel_range_dist)  * $abs_range_dist))]

   set green_equation [.the_canvas create rectangle $x1 $y1 $x1 $y1 -width 0 -fill green ]

   #puts "---> ($x, $y) ==> pixels ($x1, $y1)"

}

#
# This has two critical numbers:
#
#            3     2
#    f(x) = x  + 4x + 3x + 1
#
for { set x $min_x } { $x <= $max_x } { set x [expr $x + 0.001] } {

   set x2 [ expr ($x * $x) ]

   set x3 [ expr ($x2 * $x) ]

   set y [expr ($x3 + 4 * $x2 + 3 * $x + 1)]

   set x1 [expr ($horiz_xi + ((($x - $min_x) / $rel_domain_dist) * $abs_domain_dist))]
   set y1 [expr ($vert_yi + (((($rel_range_dist / 2) - $y) / $rel_range_dist)  * $abs_range_dist))]

   set blue_equation [.the_canvas create rectangle $x1 $y1 $x1 $y1 -width 0 -fill blue ]

   #puts "---> ($x, $y) ==> pixels ($x1, $y1)"

}

button .exit -text "Exit" -command { exit }

grid .the_canvas -row 0 -column 0
grid .exit       -row 1 -column 0
