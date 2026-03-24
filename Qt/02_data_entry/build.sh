#=============================================================================
# FILE: build.sh
#
# DESCRIPTION:
#    Steps to use 'qmake' tool to build 'data-entry' Qt app.
#=============================================================================

qmake -o Makefile data_entry.pro

make clean

make

