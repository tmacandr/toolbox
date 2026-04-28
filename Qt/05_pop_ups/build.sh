#=============================================================================
# FILE: build.sh
#
# DESCRIPTION:
#    Steps to use 'qmake' tool to build 'pop-up demo' Qt app.
#=============================================================================

qmake -o Makefile pop_up_demo.pro

make clean

make

