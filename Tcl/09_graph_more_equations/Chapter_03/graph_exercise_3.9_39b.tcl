#!/usr/bin/wish
# ************************************************************************
# FILE: graph_exercise_3.9_39b.tcl
#
# DESCRIPTION:
#    Tcl script to graph the equation from:
#       Section 3.9
#       Exercise 39
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

set max_x  [expr 10.0 ]
set min_x  [expr -$max_x]

set rel_domain_dist [expr $max_x - $min_x]

set max_y [expr 10.0]
set min_y [expr -$max_y]

set rel_range_dist [expr $max_y - $min_y]

set abs_domain_dist [expr $horiz_xf - $horiz_xi]
set abs_range_dist  [expr $vert_yf - $vert_yi]

#
# Equation given for 3.9_39 is:
#
#     2      3
#    x  y - y  = 8
#
# The 'goal' was to force an implicit differentiation on y.
# So an expression in y = f(x) can't be obtained ... the
# equation is 'recursive' in y.
#
# But solving for x gives:
#
#           3
#     2    y  + 8
#    x  = --------
#             y
#
# So a graph based on x = g(y) is made where the 'independent'
# variable will now be 'y'.
#
# But what I got in 3.9_39 is confusing ... it looks 'not right'.
#
# So, in this case, the following will be graphed:
#
#           3
#     2    x  + 8
#    y  = --------
#             x
#
#
#                   ----------
#         +        /  3
#         -       /  x  + 8
#    y  =    -   /  --------
#              \/       x
#
# So, graph as (x, y) but reversing the independent/dependent
# variables ... and them (mentally) rotate it 90 degrees.
#
for { set x $min_x } { $x <= $max_x } { set x [expr $x + 0.001] } {

   set x3 [ expr ($x * $x * $x) ]
 
   set numerator [expr ( $x3 + 8 ) ]

   set temp_y [ expr ( $numerator / $x ) ]

   set x1 [expr ($horiz_xi + ((($x - $min_x) / $rel_domain_dist) * $abs_domain_dist))]

   if { $temp_y > 0 } {

      set y [ tcl::mathfunc::sqrt [ expr ( $temp_y ) ] ]

      set y1 [expr ($vert_yi + (((($rel_range_dist / 2) - $y) / $rel_range_dist)  * $abs_range_dist))]

      set red_equation [.the_canvas create rectangle $x1 $y1 $x1 $y1 -width 0 -fill red]

      set y [ expr ( -$y ) ]

      set y1 [expr ($vert_yi + (((($rel_range_dist / 2) - $y) / $rel_range_dist)  * $abs_range_dist))]

      set green_equation [.the_canvas create rectangle $x1 $y1 $x1 $y1 -width 0 -fill green]

      #puts "---> ($x, $y) ==> pixels ($x1, $y1)"

   } else {

      puts "---> ($x, UNDEFINED)"

      set y 0.0

      set y1 [expr ($vert_yi + (((($rel_range_dist / 2) - $y) / $rel_range_dist)  * $abs_range_dist))]

      set yellow_equation [.the_canvas create rectangle $x1 $y1 $x1 $y1 -width 0 -fill yellow]

   }

}

button .exit -text "Exit" -command { exit }

grid .the_canvas -row 0 -column 0
grid .exit       -row 1 -column 0
