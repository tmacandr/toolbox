#=============================================================================
# FILE: build.sh
#
# DESCRIPTION:
#    Steps to use 'qmake' tool to build 'menu-bar' demo Qt app.
#=============================================================================

qmake -o Makefile menu_bar.pro

make clean

make

