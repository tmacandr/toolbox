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

So off I go ... into the world of *Qt**.

# Installation of Qt on Ubuntu

