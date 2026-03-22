#=============================================================================
# FILE: build.sh
#
# DESCRIPTION:
#    Steps to use 'qmake' tool to build 'hello_world' Qt app.
#
#    I made the mistake of not reading the "Qt Assistant" documentation.
#
#    A Qt build requires the use of the 'qmake' tool.  And already I don't
#    like that.  It means the build mechanics are so friggin' complicated
#    that trying to do it 'manually' is an impossibility.
#
#    So this script captures the base steps.
#
#    NOTES:
#       1) Qt is C++ and C++ ONLY!
#
#       2) I don't have to worry about specifying
#          "Position Indepedent Code" (PIC) build because
#          Qt was built using a "-reduce-relocations"
#          option ... whatever that is.
#
#          But since the 'qmake' tool figures everything out,
#          I don't have to worry about it.
#=============================================================================

qmake -o Makefile hello.pro

make clean

make

