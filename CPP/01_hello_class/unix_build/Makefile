#==============================================================================
# FILE: Makefile
#
# DESCRIPTION:
#    Makefile to build DOS example program ... what?
#==============================================================================
CC = g++ -ggdb -Wall

SRC = someClass.cpp \
      main.cpp

OBJ = $(SRC:.cpp=.o)

EXE = main.exe

IPATH = -I.. 

$(EXE):$(OBJ)
	@echo "Link .....: $@"
	@$(CC) $? -o $@

main.o:../main.cpp
	@echo "Compile...: $?"
	@$(CC) $(IPATH) -c $?

someClass.o:../someClass.cpp
	@echo "Compile...: $?"
	@$(CC) $(IPATH) -c $?

clean:
	@echo "Clean"
	@rm -f *.o
	@rm -f *.exe

