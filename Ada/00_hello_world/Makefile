#===================================================================
# FILE: Makefile
#
# Description:
#    Make file to build the Ada hello_world.adb to an executable.
#
#    Uses GNU "gnat" package for Ada compiler and linker.
#
#    Installation of GNAT toolset on Ubuntu:
#
#       sudo apt install gnat
#
#    That's it!
#
#    Notes on Makefiles:
#
#       http://www.eecs.harvard.edu/~ellard/libsq/ref/make.html
#
# USAGE:
#   make
#   make clean
#===================================================================

#
# Define variables:
#
ADA   = gnat
LPATH = -L/lib/w32api
SRC   = hello_world.adb
ALI   = $(SRC:.adb=.ali)
OBJ   = $(SRC:.adb=.o)

#
# Executable to be built
#
EXE   = hello_world.exe

#
# Special commands:
#    $@ the file to be made. 
#    $? the dependents. 
#    $< the related file that caused the action. 
#    $* the prefix of the target
# 
$(EXE):
	$(ADA) compile $(SRC)
	$(ADA) bind -x hello_world.ali
	$(ADA) link hello_world.ali $(LPATH) -o $(EXE)

#
# The "clean" target deletes the old executable.
#
clean:
	@echo "---> delete .o and .exe file(s)"
	rm -f *.exe
	rm -f *.o
	rm -f *.ali
	@echo "---> clean finished"

