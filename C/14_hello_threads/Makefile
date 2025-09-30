#==============================================================================
# FILE: Makefile
#
# DESCRIPTION:
#    Makefile to build the 'hello_thread' application.
#==============================================================================

CC  = gcc

SRC = ./hello_threads.c

OBJ = $(SRC:.c=.o)

EXE = $(SRC:.c=.exe)

L_PATH = -L/lib/w32api

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
