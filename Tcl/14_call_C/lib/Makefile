#=============================================================================
# FILE: Makefile
#
# DESCRIPTION:
#    Build c_funcdtions.c into archive to be called by Tcl script.
#=============================================================================

CC  = gcc

OPTS = -Wall -DUSE_TCL_STUBS -fPIC

SRC = c_functions.c

OBJ = $(SRC:.c=.o)

INCL = -I/usr/include/tcl8.6

LIB_PATH = -L/usr/lib/x86_64-linux-gnu

LIBS = -ltclstub8.6

TO_LIB = libc_func.so

$(TO_LIB):$(OBJ)
	@echo "________________________________"
	@echo "Build $@"
	@gcc -shared -o $(TO_LIB) $(OBJ) $(LIB_PATH) $(LIBS)

c_functions.o:c_functions.c
	@echo "________________________________"
	@echo "Compile $?"
	$(CC) $(OPTS) $(INCL) -c $?

clean:
	@echo "________________________________"
	@echo "clean"
	rm -f $(OBJ)
	rm -f $(LIB)
