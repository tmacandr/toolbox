#=============================================================================
# FILE: Makefile
#
# DESCRIPTION:
#    UNIX makefile to build the "char_capture.c" program.
#=============================================================================

CC = gcc -Wall

SRC = char_capture.c

OBJ = $(SRC:.c=.o)

EXE = $(SRC:.c=.exe)

$(EXE):$(OBJ)
	@echo "________________________________"
	@echo "Build $@"
	@$(CC) $(OBJ) -o $(EXE)

$(OBJ):$(SRC)
	@echo "________________________________"
	@echo "Compile $?"
	@$(CC) -c $?

clean:
	@echo "________________________________"
	@echo "Clean ..."
	@rm -f $(OBJ)
	@rm -f $(EXE)

