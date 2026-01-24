#=============================================================================
# FILE: Makefile
#
# DESCRIPTION:
#    Build Chapter 3 exercises
#=============================================================================

CC  = g++

SRC = main_3_1.cpp    \
      main_3_2.cpp    \
      main_3_5.cpp    \
      main_3_7.cpp    \
      main_3_9.cpp    \
      main_3_10.cpp   \
      main_3_11.cpp   \
      main_3_16.cpp

OBJ = $(SRC:.cpp=.o)

EXE = $(SRC:.cpp=.exe)

L_PATH = 

L_LIB =

OPTS = -Wall

$(EXE):$(OBJ)
	@echo "________________________________"
	@echo "Build $@"
	@for e in $(EXE); do \
		echo "$$e"; \
		TMP_OBJ=`echo $$e | sed 's/\.exe/\.o/g'`; \
		$(CC) $(OPTS) $(L_PATH) $(L_LIB) $$TMP_OBJ -o $$e; \
		echo "-------------------"; \
	done

main_3_1.o:../main_3_1.cpp
	@echo "________________________________"
	@echo "Compile $?"
	$(CC) $(OPTS) -c $?

main_3_2.o:../main_3_2.cpp
	@echo "________________________________"
	@echo "Compile $?"
	$(CC) $(OPTS) -c $?

main_3_5.o:../main_3_5.cpp
	@echo "________________________________"
	@echo "Compile $?"
	$(CC) $(OPTS) -c $?

main_3_7.o:../main_3_7.cpp
	@echo "________________________________"
	@echo "Compile $?"
	$(CC) $(OPTS) -c $?

main_3_9.o:../main_3_9.cpp
	@echo "________________________________"
	@echo "Compile $?"
	$(CC) $(OPTS) -c $?

main_3_10.o:../main_3_10.cpp
	@echo "________________________________"
	@echo "Compile $?"
	$(CC) $(OPTS) -c $?

main_3_11.o:../main_3_11.cpp
	@echo "________________________________"
	@echo "Compile $?"
	$(CC) $(OPTS) -c $?

main_3_16.o:../main_3_16.cpp
	@echo "________________________________"
	@echo "Compile $?"
	$(CC) $(OPTS) -c $?

clean:
	@echo "________________________________"
	@echo "clean"
	rm -f *.o
	rm -f *.exe
