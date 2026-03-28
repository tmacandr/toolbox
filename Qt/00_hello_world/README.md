# Introduction to Qt

Showing my age ...

After struggling to try to develop a Tcl GUI for the "Geographic Map
System" (GMS) I ran into a wall.  The GMS is written in C++.  I installed
the **tcl-dev** toolkit.  This allows a Tcl script to call C functions
compiled into a shared (.so) library.  The _problem_ is that the toolkit
**tcl-dev** is C only and can't be used to invoke C++ object code that
has been _name-mangled_ by C++ compilation.  So my idea of using Tcl
scripts to replace my old _X Window System_ applications isn't going
to work.

So I asked **google** flat out.
```
If you were to write a GUI application which would you choose, Qt or Tcl?
```
And the answer came back **Qt**.

Ug.

So off I go ... into the world of **Qt**.

# How to Install Qt on Ubuntu

Again, did a google question on how to install **Qt** on _Ubuntu_ using
`sudo`.

1. **skipped** - Update your package lists

   ```
   sudo apt update
   ```

2. **skipped** - Install essential build tools

   ```
   sudo apt install build-essential
   ```

   I think I already have what's needed.  I hope.

3. Install **Qt Creator and development libraries**.

   I'm picking version Qt **5**.  Though they say **6** is the latest.

   ```
   sudo apt install qtcreator qtbase5-dev qt5-qmake cmake
   ```

4. Install Documentation and examples.  This is _optional_ but I'm going
   to install these because I don't want to keep asking _google_ how
   to do things ... and get into _copyright_ troubles.

   NOTE - This is for version **5**.

   ```
   sudo apt install qt5-doc qtbase5-examples
   ```

# Actual Installation of Qt

Here goes, first the **Qt** toolkit:

   ```
   sudo apt install qtcreator qtbase5-dev qt5-qmake cmake

   Oh wow!  This thing is huge!!

   It's already filled 8 or 9 console pages with "selecting", "unpacking"
   and a bevy of other statements.

   ----------------------------------------------------
Reading package lists... Done
Building dependency tree       
Reading state information... Done
cmake is already the newest version (3.16.3-1ubuntu1.20.04.1).
The following additional packages will be installed:
  binfmt-support clang clang-10 clang-tidy clang-tidy-10 clang-tools-10
  lib32gcc-s1 lib32stdc++6 libc6-i386 libclang-common-10-dev libclang-cpp10
  libclang1-10 libclang1-8 libdouble-conversion3 libegl-dev libffi-dev
  libgl-dev libglu1-mesa-dev libglx-dev libkf5syntaxhighlighting-data
  libkf5syntaxhighlighting5 libllvm10 libllvm8 libncurses-dev libobjc-9-dev
  libobjc4 libomp-10-dev libomp5-10 libpcre2-16-0 libpfm4
  libpthread-stubs0-dev libqbscore1.13 libqt5concurrent5 libqt5core5a
  libqt5dbus5 libqt5designer5 libqt5designercomponents5 libqt5gui5 libqt5help5
  libqt5network5 libqt5opengl5 libqt5opengl5-dev libqt5positioning5
  libqt5printsupport5 libqt5qml5 libqt5quick5 libqt5quicktest5
  libqt5quickwidgets5 libqt5script5 libqt5sensors5 libqt5serialport5
  libqt5sql5 libqt5sql5-sqlite libqt5svg5 libqt5test5 libqt5webchannel5
  libqt5webkit5 libqt5widgets5 libqt5xml5 libqt5xmlpatterns5 libtinfo-dev
  libvulkan-dev libx11-dev libxau-dev libxcb-xinerama0 libxcb-xinput0
  libxcb1-dev libxdmcp-dev libxext-dev libz3-4 libz3-dev llvm-10 llvm-10-dev
  llvm-10-runtime llvm-10-tools python3-pygments qbs-common qdoc-qt5
  qhelpgenerator-qt5 qml-module-qtgraphicaleffects qml-module-qtqml-models2
  qml-module-qtquick-controls qml-module-qtquick-layouts
  qml-module-qtquick-window2 qml-module-qtquick2 qmlscene qt3d5-doc
  qt5-assistant qt5-doc qt5-gtk-platformtheme qt5-qmake-bin
  qt5-qmltooling-plugins qtattributionsscanner-qt5 qtbase5-dev-tools
  qtbase5-doc qtcharts5-doc qtchooser qtconnectivity5-doc qtcreator-data
  qtcreator-doc qtdatavisualization5-doc qtdeclarative5-dev-tools
  qtdeclarative5-doc qtgraphicaleffects5-doc qtlocation5-doc qtmultimedia5-doc
  qtnetworkauth5-doc qtquickcontrols2-5-doc qtquickcontrols5-doc qtscript5-doc
  qtscxml5-doc qtsensors5-doc qtserialbus5-doc qtserialport5-doc qtsvg5-doc
  qttools5-dev-tools qttools5-doc qttranslations5-l10n qtvirtualkeyboard5-doc
  qtwayland5-doc qtwebchannel5-doc qtwebengine5-doc qtwebsockets5-doc
  qtwebview5-doc qtx11extras5-doc qtxmlpatterns5-dev-tools qtxmlpatterns5-doc
  x11proto-core-dev x11proto-dev x11proto-xext-dev xorg-sgml-doctools
  xtrans-dev
Suggested packages:
  clang-10-doc ncurses-doc libomp-10-doc qt5-image-formats-plugins qtwayland5
  libx11-doc libxcb-doc libxext-doc llvm-10-doc python-pygments-doc
  ttf-bitstream-vera default-libmysqlclient-dev firebird-dev libpq-dev
  libsqlite3-dev unixodbc-dev clazy kate-data subversion valgrind
The following NEW packages will be installed:
  binfmt-support clang clang-10 clang-tidy clang-tidy-10 clang-tools-10
  lib32gcc-s1 lib32stdc++6 libc6-i386 libclang-common-10-dev libclang-cpp10

            .
            .
            .
   ----------------------------------------------------

   Now it's grinding out "Setting up" and "Processing" statements, 2 or 3
   more pages.

   ----------------------------------------------------
Fetched 333 MB in 32s (10.2 MB/s)                                              
Extracting templates from packages: 100%
Selecting previously unselected package libdouble-conversion3:amd64.
(Reading database ... 212154 files and directories currently installed.)
Preparing to unpack .../000-libdouble-conversion3_3.1.5-4ubuntu1_amd64.deb ...
Unpacking libdouble-conversion3:amd64 (3.1.5-4ubuntu1) ...
Selecting previously unselected package libpcre2-16-0:amd64.
Preparing to unpack .../001-libpcre2-16-0_10.34-7ubuntu0.1_amd64.deb ...
Unpacking libpcre2-16-0:amd64 (10.34-7ubuntu0.1) ...
Selecting previously unselected package libqt5core5a:amd64.
Preparing to unpack .../002-libqt5core5a_5.12.8+dfsg-0ubuntu2.1_amd64.deb ...
Unpacking libqt5core5a:amd64 (5.12.8+dfsg-0ubuntu2.1) ...

            .
            .
            .
   ----------------------------------------------------

   I intended to copy the whole thing here.  No way.  It'll blow my GitHub
   allotment.

   All told, took about 5 minutes to install.

   Ug ... already getting a bad feeling ... it's too big.
   ```

Next, the documentation.  I'm trying to brace myself for how huge
this might be:

   ```
   sudo apt install qt5-doc qtbase5-examples

   Oh ... just this:

   -----------------------------------------------------
Reading package lists... Done
Building dependency tree       
Reading state information... Done
qt5-doc is already the newest version (5.12.8-0ubuntu1).
qt5-doc set to manually installed.
The following NEW packages will be installed:
  qtbase5-examples
0 upgraded, 1 newly installed, 0 to remove and 45 not upgraded.
Need to get 5,292 kB of archives.
After this operation, 24.4 MB of additional disk space will be used.
Do you want to continue? [Y/n] y
Get:1 http://us.archive.ubuntu.com/ubuntu focal-updates/universe amd64 qtbase5-examples amd64 5.12.8+dfsg-0ubuntu2.1 [5,292 kB]
Fetched 5,292 kB in 1s (5,626 kB/s)           
Selecting previously unselected package qtbase5-examples:amd64.
(Reading database ... 222913 files and directories currently installed.)
Preparing to unpack .../qtbase5-examples_5.12.8+dfsg-0ubuntu2.1_amd64.deb ...
Unpacking qtbase5-examples:amd64 (5.12.8+dfsg-0ubuntu2.1) ...
Setting up qtbase5-examples:amd64 (5.12.8+dfsg-0ubuntu2.1) ...
   -----------------------------------------------------

   ```

## Qt Assistant and Qt Designer

Go to the **Show Applications** multi-button on the far left of the
screen.

Select the **Qt 5 Assistant** and/or the **Qt 5 Designer** icons.

Or !!

In _console_ window, simply type:
```
   qtcreator &
```
Don't forget the `&` so it doesn't lock the console window.

NOTE - It takes a couple of seconds for the IDE to render.  It's a big
puppy.

## Compile

   Include directories:

   See `Makefile`

   Wow ... this looks bad.  The base include directory is:
   ```
   /usr/include/x86_64-linux-gnu/qt5
   ```

   This contains the following sub-directories:
   ```
      QtConcurrent
      QtGui
      QtOpenGLExtensions
      QtSql
      QtXml
      QtCore
      QtNetwork
      QtPlatformHeaders
      QtTest
      QtDBus
      QtOpenGL
      QtPrintSupport
      QtWidgets
   ```

   So this looks massive.

   I notice there's a **QtOpenGL** directory.  Looks like they have an
   **OpenGL** capability.  So **3D** functionality.

   First compilation error:
   ```
      /usr/include/x86_64-linux-gnu/qt5/QtCore/qglobal.h:1187:4:
      error:
      #error "You must build your code with position independent code
              if Qt was built with -reduce-relocations. "
             "Compile your code with -fPIC (-fPIE is not enough)."
      1187 | #  error "You must build your code with position
             independent code if Qt was built with
             -reduce-relocations.
   ```
   Um ... OK ... I guess to `sudo` installation picked a
   **-reduce-relocations** option ... whatever that is.

   OK ... got it to compile.  Have `hello_world.o`

## Link

   This looks worse!  The base path to a massive amount of shared
   libraries is:

   ```
      /usr/lib/x86_64-linux-gnu
   ```

   I'm going blind trying to find all the **Qt** libraries there.

   First link error:
   ```
   /usr/bin/ld:
   hello_world.o: undefined reference to symbol
   '_ZN10QArrayData10deallocateEPS_mm@@Qt_5'
   /usr/bin/ld: /lib/x86_64-linux-gnu/libQt5Core.so.5:
   error adding symbols: DSO missing from command line
   ```

   Ug ... what does that mean?

   Oh ... **google** page says I have to build a **project** file.

   Have to run:
   ```
   qmake
   ```

   So, reading the **Qt Assistant**, _Getting Started_ page:

   1. Define a _project_ file:

      ```
         QT += widgets
         SOURCES += hello_world.cpp
         TARGET = hello_world.exe      
      ```

   2. Run **qmake** tool to **generate** a **Makefile**:

      ```
         qmake -o Makefile hello.pro
      ```

   3. Then run the **Makefile**

This worked!

Wow ... what an ugly GUI.  But it's a start, I guess.

Had to convert my `Makefile` to `build.sh`.  Add the above steps
to the script.  The 'Makefile' is generated by the `qmake` tool,
so I can't have my own 'Makefile'.

Defined **build.sh** to consolidate the build procedure.

Not sure that I like it.  Having to run the **qmake** tool means
that the **Qt** build mechanics are so dang complicated that
the **qmake** tool is required to set everything up.  I can't
have my own Makefile, etc.
 
