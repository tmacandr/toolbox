#=============================================================================
# FILE: Makefile
#
# DESCRIPTION:
#    UNIX makefile to build the "count_down" C++ program.
#=============================================================================

CC  = g++

SRC = count_down.cpp

OBJ = $(SRC:.cpp=.o)

EXE = $(SRC:.cpp=.exe)

L_PATH = 

L_LIB =

OPTS = -Wall

$(EXE):$(OBJ)
	@echo "________________________________"
	@echo "Build $@"
	$(CC) $(OPTS) $? $(L_PATH) $(L_LIB) -o $@

$(OBJ):$(SRC)
	@echo "________________________________"
	@echo "Compile $?"
	$(CC) $(OPTS) -c $?

clean:
	@echo "________________________________"
	@echo "clean"
	rm -f *.o
	rm -f *.exe
