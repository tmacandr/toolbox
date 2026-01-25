# How to Call C Functions from a Tcl Script

Want to define a simple demo where a Tcl script calls C functions.

## Introduction

Was hoping that I could separate the GUI and parsing mechanics to the Tcl
script and the "grind" work (e.g. math) to the C functions.

What I didn't expect is that Tcl is a rather "closed" system.  And the only
way to make it happen is by installing an "interface" packagae that allows
a Tcl script to access the C functions.

I thought the approach would be to 'archive' a set of C functions in a system
file (e.g. libcfuncs.a or .so) and there would be some magical Tcl mechanism
(built-in) that would somehow 'load' the .a (or .so) file and then access
the object code of the C code.

I had dreams of 'pragma interface "C"'.

But no such luck.

To connect Tcl to C object code an "interface" package has to be used.  There
seems to be several implementations:

   1. native Tcl C API
   2. Critcl - Compiled Runtime In Tcl
   3. SWIG - Simplified Wrapper and Interface Generator
   4. tcl-cffi - Foreign Function Interface for Tcl

At this point, I have no idea which is the easiest to use, easiest to install,
whether they're portable between Windows and Linux, or even if any or all are
'proprietary'.  Not looking forward to installing yet another package on my
Linux.

## Interface Package

Native Tcl C API:
Linux (Debian/Ubuntu):
    It is provided by packages such as tcl8.6-dev or tcl-dev.

Linux (Red Hat/CentOS/Fedora):
    It is provided by the tcl-devel package.

Source Code:
    If Tcl is built from source, tcl.h is located in the generic
    directory of the source tree (e.g., tcl/generic/tcl.h). 

If a build fails with this error, it means you need to install the
development package, not just the Tcl interpreter.

    Ubuntu/Debian: sudo apt-get install tcl-dev
    CentOS/RHEL: sudo dnf install tcl-devel 

If the file is installed but not found by the compiler, you may need to add
the path to your compiler flags, for example:

          -I/usr/include/tcl8.6

# References

1. Swig https://wiki.tcl-lang.org/page/Swig

2. Ctritcl https://wiki.tcl-lang.org/page/Critcl

3. cffi https://wiki.tcl-lang.org/page/CFFI+Package

4. Native Tcl C API

