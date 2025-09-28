#!C:/Tcl/bin/tclsh
# ************************************************************************
# FILE: hello.tcl
#
# DESCRIPTION:
#    Determine concavity of equation from Section 4.4, Exercise 18.
#*************************************************************************

# ***********************************************
# PROCEDURE NAME: Second_Derivative 
#
# DESCRIPTION:
#    Second derivative is (I claim) ...
#
#                  2
#       "     2x (3x - 10)
#      f  = --------------
#                   2 3/2
#             (4 - x )
#
#    Abscissa values of infection points
#    are (I claim) ...
#
#        x = sqrt(10/3) = 1.83
#
#        x = -sqrt(10/3) = -1.83
#
# ***********************************************
proc Second_Derivative { x } {

   set x2 [expr ($x * $x)]

   set num [expr ( (2 * $x) * (3 * $x2 - 10) )]

   set rad [expr (4 - $x2)]

   set rad2 [expr ($rad * $rad)]

   set denom [ ::tcl::mathfunc::pow $rad2 0.33 ]

   set Y [expr ($num / $denom)]

   return $Y
}


# ***********************************************
# PROCEDURE NAME: main ... sort of ...
#
# DESCRIPTION:
#    Executing commands begins here ...
# ***********************************************
puts "Begin"

set values { -1.9 -1.0 1.0 1.9 }

foreach v $values {

   set y [Second_Derivative $v]

   puts "---> Second derivative of $v is $y"

} 

puts "End - hello Tcl"
