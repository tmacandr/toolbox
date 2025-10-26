#=============================================================================
# FILE: Makefile
#
# DESCRIPTION:
#    UNIX makefile to build the "serial_port.c" demo program.
#=============================================================================

CC = gcc -Wall

SRC = serial_port.c

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

