#=============================================================================
# FILE: Makefile
#
# DESCRIPTION:
#    Build c_funcdtions.c into archive to be called by Tcl script.
#=============================================================================

CC  = gcc

SRC = c_functions.c

OBJ = $(SRC:.c=.o)

LIB = libc_func.a

OPTS = -Wall

$(LIB):$(OBJ)
	@echo "________________________________"
	@echo "Build $@"
	@ar -r $(LIB) $(OBJ)

c_functions.o:c_functions.c
	@echo "________________________________"
	@echo "Compile $?"
	$(CC) $(OPTS) -c $?

clean:
	@echo "________________________________"
	@echo "clean"
	rm -f $(OBJ)
	rm -f $(LIB)
