#=============================================================================
# FILE: Makefile
#
# DESCRIPTION:
#    Uses the Java compiler 'javac' to build the 'hello world' program.
#=============================================================================

SRC = HelloWorld.java

OBJ = $(SRC:.java=.class)

$(OBJ):$(SRC)
	@echo "---> Compile $?"
	javac $(SRC)

clean:
	rm $(OBJ)
