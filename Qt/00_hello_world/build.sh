#=============================================================================
# FILE: Makefile
#
# DESCRIPTION:
#    Base 'make' file to build the Qt "hello world" app.
#
#    Not sure I should start here.  Apparently Qt has a 'make' tool as
#    part of the overall Qt toolkit.  But I guess I'm already leaning
#    toward what I know rather than take the time to sit down and read
#    the Qt manuals.
#
#    First things first, Qt is C++ and C++ ONLY!
#
#    Next - must specify "Position Indepedent Code" (PIC) build because
#           Qt was built using a "-reduce-relocations" option ... whatever
#           that is.
#=============================================================================

CC = gcc -Wall -fPIC

SRC = hello_world.cpp

OBJ = $(SRC:.cpp=.o)

EXE = $(SRC:.cpp=.exe)

INCL = -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets \
       -I/usr/include/x86_64-linux-gnu/qt5

LPATH = -L/usr/lib/x86_64-linux-gnu

LLIBS = -lQt5Widgets

$(EXE):$(OBJ)
	@echo "________________________________"
	@echo "Build $@"
	@$(CC) $(OBJ) $(LPATH) $(LLIBS) -o $(EXE)

$(OBJ):$(SRC)
	@echo "________________________________"
	@echo "Compile $?"
	qmake hello.pro
	@$(CC) $(INCL) -c $?

clean:
	@echo "________________________________"
	@echo "Clean ..."
	@rm -f $(OBJ)
	@rm -f $(EXE)

