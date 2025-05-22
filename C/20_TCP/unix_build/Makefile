#==============================================================================
# FILE: Makefile
#
# DESCRIPTION:
#    Makefile to build the 'TCP' client and server demo programs.
#==============================================================================

CC=gcc

L_PATH=

L_LIB= 

OPTS=-Wall

CLIENT_EXE=TCP_client.exe

SERVER_EXE=TCP_server.exe

EXE = $(CLIENT_EXE) \
      $(SERVER_EXE)

OBJ = $(EXE:.exe=.o)

$(EXE):$(OBJ)
	@echo "________________________________"
	@echo "Build TCP server"
	$(CC) $(OPTS) TCP_server.o $(L_PATH) $(L_LIB) -o TCP_server.exe
	@echo "Build TCP client"
	$(CC) $(OPTS) TCP_client.o $(L_PATH) $(L_LIB) -o TCP_client.exe

TCP_client.o:../TCP_client.c
	@echo "________________________________"
	@echo "Compile $?"
	$(CC) $(OPTS) -c $?

TCP_server.o:../TCP_server.c
	@echo "________________________________"
	@echo "Compile $?"
	$(CC) $(OPTS) -c $?

clean:
	@echo "________________________________"
	@echo "clean"
	rm -f *.o
	rm -f *.exe

