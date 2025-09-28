#!/usr/bin/wish
# ************************************************************************
# FILE: graph_exercise_4.4_18.tcl
#
# DESCRIPTION:
#    Tcl script to graph the equation from Exercise 4.4-18
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

set horiz_xi 1
set horiz_yi 498

set horiz_xf 498
set horiz_yf 498

set x_axis [.the_canvas create line $horiz_xi $horiz_yi $horiz_xf $horiz_yf -fill blue -width 1]
set x_label [.the_canvas create text 455 $horiz_yf -text "X"]

set vert_xi 498
set vert_yi 1

set vert_xf 498
set vert_yf 498

set y_axis [.the_canvas create line $vert_xi $vert_yi $vert_xf $vert_yi -fill blue -width 1]
set y_label [.the_canvas create text 1 40 -text "Y"]

set max_x  [expr 2.0 ]
set min_x  [expr 0.0]

set rel_domain_dist [expr $max_x - $min_x]

set max_y [expr 3.0]
set min_y [expr 0.0]

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

   set Y [expr ($vert_yi + ((($rel_range_dist - $y) / $rel_range_dist)  * $abs_range_dist))]

   return $Y
}


# ***********************************************
# PROCEDURE NAME: Draw_X_Grid_Marks
#
# DESCRIPTION:
#    Marks the abscissa with grid lines.
# ***********************************************
proc Draw_X_Grid_Marks { } {

   global horiz_yi
   global min_x
   global max_x

   set y_up [expr ($horiz_yi + 5)]
   set y_dwn [expr ($horiz_yi - 5)]

   for { set x $min_x } { $x <= $max_x } { set x [expr $x + 1] } {

       set x1 [Convert_To_X_Pixel $x]

       set grid_mark [.the_canvas create rectangle $x1 $y_up $x1 $y_dwn -width 0 -fill black ]
   }
}


# ***********************************************
# PROCEDURE NAME: Draw_Y_Grid_Marks
#
# DESCRIPTION:
#    Marks the ordinate with grid lines.
# ***********************************************
proc Draw_Y_Grid_Marks { } {

   global vert_xi
   global min_y
   global max_y

   set x_up [expr (10)]
   set x_dwn [expr (-5)]

   for { set y $min_y } { $y <= $max_y } { set y [expr $y + 1] } {

       set y1 [Convert_To_Y_Pixel $y]

       set grid_mark [.the_canvas create rectangle $x_up $y1 $x_dwn $y1 -width 0 -fill black ]
   }
}

draw_box .the_canvas $width $height

Draw_X_Grid_Marks

Draw_Y_Grid_Marks

for { set x $min_x } { $x <= $max_x } { set x [expr $x + 0.0001] } {

   #
   #             --------
   #            /      2
   # Draw  x \ / (4 - x )
   #
   set x2 [expr ( $x * $x )]

   set rad [expr ( 4 - $x2 )]

   if { $rad >= 0 } {

       set xroot [ ::tcl::mathfunc::sqrt $rad ]

       set y [expr ( $x * $xroot )]

       set x1 [Convert_To_X_Pixel $x]

       set y1 [Convert_To_Y_Pixel $y]

       set red_equation [.the_canvas create rectangle $x1 $y1 $x1 $y1 -width 0 -fill red ]

       check_for_x_zero $x $y $x1 $y1
   }

   set y $x

   set x1 [Convert_To_X_Pixel $x]

   set y1 [Convert_To_Y_Pixel $y]

   set green_equation [.the_canvas create rectangle $x1 $y1 $x1 $y1 -width 0 -fill green ]
}

button .exit -text "Exit" -command { exit }

grid .the_canvas -row 0 -column 0
grid .exit       -row 1 -column 0
