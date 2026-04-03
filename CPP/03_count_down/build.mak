#=============================================================================
# FILE: build.mak
#
# DESCRIPTION:
#    Visual Studio NMAKE file for building count_down.cpp
#
#    Use the 'build.bat' script to invoke.  It sets the Visual Studio
#    environment needed to build.
#
# RUN:
#   nmake /f build.mak
#=============================================================================

SRC = count_down.cpp

OBJ = count_down.obj

EXE = count_down.exe

CC = $(VS_BIN_DIR)\cl.exe

# Define the compiler flags
# /Fo specifies the object file name

COPTS = $(INCL) \
       /D WIN32 /D _DEBUG /D _CONSOLE \
       /D _MBCS /D _WINSOCK_DEPRECATED_NO_WARNINGS \
       /EHsc    \
       /Fo$(OBJ)

#
# C link libs
#
BASE_LIBS = kernel32.lib user32.lib   gdi32.lib   winspool.lib \
            comdlg32.lib advapi32.lib shell32.lib ole32.lib    \
            oleaut32.lib uuid.lib     odbc32.lib  odbccp32.lib

#
# C++ link libs
#    ucrtd.lib
#    vcruntimed.lib
#

CPP_LIBS = msvcrtd.lib

LIBS = $(BASE_LIBS) $(CPP_LIBS) Ws2_32.lib

#
# Avoid warning LNK4098:
#       defaultlib 'LIBCMT' conflicts with use of other libs
#

LINK_OPTS = /NODEFAULTLIB:LIBCMT

all: $(EXE)

$(EXE): $(OBJ)
	@echo ^-^-^-^> Link $(EXE)
	@echo lpath: $(LPATH)
	$(CC) $(OBJ) /link $(LPATH) $(LIBS) /OUT:$(EXE) $(LINK_OPTS)

$(OBJ): $(SRC)
	@echo ^-^-^-^> Compile $(SRC)
	$(CC) $(COPTS) /c $(SRC)

# Clean target: remove intermediate and output files
clean:
	@echo ^-^-^-^> Clean
	@if exist $(OBJ) del /f /q $(OBJ)
	@if exist $(EXE) del /f /q $(EXE)
