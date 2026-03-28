#=============================================================================
# FILE: build.sh
#
# DESCRIPTION:
#    Steps to use 'qmake' tool to build 'basic graphics' demo Qt app.
#=============================================================================

qmake -o Makefile basic_graphics.pro

make clean

make

