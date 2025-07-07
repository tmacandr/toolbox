#=============================================================================
# FILE: Makefile
#
# DESCRIPTION:
#    Make to build question 14 program of job quiz problems.
#=============================================================================

CC = g++ -Wall -g3

INCL = -I.

SRC = binary_tree.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

EXE = binary_tree.exe

$(EXE):$(OBJ)
	@echo "--------Link-------"
	$(CC) $(OBJ) -o $(EXE)

binary_tree.o:binary_tree.cpp
	@echo "-------Compile $? -----"
	$(CC) $(INCL) -c $?

question_14.o:question_14.cpp
	@echo "-------Compile $? -----"
	$(CC) $(INCL) -c $?

clean:
	@echo "---> Begin clean"
	@rm $(OBJ)
	@rm $(EXE)
	@echo "---> Done"

