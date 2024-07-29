#=============================================================================
# FILE: Makefile
#
# DESCRIPTION:
#    UNIX makefile to build the "hello-world" program.
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

CC = gcc -Wall

SRC = hello_world.c

OBJ = $(SRC:.c=.o)

EXE = $(SRC:.c=.exe)

$(EXE):$(OBJ)
	@echo "________________________________"
	@echo "Build $@"
	@$(CC) $(OBJ) -o $(EXE)

$(OBJ):../$(SRC)
	@echo "________________________________"
	@echo "Compile $?"
	@$(CC) -c $?

clean:
	@echo "________________________________"
	@echo "Clean ..."
	@rm -f $(OBJ)
	@rm -f $(EXE)

