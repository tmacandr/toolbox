#=============================================================================
# FILE: Makefile
#
# DESCRIPTION:
#    Make to build question 14 program of job quiz problems.
#=============================================================================

CC = g++ -Wall -g3

INCL = -I.

SRC = binary_tree.cpp \
      main.cpp

OBJ = $(SRC:.cpp=.o)

EXE = binary_tree.exe

$(EXE):$(OBJ)
	@echo "--------Link-------"
	$(CC) $(OBJ) -o $(EXE)

binary_tree.o:binary_tree.cpp
	@echo "-------Compile $? -----"
	$(CC) $(INCL) -c $?

main.o:main.cpp
	@echo "-------Compile $? -----"
	$(CC) $(INCL) -c $?

clean:
	@echo "---> Begin clean"
	@for each in $(OBJ); do if test -f $$each; then rm $$each; fi; done
	@if test -f $(EXE); then rm $(EXE); fi
	@echo "---> Done"

