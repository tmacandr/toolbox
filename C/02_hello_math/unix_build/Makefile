#

CC  = /usr/bin/gcc

SRC = ../hello_math.c

OBJ = hello_math.o

EXE = $(OBJ:.o=.exe)

L_PATH = -L/lib/w32api

L_LIB = -lm

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
