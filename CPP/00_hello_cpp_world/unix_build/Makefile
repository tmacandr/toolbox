#=============================================================================
# FILE: Makefile
#
# DESCRIPTION:
#    UNIX makefile to build the "hello-world" C++ program.
#
#    To run, type:
#
#			make
#
#    By default, any program in the directory named "Makefile" will be
#    executed.  Alternatively, you can type:
#
#           make -f <name-of-makefile>
#
#    So, the command is sort of redundant:
#
#           make -f Makefile
#
#=============================================================================


CC  = g++

SRC = hello_world.cpp

OBJ = $(SRC:.cpp=.o)

EXE = $(SRC:.cpp=.exe)

L_PATH = -L/lib/w32api

L_LIB =

OPTS = -Wall

$(EXE):$(OBJ)
	@echo "________________________________"
	@echo "Build $@"
	$(CC) $(OPTS) $? $(L_PATH) $(L_LIB) -o $@

$(OBJ):../$(SRC)
	@echo "________________________________"
	@echo "Compile $?"
	$(CC) $(OPTS) -c $?

clean:
	@echo "________________________________"
	@echo "clean"
	rm -f *.o
	rm -f *.exe
