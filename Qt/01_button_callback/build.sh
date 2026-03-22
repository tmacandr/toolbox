#=============================================================================
# FILE: build.sh
#
# DESCRIPTION:
#    Steps to use 'qmake' tool to build 'button callback' Qt app.
#=============================================================================

qmake -o Makefile button_demo.pro

make clean

make

