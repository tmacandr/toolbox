#=============================================================================
# FILE: Makefile
#
# DESCRIPTION:
#    Uses the Java compiler 'javac' to build the Java 'button' GUID demo.
#=============================================================================

SRC = ButtonExample.java

OBJ = $(SRC:.java=.class)

$(OBJ):$(SRC)
	@echo "---> Compile $?"
	javac $(SRC)

clean:
	rm $(OBJ)
	rm *.class
