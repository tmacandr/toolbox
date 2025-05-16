#==============================================================================
# FILE: Makefile
#
# DESCRIPTION:
#    Makefile to build the 'UDP' client and server demo programs.
#==============================================================================

CC=gcc

INCL_PATH=

L_PATH=-L/lib/w32api

L_LIB=

OPTS=-Wall

CLIENT_EXE=UDP_client.exe

SERVER_EXE=UDP_server.exe

EXE = $(CLIENT_EXE) \
      $(SERVER_EXE)

OBJ = $(EXE:.exe=.o)

$(EXE):$(OBJ)
	@echo "________________________________"
	@echo "Build UDP server"
	$(CC) $(OPTS) UDP_server.o $(L_PATH) $(L_LIB) -o UDP_server.exe
	@echo "Build UDP client"
	$(CC) $(OPTS) UDP_client.o $(L_PATH) $(L_LIB) -o UDP_client.exe

UDP_client.o:../UDP_client.c
	@echo "________________________________"
	@echo "Compile $?"
	$(CC) $(INCL_PATH) $(OPTS) -c $?

UDP_server.o:../UDP_server.c
	@echo "________________________________"
	@echo "Compile $?"
	$(CC) $(INCL_PATH) $(OPTS) -c $?

clean:
	@echo "________________________________"
	@echo "clean"
	rm -f *.o
	rm -f *.exe

