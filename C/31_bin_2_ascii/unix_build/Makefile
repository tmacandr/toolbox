#=============================================================================
# FILE: Makefile
#
# DESCRIPTION:
#    UNIX makefile to build the "bin_2_ascii" program.
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

CC = /usr/bin/cc

SRC = bin_2_ascii.c

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
