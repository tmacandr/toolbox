#===================================================================
# FILE: Makefile
#
# Description:
#    Builds the items of the 'hello_task_pkg' demo.
#===================================================================

#
# Define variables:
#
ADA   = gnat
LPATH = -L/lib/w32api
LLIBS = 
OPTS  = 

SRC   = main.adb \
        hello_task_pkg.adb

OBJ   = $(SRC:.adb=.o)

#
# This variable is a list of the
# .o files.  It is build by converting
# the ".c" in each item in SRC to a ".o"
#
EXE   = main.exe

$(EXE):$(OBJ)
	@echo "---> build executable: $@"
	$(ADA) bind -x main.ali
	$(ADA) link main.ali $(LPATH) -o $(EXE)

main.o:main.adb
	@echo "---> compile $?"
	$(ADA) compile $?

hello_task_pkg.o:hello_task_pkg.adb
	@echo "---> compile $?"
	$(ADA) compile $?

#
# The "clean" target deletes the old executable.
#
clean:
	@echo "---> delete .o and .exe file(s)"
	rm -f *.exe
	rm -f *.o
	rm -f *.ali
	@echo "---> clean finished"

