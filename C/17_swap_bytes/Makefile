#******************************************************************************
# FILE: Makefile
#
# DESCRIPTION:
#    UNIX (actually, cygwin) makefile to build the 'swap-bytes' program via
#    the GNU toolset.
#
# COPYRIGHT:
#   Copyright (c), Raytheon Company, 2009
#   All Rights Reserved -- Raytheon Proprietary -- Unpublished Work
#******************************************************************************

#
# Tools and build environment ...
#
CC       = gcc

C_FLAGS  = -O2 \
           -std=gnu99 \
           -ansi

WARN     = -Wall

I_PATH   = -I../../source/C

LD_LIBS  = -luser32

LD_PATH = -L/lib/w32api

#
# Source to .exe
#
SRC  = ../../source/C/swap_bytes.c

OBJ  = swap_bytes.o

EXE  = swap_bytes.exe

$(EXE): $(OBJ)
	@echo "________________________________"
	@echo "Build executable ..."
	$(CC) $(C_FLAGS) $(LD_PATH) $? $(LD_LIBS) -o $@

$(OBJ):$(SRC)
	@echo "________________________________"
	@echo "Compile $? "
	$(CC) $(C_FLAGS) $(WARN) $(I_PATH) -c $?

clean:
	@rm -f $(OBJ)
	@rm -f $(EXE)
