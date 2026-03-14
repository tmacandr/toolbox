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

## Notes

Once upon a time I did a:
```
   sudo apt install tcl
```
and I got Tcl 8.6.
```
   tclsh
   puts $tcl_version
```
And I guess I just trusted `Ubuntu` to install some official Tcl.  But Tcl
is (to this day) an **open-source** product maintained by what Google
describes as a **Core Tcl Group**.  I guess they control any advances,
changes, addendums, etc to the language and products.

And the versions are kept in **SourceForge**.

So I think Ubuntu, used:
```
https://sourceforge.net/projects/tcl/files/Tcl/8.6.0/
```

By-the-way, I see that Ubuntu uses the list from:
```
   /etc/apt/sources.list
```
when searching for (and downloading) items via `sudo apt install <pkg>`.

Which is a double-pointer mechanism.  The `sources.list` file points
to `Ubuntu` sites, which in turn have lists of sites to download packages.

I should pay more attention.

I'm getting off topic ...

## Tcl to C Interface Options

To connect Tcl to C object code an "interface" package has to be used.  There
seems to be several implementations:

   1. Native Tcl C API

      But this is a mechanism for embedding Tcl in C programs.

      This is the opposite of what I want to do.  I want Tcl to call
      C functions.

      https://wiki.tcl-lang.org/page/Tcl+C+API

   2. Critcl - Compiled Runtime In Tcl

      This is a Tcl package, that I guess (also) has to be downloaded,
      that allows one to write Tcl scripts in which there are Tcl-like
      procedures, but the body of these are written in C.

      Then, the Tcl script (file) is 'compiled' by the 'critcl' compiler
      to generate a Tcl package that can be loaded by a base Tcl script.

      In this case it's as if one is writting a file that is both Tcl
      and C.

      The base web page is:

         https://wiki.tcl-lang.org/page/
                  Accessing+C+library+functions+using+Critcl

      It doesn't give an example of how the generated "pkg" is used.
 
   3. SWIG - Simplified Wrapper and Interface Generator

      As it says, "Generator", this appears to be a tool that reads in
      C code functions and auto-generates a bunch of C wrapper code
      that can then be called by a Tcl script.

      I think it's an attempt to hide the ugliness of what it takes
      to make a C function callable from Tcl.

      See:

         https://wiki.tcl-lang.org/page/Swig

      Not sure this is what I want either.  On the one hand, I'm not sure
      I want to spend time learning how to use a tool that "hides"
      everything while trying to come up to speed on how to use it.

      But on the other hand, if things start to get complicated do I have
      to know all the nuances of the Tcl C API package 'tcl-dev' (that I
      have to install whether I use SWIG or not) to figure out what's
      going on.

      Not sure if it's a help or makes things clunky.
 
   4. tcl-cffi - Foreign Function Interface for Tcl

      I'm not sure if this is an addendum or outright alternative to the Tcl
      extension package 'tcl-dev'.

      It has a different approach, but basically the same mechanics as
      'tcl-dev'.  One has to download/install a 'cffi' package.

      Well, maybe it's better in that one doesn't have to clutter the C
      code with all this 'tcl.h' rigmarole to make the connection work.
      It seems the 'cffi' package is able to figure out the C interface
      from the Tcl code, not the C code.

      But I'm a little leary about its pedigree.  It's from a GitHub site:

                https://github.com/apnadkarni/tcl-cffi

      Like, who is 'apnadkarni'?

      His GitHub site is quite extensive ... massive ... dense with Tcl
      work ... from 2012 to 2025.

      Apparently, his name is "Ashok P. Nadkarni" and is a "software
      developer and auther associated with numerous open-source projects".

      OK.

      But Tcl itself is an "open-ware" product ... not officially
      maintained by a group such as ANSI or ISO.

      There's a "soure forge" database of 'tcl-cffi' too.

At this point, I have no idea which is the easiest to use, easiest to install,
whether they're portable between Windows and Linux, or even if any or all are
'proprietary'.  Not looking forward to installing yet another package on my
Linux.

## What To Do

I guess what I'm going to do is (trust?) Ubuntu to download a good version
of the `tcl-dev` package and add it to my `tcl` installation (which is,
as of this writing, version 8.6).

Then, I'll grind through the mechanics of modifying the C code so that it
brings in all the Tcl API mechanics so that one or more C functions can
then be called by my (simple?) Tcl script.

Basically, I'm going to try and implement the "hello world" demo given from:
```
   https://wiki.tcl-lang.org/page/Hello+World+as+a+C+extension
```

## Steps:

Tried the following:

1. Install 'tcl-dev'

   ```
   sudo apt install tcl-dev
   [sudo] password for <who-am-i>:
   Reading package lists... Done
   Building dependency tree       
   Reading state information... Done
   The following additional packages will be installed:
     tcl8.6-dev
   Suggested packages:
     tcl-doc tcl8.6-doc
   The following NEW packages will be installed:
     tcl-dev tcl8.6-dev
   0 upgraded, 2 newly installed, 0 to remove and 45 not upgraded.
   Need to get 911 kB of archives.
   After this operation, 4,797 kB of additional disk space will be used.
   Do you want to continue? [Y/n] y
   Get:1 http://us.archive.ubuntu.com/ubuntu focal/main amd64 
              tcl8.6-dev amd64 8.6.10+dfsg-1 [905 kB]
   Get:2 http://us.archive.ubuntu.com/ubuntu focal/universe amd64 
              tcl-dev amd64 8.6.9+1 [5,760 B]
   Fetched 911 kB in 1s (1,568 kB/s)   
   Selecting previously unselected package tcl8.6-dev:amd64.
   (Reading database ... 212070 files and directories currently installed.)
   Preparing to unpack .../tcl8.6-dev_8.6.10+dfsg-1_amd64.deb ...
   Unpacking tcl8.6-dev:amd64 (8.6.10+dfsg-1) ...
   Selecting previously unselected package tcl-dev:amd64.
   Preparing to unpack .../tcl-dev_8.6.9+1_amd64.deb ...
   Unpacking tcl-dev:amd64 (8.6.9+1) ...
   Setting up tcl8.6-dev:amd64 (8.6.10+dfsg-1) ...
   Setting up tcl-dev:amd64 (8.6.9+1) ...
   Processing triggers for man-db (2.9.1-1) ...
   ```

2. Check:
   ```
   ls /usr/include/tcl8.6
   ```

3. Modify C Code

   Well ... this was kind of a grind.

   Things to consider ... trade-offs:
   
   a. There's one "init" function that performs the mapping of
      callable C functions to the Tcl interpreter.

   b. All the 'signatures' of the C functions get lost!

      For example, the following: 
      ```
         int get_integer(void);
      ```
      Had to be re-written as:
      ```
         int get_integer(ClientData clientData, 
                         Tcl_Interp *interp, 
                         int        argc,
                         const char *argv[]); 
      ```
      So, the "signature" of the C functions have to be "understood" by
      the caller before-hand.  There's no enforcement of argument or
      return semantics by the compiler.  Gone!

      In this case, the signature was `void`.  But if a more sophisticated
      function is written, the caller has to "understand" what arguemnts
      to pass.  And if they're wrong, you won't know till run-time.  Or
      worse, they're processed but interpreted in a WRONG way.

   c. All return signatures are lost.  All C functions called by a Tcl
      script return an `int`, which is a status value such as `TCL_OK`
      or `TCL_ERROR`.

      But the actual return value is processed via a Tcl dev function
      called
      ```
         Tcl_SetObjResult()
      ```
      which I haven't implemented yet.

   d. More notes

3. Modify the **Makefile**

   Had to:
   a. Convert the archive .a to a shared lib .so

   b. Use macro
      ```
      -DUSE_TCL_STUBS
      ```
   c. Expand include path to:
      ```
      -I/usr/include/tcl8.6
      ```
      Though I'm not really sure this was needed.  It might now be
      in the default include paths of `gcc` when the `tcl-dev` was installed
      via `sudo apt install`.  Should check this.

    d. Had to specify **Position Independent Code** (PIC) option on compile.
       Otherwise, the linker states:
       ```
          /usr/bin/ld: c_functions.o:
             relocation R_X86_64_PC32 against symbol `get_integer' can not
             be used when making a shared object; recompile with -fPIC
             /usr/bin/ld: final link failed: bad value
       ```
       Thus, specify `gcc` option:
       ```
         -fPIC
       ```

    d. Specify link path:
       ```
       -L/usr/lib/x86_64-linux-gnu
       ```

    e. Specify the link library:
       ```
       -ltclstub8.6.a
       ```

4. Modify Tcl script

   Add to the Tcl script `call_C.tcl`
   ```
      load lib/libc_func[info sharedlibextension]

      get_integer
   ```

5. Run

   Failed with:
   ```
      cannot find symbol "C_func_Init": lib/libc_func.so:
      undefined symbol: _C_func_Init
      while executing
            "load lib/libc_func[info sharedlibextension]"
      (file "call_C.tcl" line 32)
   ```

6. Fixes

   The name of the **INIT** function must be:
   ```
      C_func_Init
   ```

   Apparently there's a protocol here where, since the name of the
   shared library is `libc_func.so`, then the name of the init
   function must be:
   ```
         C_func_Init
   ```

7. Run

   WORKED!!!

# Discussion

Expanded the three C functions to return 'results'.  And things got
messy.

   1. Input arguments

      Arguments, it appears, can only be scalar values (char, int,
      float, etc) but no matter the type, the value is converted
      to (ASCII) string.

      Then, the agruments are passed to the C function as the
      typical:
      ```
         int argc, char **argv
      ```

      So the C function has to convert the given argument from
      string (back) to the original scalar type.

      So complex structures can't be passed.  Or, at least I'm not
      seeing a mechanism to do so.

   2. Return value

      The protocol seems to be:
      ```
         Tcl_Obj *result_obj;

         result_obj = Tcl_New<TYPE>Obj(<result>, [other args]);

         Tcl_SetObjResult(interp, result_obj);
      ```

      Then the protcol in the Tcl code is:
      ```
         set answer [<C_function_name <arg1> ... <argN>]
      ```

      The <Type> can be Int, Double (there's no 'float'), String, etc.

   3. Output arguments.

      And there are no 'out' arguments.

At this point, I'll close this effort out.  It shows the basic
mechanics of how to pass arguments from a Tcl script to a C function
and then receive the results.

But that said, the idea (goal) of passing complex objects, such as
a drawing pallette, to C functions to do complex processing doesn't
seem to be possible.

Couple more things:

   1. I didn't discuss/cover the mechanics associated with the
      `Tcl_CmdDeleteProc()` callback.  When the function
      ```
         Tcl_CmdDelete()
      ```
      is called the corresponding callback(s) are invoked to
      deallocate resources.

      But I'm not sure how or when the `Tcl_CmdDelete()` is done.
      Maybe there's supposed to be a 'clean-up' C-function analogous
      to the `C_func_Init()`.  But it's called somewhere in the Tcl
      script, whereas the `C_func_Init()` is invoked (for free) when
      `load <lib>[info sharedlibextension]` is invoked.

   2. I'm not sure about how memory allocated in a C function
      (e.g. a char * buffer) is to be deallocated once the
      `Tcl_SetObjResult()` is called and the C function returns.

      Seems it could be an easy way to cause memory leaks.

# References

1. Swig https://wiki.tcl-lang.org/page/Swig

2. Ctritcl https://wiki.tcl-lang.org/page/Critcl

3. cffi https://wiki.tcl-lang.org/page/CFFI+Package

4. Native Tcl C API

