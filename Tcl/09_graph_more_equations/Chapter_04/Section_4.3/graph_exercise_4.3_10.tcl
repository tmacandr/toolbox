#!/usr/bin/wish
# ************************************************************************
# FILE: graph_exercise_4.3_10.tcl
#
# DESCRIPTION:
#    Tcl script that demos some graphics features.
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

set max_x  [expr 8.0 ]
set min_x  [expr -$max_x]

set rel_domain_dist [expr $max_x - $min_x]

set max_y [expr 9.0]
set min_y [expr -$max_y]

set rel_range_dist [expr $max_y - $min_y]

set abs_domain_dist [expr $horiz_xf - $horiz_xi]
set abs_range_dist  [expr $vert_yf - $vert_yi]

set is_first_y 1

set previous_y [expr 0.0]


# ***********************************************
# PROCEDURE NAME: check_for_x_zero
#
# DESCRIPTION:
#    Determines if the x-axis has just been crossed
#    for the current y value verses the previous
#    y-valu.  This is a 'zero' of the function
#    being graphed.
# ***********************************************
proc check_for_x_zero { x y pixel_x pixel_y } {

   global is_first_y
   global previous_y
   global the_canvas
   global width
   global height

   if { $is_first_y == 1 } {

      set is_first_y 0

      set previous_y [expr $y]

      set label [ format "%1.2f" $x ]

      set x_label [.the_canvas create text 15 10 -text "$label"]

      return
   }

   if { $previous_y < 0.0 } {

      if { $y > 0.0 } {

         puts "---> Zero: $x )"

         set previous_y [expr $y]

         set label [ format "%1.2f" $x ]

         set y_offset [ expr ($pixel_y - 3) ]

         set marker2 [.the_canvas create text $pixel_x $y_offset -text "$label"]
      }

   } else {

      #
      # $previous_y > 0.0
      #
      if { $y < 0.0 } {

         puts "---> Zero: $x )"

         set previous_y $y

         set label [ format "%1.2f" $x ]

         set y_offset [ expr ($pixel_y - 3) ]

         set marker2 [.the_canvas create text $pixel_x $y_offset -text "$label"]
      }

   }
}


# ***********************************************
# PROCEDURE NAME: draw_box
#
# DESCRIPTION:
#    Draws a box around the cartesian grid.
# ***********************************************
proc draw_box { the_canvas  w  h } {

   set black_box [.the_canvas create line 2  2  $w 2  -fill black -width 1 ]
   set black_box [.the_canvas create line 2  2  2  $h -fill black -width 1 ]
   set black_box [.the_canvas create line $w 2  $w $h -fill black -width 1 ]
   set black_box [.the_canvas create line 2  $h $w $h -fill black -width 1 ]
}


# ***********************************************
# PROCEDURE NAME: Convert_To_X_Pixel
#
# DESCRIPTION:
#    Converts a given 'x' cartesian value to
#    the corresponding 'x' pixel value.
# ***********************************************
proc Convert_To_X_Pixel { x } {

   global horiz_xi
   global min_x
   global rel_domain_dist
   global abs_domain_dist

   set X [expr ($horiz_xi + ((($x - $min_x) / $rel_domain_dist) * $abs_domain_dist))]

   return $X
}


# ***********************************************
# PROCEDURE NAME: Convert_To_Y_Pixel
#
# DESCRIPTION:
#    Converts a given 'x' cartesian value to
#    the corresponding 'y' pixel value.
# ***********************************************
proc Convert_To_Y_Pixel { y } {

   global vert_yi
   global min_y
   global rel_range_dist
   global abs_range_dist

   set Y [expr ($vert_yi + (((($rel_range_dist / 2) - $y) / $rel_range_dist)  * $abs_range_dist))]

   return $Y
}


draw_box .the_canvas $width $height

for { set x $min_x } { $x <= $max_x } { set x [expr $x + 0.01] } {

   #
   #               2 1/2
   # Draw x  (4 - x )
   #
   # Domain is only [-2 .. 2]
   #
   if { $x >= -2.0 && $x <= 2.0 } {

       set x2 [expr $x * $x]

       set tempx [expr (4 - $x2)]

       set x12 [ ::tcl::mathfunc::sqrt $tempx ]

       set y [expr ($x * $tempx) ]

       set x1 [Convert_To_X_Pixel $x]

       set y1 [Convert_To_Y_Pixel $y]

       set red_equation [.the_canvas create rectangle $x1 $y1 $x1 $y1 -width 0 -fill red ]

       check_for_x_zero $x $y $x1 $y1

       #puts "---> ($x, $y) ==> pixels ($x1, $y1)"
   }
}

button .exit -text "Exit" -command { exit }

grid .the_canvas -row 0 -column 0
grid .exit       -row 1 -column 0
