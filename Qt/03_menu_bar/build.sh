#=============================================================================
# FILE: build.sh
#
# DESCRIPTION:
#    Steps to use 'qmake' tool to build 'menu-bar' demo Qt app.
#
#    ATTENTION:
#       Below are some parameters during a 'build' operation.  However,
#       the 'lesson learned' is do NOT try to figure out object attributes
#       or behavior by reading "code".  You'll go blind!  Instead, one
#       MUST use the documentation in the "Qt Assistant" tool.
#
#    Build Configuration:
#    --------------------
#       /usr/lib/qt5/bin/uic <project>.ui -o <project>.h
#
#       g++ -c -pipe -O2 -std=gnu++11
#          -Wall -W -D_REENTRANT -fPIC
#          -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG
#          -DQT_WIDGETS_LIB -DQT_GUI_LIB
#          -DQT_CORE_LIB
#          -I.
#          -isystem /usr/include/x86_64-linux-gnu/qt5
#          -isystem /usr/include/x86_64-linux-gnu/qt5/QtWidgets
#          -isystem /usr/include/x86_64-linux-gnu/qt5/QtGui
#          -isystem /usr/include/x86_64-linux-gnu/qt5/QtCore
#          -I.
#          -I.
#          -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++
#          -o main.o main.cpp
#=============================================================================

qmake -o Makefile menu_bar.pro

make clean

make

