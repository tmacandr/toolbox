#=============================================================================
# FILE: build.mak
#
# DESCRIPTION:
#    Visual Studio NMAKE file for building TCP_server.c and TCP_client.c
#
#    Use the 'build.bat' script to invoke.  It sets the Visual Studio
#    environment needed to build.
#
# RUN:
#  nmake /f build.mak
#=============================================================================

CLT_SRC = ..\TCP_client.c

CLT_OBJ = TCP_client.obj

CLT_EXE = TCP_client.exe

SVR_SRC = ..\TCP_server.c

SVR_OBJ = TCP_server.obj

SVR_EXE = TCP_server.exe

ALL_EXE = $(CLT_EXE) $(SVR_EXE)

CC = $(VS_BIN_DIR)\cl.exe

# Define the compiler flags
# /Fo specifies the object file name

COPTS = $(INCL) \
      /D WIN32 /D _DEBUG /D _CONSOLE /D _MBCS /D _WINSOCK_DEPRECATED_NO_WARNINGS \
      /Fo$(OBJ)

BASE_LIBS = kernel32.lib user32.lib  gdi32.lib  winspool.lib \
            comdlg32.lib advapi32.lib shell32.lib ole32.lib  \
            oleaut32.lib uuid.lib    odbc32.lib  odbccp32.lib

LIBS = $(BASE_LIBS) Ws2_32.lib

all: $(ALL_EXE)

$(CLT_EXE): $(CLT_OBJ)
	@echo ^-^-^-^> Link $(CLT_EXE)
	@echo lpath: $(LPATH)
	$(CC) $(CLT_OBJ) /link $(LPATH) $(LIBS) /OUT:$(CLT_EXE)

$(CLT_OBJ): $(CLT_SRC)
	@echo ^-^-^-^> Compile $(CLT_SRC)
	$(CC) $(COPTS) /c $(CLT_SRC)

$(SVR_EXE): $(SVR_OBJ)
	@echo ^-^-^-^> Link $(SVR_EXE)
	@echo lpath: $(LPATH)
	$(CC) $(SVR_OBJ) /link $(LPATH) $(LIBS) /OUT:$(SVR_EXE)

$(SVR_OBJ): $(SVR_SRC)
	@echo ^-^-^-^> Compile $(SVR_SRC)
	$(CC) $(COPTS) /c $(SVR_SRC)

# Clean target: remove intermediate and output files
clean:
	@echo ^-^-^-^> Clean
	@if exist $(CLT_OBJ) del /f /q $(CLT_OBJ)
	@if exist $(CLT_EXE) del /f /q $(CLT_EXE)
	@if exist $(SVR_OBJ) del /f /q $(SVR_OBJ)
	@if exist $(SVR_EXE) del /f /q $(SVR_EXE)

