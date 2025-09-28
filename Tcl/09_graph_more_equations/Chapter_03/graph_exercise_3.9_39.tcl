#!/usr/bin/wish
# ************************************************************************
# FILE: graph_exercise_3.9_39.tcl
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
# But the problem is that each expression in 'y' gives two
# allowed values in 'x' ... 'x' and '-x'.  So the loop below
# must handle this.
#
# Also, not the following:
#
#    (a) y can't be 0
#
#    (b) I think there's an 'undefined' value
#        at y = -1
#
#        There may be others.  So I'm not sure
#        how to handle these in the 'loop'.
#
for { set y $min_y } { $y <= $max_y } { set y [expr $y + 0.001] } {

   set y3 [ expr ($y * $y * $y) ]
 
   set numerator [expr ( $y3 + 8 ) ]

   set x2 [ expr ( $numerator / $y ) ]

   if { $x2 > 0 } {

      set x [ tcl::mathfunc::sqrt [ expr ( $x2 ) ] ]

      set x1 [expr ($horiz_xi + ((($x - $min_x) / $rel_domain_dist) * $abs_domain_dist))]
      set y1 [expr ($vert_yi + (((($rel_range_dist / 2) - $y) / $rel_range_dist)  * $abs_range_dist))]

      set red_equation [.the_canvas create rectangle $x1 $y1 $x1 $y1 -width 0 -fill red]

      set x [ expr ( -$x ) ]

      set x1 [expr ($horiz_xi + ((($x - $min_x) / $rel_domain_dist) * $abs_domain_dist))]

      set green_equation [.the_canvas create rectangle $x1 $y1 $x1 $y1 -width 0 -fill green]

      #puts "---> ($x, $y) ==> pixels ($x1, $y1)"

   } else {

      puts "---> (sqrt($x2), $y) ==> UNDEFINED"

   }

}

for { set x $min_x } { $x <= $max_x } { set x [expr $x + 0.001] } {

   set y [ expr ( $x + 4 ) ]

   set x1 [expr ($horiz_xi + ((($x - $min_x) / $rel_domain_dist) * $abs_domain_dist))]
   set y1 [expr ($vert_yi + (((($rel_range_dist / 2) - $y) / $rel_range_dist)  * $abs_range_dist))]

   set mag_equation [.the_canvas create rectangle $x1 $y1 $x1 $y1 -width 0 -fill magenta]
}

button .exit -text "Exit" -command { exit }

grid .the_canvas -row 0 -column 0
grid .exit       -row 1 -column 0
