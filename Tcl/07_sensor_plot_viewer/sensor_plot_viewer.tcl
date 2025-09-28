#!C:/Tcl/bin/wish84
# ************************************************************************
# FILE: sensor_plot_viewer.tcl
#
# DESCRIPTION:
#    Tcl script that displays info from a 'sensor plot' list.  In most
#    cases the input file is a list of 'plots' from a radar, which in
#    the 'tracking world' are referred to as "observations".  This term
#    separates the Kalman Filtering from the type of sensor that is
#    generating the outputs.
#
#*************************************************************************
package require Tk

set canvas_height 450
set canvas_width [expr $canvas_height * 2]

canvas .lat_lon_canvas -width $canvas_width -height $canvas_height
label .dwell_info -text "dwell info"

set fd_in    0
set plot_file 0


# ***********************************************
# PROCEDURE NAME: parse_name_value_pair
#
# DESCRIPTION:
#    Extracts the value from a string whose format
#    is:
#
#          "<name> =  <value>"
#
#    The trick is that the "<name>" marker can
#    be a combination of 1 or more strings.  This
#    procedure assumes the <value> is the last
#    item in the string and returns it.  Note
#    that the <value> is returned as a string.
# ***********************************************
proc parse_name_value_pair { } {

   global fd_in

   gets $fd_in line

   set num_items [llength $line]

   if { $num_items > 2 } {

      set value [lindex $line end]

   } else {

      set value "***> error - $line only has $num_items items<***"

   }

   return $value
}


# ***********************************************
# PROCEDURE NAME: parse_track_summary_table
#
# DESCRIPTION:
#    Parses the table of "track" information.
#
#    Reads the track summary table until the
#    marker:
#
#       "**** Observation Summary ****"
#
#    is encountered.
# ***********************************************
proc parse_track_summary_table { } {

   global fd_in

   #
   # Title:
   #    blank line
   #    two row banner
   #    "----" bar
   #
   gets $fd_in line
   gets $fd_in line
   gets $fd_in line
   gets $fd_in line

   gets $fd_in line_1

   set line_2 ""

   while { [eof $fd_in] != 1 } {

       if { $line_1 == "**** Observation Summary ****" } {

          .debug_5 configure -text "last trk summary 1: $line_1"

          break

       }

       set len [string length $line_1]

       if { $len <= 0 } {

          gets $fd_in line_1

       } else {

           set track_index       [lindex $line_1 0]
           set parent_index      [lindex $line_1 1]
           set cluster_index     [lindex $line_1 2]
           set family_index      [lindex $line_1 3]
           set score             [lindex $line_1 4]
           set extern_score_aug  [lindex $line_1 5]
           set supressed         [lindex $line_1 6]
           set post_probability  [lindex $line_1 7]
           set trk_init_time     [lindex $line_1 8]
           set gated_obs_index   [lindex $line_1 9]
           set RCS               [lindex $line_1 10]
           set TCF_index         [lindex $line_1 11]
           set total_miss_count  [lindex $line_1 12]
           set prob_of_detection [lindex $line_1 13]

           #
           # This is annoying ... they output
           # maneuver model information for 1 .. 4
           # different types of models.  They don't
           # specify how many models ... you have
           # to read the 'type' ... if it's another
           # model, then process as such ... otherwise
           # go back and start reading the next track
           #
           # C'mon ... as if they couldn't put the number
           # of IMM's they're writing out.
           #
           while { [eof $fd_in] != 1 } {

               gets $fd_in line_2

               set imm_type [lindex $line_2 0]

               set len [string length $imm_type]

               if { $len < 10 } {

                   set line_1 $line_2

                   break

               }

               set range             [lindex $line_2 1]
               set azimuth_deg       [lindex $line_2 2]
               set elevation_deg     [lindex $line_2 3]
               set range_rage        [lindex $line_2 4]
               set probability       [lindex $line_2 5]
               set likelihood        [lindex $line_2 6]

               #
               # Begin parsing the "Filtered:" info
               #
               set track_state_x [lindex $line_2 8]
               set track_state_y [lindex $line_2 9]

               if { $imm_type != "PGT_IMM_RD" } {

                  set track_state_z     [lindex $line_2 10]
                  set track_state_vel_x [lindex $line_2 11]
                  set track_state_vel_y [lindex $line_2 12]
                  set track_state_vel_z [lindex $line_2 13]

                  set d_sq              [lindex $line_2 14]
                  set det_S             [lindex $line_2 15]

               } else {

                  set road_num [lindex $line_2 10]
                  set seq_num  [lindex $line_2 11]

                  set d_sq     [lindex $line_2 12]
                  set det_S    [lindex $line_2 13]

               }

               #
               # Next line is the "Predicted:" info
               #
               gets $fd_in line_3

               set pred_track_state_x [lindex $line_3 1]
               set pred_track_state_y [lindex $line_3 2]

               if { $imm_type != "PGT_IMM_RD" } {

                  set pred_track_state_z     [lindex $line_3 3]
                  set pred_track_state_vel_x [lindex $line_3 4]
                  set pred_track_state_vel_y [lindex $line_3 5]
                  set pred_track_state_vel_z [lindex $line_3 6]

               }

               .debug_6 configure -text "last line-2: $line_2"

           }
       }
   }
}


# ***********************************************
# PROCEDURE NAME: draw_sensor_position
#
# DESCRIPTION:
#    Draws the sensor position on the map
# ***********************************************
proc draw_sensor_position { lat lon alt } {

   global canvas_width
   global canvas_height

   set y1 [expr ( ( (90.0 - $lat) / 180.0 ) * $canvas_height) ]
   set x1 [expr ( ( (180.0 + $lon) / 360.0 ) * $canvas_width) ]

   set y2 [expr $y1 + 1]
   set x2 [expr $x1 + 1]

   set sensor_pos [.lat_lon_canvas create rect $x1 $y1 $x2 $y2 -fill orange]
}


# ***********************************************
# PROCEDURE NAME: draw_dwell_corners
#
# DESCRIPTION:
#    Draws the corners of the dwell.
# ***********************************************
proc draw_dwell_corners { l1 g1 a1 l2 g2 a2 l3 g3 a3 l4 g4 a4} {

   global canvas_width
   global canvas_height

   set y1 [expr ( ( (90.0 - $l1) / 180.0 ) * $canvas_height) ]
   set x1 [expr ( ( (180.0 + $g1) / 360.0 ) * $canvas_width) ]

   set y2 [expr ( ( (90.0 - $l2) / 180.0 ) * $canvas_height) ]
   set x2 [expr ( ( (180.0 + $g2) / 360.0 ) * $canvas_width) ]

   set y3 [expr ( ( (90.0 - $l3) / 180.0 ) * $canvas_height) ]
   set x3 [expr ( ( (180.0 + $g3) / 360.0 ) * $canvas_width) ]

   set y4 [expr ( ( (90.0 - $l4) / 180.0 ) * $canvas_height) ]
   set x4 [expr ( ( (180.0 + $g4) / 360.0 ) * $canvas_width) ]

   set boundaries "$x1 $y1 $x2 $y2 $x3 $y3 $x4 $y4 $x1 $y1"

   set dwell_corners [.lat_lon_canvas create line $boundaries -fill green -width 1]

}


# ***********************************************
# PROCEDURE NAME: parse_sensor_position
#
# DESCRIPTION:
#    Parses the observation information for the
#    "Sensor Position" values.
#
#    This is a mess ... because the formatting
#    from RMHT is a mess.
# ***********************************************
proc parse_sensor_position { } {

   global fd_in

   #
   # First line is of the form:
   #
   #   "Sensor Position: <l> <g> <a>Ver[1] (x, y, z): <l> <g> <a> Ver[2] (x, y, z): <l> <g> <a>"
   #
   # where:
   #    <l> the latitude value
   #    <g> longitude value
   #    <a> altitude value
   # and
   #    Ver[n]
   # marks the vertices of the corners of the dwell.
   #
   # The problem is the "<a>Ver[1]" string.  They
   # didn't put a separation between the value and
   # the name.
   #
   gets $fd_in line

   .debug_0 configure -text "line: $line"

   #
   # Lop off the "Sensor Position:" substring
   #
   set trimmed [lrange $line 2 end]

   #
   # Now, drop the "{ }" combinations.  These
   # are added to the line for some reason during
   # the 'gets' operation ... I don't know why.
   # It may have something to do with strings
   # that are a combination of numbers and alphabetic
   # characters ... such as "11.0Ver[1]".
   #
   regsub -all "\{" $trimmed " " trimmed
   regsub -all "\}" $trimmed " " trimmed

   set start_pos [string first "Ver" $trimmed 0]
   set end_pos [expr $start_pos + 17]

   set trimmed [string replace $trimmed $start_pos $end_pos " "]

   .debug_1 configure -text "trimmed: $trimmed"

   set start_pos [string first "Ver" $trimmed 0]
   set end_pos [expr $start_pos + 17]

   set trimmed [string replace $trimmed $start_pos $end_pos " "]

   .debug_2 configure -text "done: $trimmed"

   #
   # The string should now look like this:
   #
   #   " <l> <g> <a>  <l> <g> <a>   <l> <g> <a>"
   #
   # So, just pick off the values now ...
   #
   set sensor_lat [lindex $trimmed 0]
   set sensor_lon [lindex $trimmed 1]
   set sensor_alt [lindex $trimmed 2]

   .sensor_lat configure -text "sensor lat: $sensor_lat"
   .sensor_lon configure -text "sensor lon: $sensor_lon"
   .sensor_alt configure -text "sensor alt: $sensor_alt"

   draw_sensor_position $sensor_lat $sensor_lon $sensor_alt

   set dwell_corner_1_lat [lindex $trimmed 3]
   set dwell_corner_1_lon [lindex $trimmed 4]
   set dwell_corner_1_alt [lindex $trimmed 5]

   set dwell_corner_2_lat [lindex $trimmed 6]
   set dwell_corner_2_lon [lindex $trimmed 7]
   set dwell_corner_2_alt [lindex $trimmed 8]

   #
   # The next line is of the form:
   #
   #   "Ver[3] (x, y, z): <l> <g> <a>  Ver[4] (x, y, z): <l> <g> <a>"
   #
   # This one's easier ...
   #
   gets $fd_in line

   regsub -all "\{" $line " " line
   regsub -all "\}" $line " " line

   set start_pos [string first "Ver" $line 0]
   set end_pos [expr $start_pos + 17]

   set line [string replace $line $start_pos $end_pos " "]

   .debug_3 configure -text "line: $line"

   set start_pos [string first "Ver" $line 0]
   set end_pos [expr $start_pos + 17]

   set line [string replace $line $start_pos $end_pos " "]

   .debug_4 configure -text "done: $line"

   #
   # The string should now look like this:
   #
   #   "  <l> <g> <a>   <l> <g> <a>"
   #
   # pick off the values again
   #
   set dwell_corner_3_lat [lindex $line 0]
   set dwell_corner_3_lon [lindex $line 1]
   set dwell_corner_3_alt [lindex $line 2]

   set dwell_corner_4_lat [lindex $line 3]
   set dwell_corner_4_lon [lindex $line 4]
   set dwell_corner_4_alt [lindex $line 5]

   draw_dwell_corners $dwell_corner_1_lat $dwell_corner_1_lon $dwell_corner_1_alt \
                      $dwell_corner_2_lat $dwell_corner_2_lon $dwell_corner_2_alt \
                      $dwell_corner_3_lat $dwell_corner_3_lon $dwell_corner_3_alt \
                      $dwell_corner_4_lat $dwell_corner_4_lon $dwell_corner_4_alt
}


# ***********************************************
# PROCEDURE NAME: parse_observation_summary
#
# DESCRIPTION:
#    Parses the table of "observation" information.
#
#    Reads the obs summary table until the
#    marker:
#
#       "**** TCF Summary ****"
#
#    is encountered.
# ***********************************************
proc parse_observation_summary { } {

   global fd_in

   #
   # blank line
   # Sensor position
   # blank line
   #
   gets $fd_in line

   parse_sensor_position

   gets $fd_in line

   #
   # Title is 3 rows, then the "----" bar
   #
   gets $fd_in line
   gets $fd_in line
   gets $fd_in line
   gets $fd_in line

   while { [eof $fd_in] != 1 } {

       gets $fd_in line

       if { $line == "**** TCF Summary ****" } {

          break

       }
   }
}


# ***********************************************
# PROCEDURE NAME: parse_TCF_summary
#
# DESCRIPTION:
#    Parses the table of "TCF" information.
#
#    Reads the TCF summary table until the
#    marker:
#
#       "****** Track Summary ******"
#
#    is encountered.
# ***********************************************
proc parse_TCF_summary { } {

   global fd_in

   #
   # blank line
   # title
   # "----" bar
   #
   gets $fd_in line
   gets $fd_in line
   gets $fd_in line

   while { [eof $fd_in] != 1 } {

       gets $fd_in line

       if { $line == "****** Track Summary ******" } {

          break

       }
   }
}


# ***********************************************
# PROCEDURE NAME: parse_dwell 
#
# DESCRIPTION:
#    Extracts the information from the current
#    dwell.  This procedure expects that the item:
#
#          "Dwell No         =  xx"
#
#    has just been read and that the rest of the
#    dwell information follows.
#
#    Parsing continues until the marker:
#
#           "****** Track Summary ******"
#
#    is read ... indicating the start of a new
#    dwell
# ***********************************************
proc parse_dwell { } {

   global fd_in

   set dwell_time [parse_name_value_pair]
   .dwell_time configure -text "dwell-time.....: $dwell_time"

   set num_of_tracks [parse_name_value_pair]
   .num_of_tracks configure -text "num of tracks.........: $num_of_tracks"

   set num_of_families [parse_name_value_pair]
   .num_of_families configure -text "num of families.....: $num_of_families"

   set num_of_clusters [parse_name_value_pair]
   .num_of_clusters configure -text "num of clusters.....: $num_of_clusters"

   #
   # Blank line
   #
   gets $fd_in line

   set num_of_tracks_coarse_gated [parse_name_value_pair]
   .num_of_tracks_coarse_gated configure -text "num trks coarse-gated: $num_of_tracks_coarse_gated"

   set num_of_tracks_predicted [parse_name_value_pair]
   .num_of_tracks_predicted configure -text "num trks predicted......: $num_of_tracks_predicted"

   parse_track_summary_table

   parse_observation_summary 

   parse_TCF_summary 

}


# ***********************************************
# PROCEDURE NAME: get_next_dwell 
#
# DESCRIPTION:
#    Continues reading the plot file until the
#    marker "Dwell No" is reached.  This marks
#    the start of a new dwell.
# ***********************************************
proc get_next_dwell { } {

   global fd_in
   global plot_file

   if { $fd_in == 0 } {

      set fd_in [open $plot_file r]

   }

   while { [eof $fd_in] != 1 } {

       gets $fd_in line

       set num_items [llength $line]

       if { $num_items > 1 } {

           set item [lrange $line 0 1]

           if { $item == "Dwell No" } {

              set dwell_num [lindex $line 3]

              .dwell_num_label configure -text "dwell no...: $dwell_num"

              parse_dwell

              break
           }
       }
   }

}


# ***********************************************
# PROCEDURE NAME: draw_coordinate_axes 
#
# DESCRIPTION:
#    Draws the (x, y) axes of a flat earth.  The
#    grid is [-90 .. 90] for latitude on the y-axis
#    and [-180 .. 180] for longitude on the x-axis.
#
#                  (lat)
#                   |
#                   |
#             ------|------ (lon)
#                   |
#                   |
#
# ***********************************************
proc draw_coordinate_axes { } {

   global canvas_width
   global canvas_height

   global canvas

   set x1 [expr $canvas_width / 2]
   set y1 0

   set x2 $x1
   set y2 $canvas_height

   set lat_line [.lat_lon_canvas create line $x1 $y1 $x2 $y2 -fill blue -width 2]

   set x1 0
   set y1 [expr $canvas_height / 2]

   set x2 $canvas_width
   set y2 $y1

   set lon_line [.lat_lon_canvas create line $x1 $y1 $x2 $y2 -fill blue -width 2]

   set boundaries "2 2 $canvas_width 2 $canvas_width $canvas_height 2 $canvas_height 2 2"

   set border [.lat_lon_canvas create line $boundaries -fill green -width 1]
}


# ***********************************************
# PROCEDURE NAME: main ... sort of ...
#
# DESCRIPTION:
#    Executing commands begins here ...
# ***********************************************
puts "Begin - Plot Viewer"

if { $argc != 1 } {

   set usage_msg "***> ERROR - missing argument(s)"
   set usage_msg "$usage_msg\n***> USAGE:"
   set usage_msg "$usage_msg\nsensor_plot_viewer.tcl <name-of-plot-file>"
   set usage_msg "$usage_msg\n***> EXAMPLE:"
   set usage_msg "$usage_msg\nsensor_plot_viewer.tcl plot_info.txt"

   label .dwell_num_label -text $usage_msg

   button .exit -text "Exit" -command { exit }

   grid .lat_lon_canvas  -row 0 -column 0
   grid .dwell_num_label -row 1 -column 0
   grid .exit            -row 2 -column 0

} else {


   #
   # Not quite like C ... the 'argv' is the list
   # of the arguments to the program.  So the name of
   # the program is not 'lindex $argv 0' ... it's "argv0"
   #
   set plot_file [lindex $argv 0]

   label .dwell_num_label -text "Plot file: $plot_file"
   label .dwell_time  -text "dwell-time: 0"
   label .num_of_tracks -text "num of tracks: 0"
   label .num_of_families -text "num of families: 0"
   label .num_of_clusters -text "num of clusters: 0"
   label .num_of_tracks_coarse_gated -text "num trks coarse-gated: 0"
   label .num_of_tracks_predicted -text "num trks predicted: 0"

   label .sensor_lat -text "sensor lat: 0"
   label .sensor_lon -text "sensor lon: 0"
   label .sensor_alt -text "sensor alt: 0"

   label .debug_0 -text " - debug 0 here -"
   label .debug_1 -text " - debug 1 here -"
   label .debug_2 -text " - debug 2 here -"
   label .debug_3 -text " - debug 3 here -"
   label .debug_4 -text " - debug 4 here -"
   label .debug_5 -text " - debug 5 here -"
   label .debug_6 -text " - debug 6 here -"

   button .read_dwell -text "Next Dwell" -command "get_next_dwell"

   button .exit -text "Exit" -command { exit }

   draw_coordinate_axes

   grid .lat_lon_canvas             -row 0 -column 0
   grid .dwell_num_label            -row 1 -column 0
   grid .dwell_time                 -row 2 -column 0
   grid .num_of_tracks              -row 3 -column 0
   grid .num_of_families            -row 4 -column 0
   grid .num_of_clusters            -row 5 -column 0
   grid .num_of_tracks_coarse_gated -row 6 -column 0
   grid .num_of_tracks_predicted    -row 7 -column 0
   grid .sensor_lat                 -row 8 -column 0
   grid .sensor_lon                 -row 9 -column 0
   grid .sensor_alt                 -row 10 -column 0
   grid .read_dwell                 -row 11 -column 0
   grid .debug_0                    -row 12 -column 0
   grid .debug_1                    -row 13 -column 0
   grid .debug_2                    -row 14 -column 0
   grid .debug_3                    -row 15 -column 0
   grid .debug_4                    -row 16 -column 0
   grid .debug_5                    -row 17 -column 0
   grid .debug_6                    -row 18 -column 0
   grid .exit                       -row 19 -column 0

}

# END
