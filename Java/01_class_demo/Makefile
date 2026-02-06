#=============================================================================
# FILE: Makefile
#
# DESCRIPTION:
#    Uses the Java compiler 'javac' to build the 'class_demo' program.
#=============================================================================

SRC = class_demo.java

OBJ = $(SRC:.java=.class)

$(OBJ):$(SRC)
	@echo "---> Compile $?"
	javac $(SRC)

clean:
	rm $(OBJ)
