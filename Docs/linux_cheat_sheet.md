# Linux Commands and Utilities

Boot configuration
```
   /etc/inittab
```

## User Commands

```
   cd <dir>     - change current directory to <dir>
   ls           - list contenst of directory
   pwd          - print working directory
   rm <file>    - Remove (delete) <file>
   mkdir        - create a new directory
   rmdir        - remove (delete) an EMPTY directory
   cp <f1> <f2> - Copy file <f1> to file <f2>
   mv <f1> <f2> - Move (rename) file <f1> to file <f2>
   cat <f1> .. <fn> <ff> - concatenate files <f1> .. <fn> into file <ff>
   more <f1>      - display the contents of <f1> in page segments from TOP
   less <f1>      - display the contents of <f1> in page segments from BOTTOM
   tail <f1>      - Show (continuous) end of file, even as it is updated
   tee <f>        - direct <stdout> to both console and specified file
   touch <f1>     - make a new, empty file <f1> or change time-stamp
                    of <f1> to current date/time
   chown <u> <f1> - Change owner of <f1> to user <u>
   chgrp <g> <f1> - Change group of <f1> to group <g>
   chmod <p> <f1> - Change privileges of <f1> to settings <p>
   sort <f1>      - Sort contents of <f1> (sent to <stdout>)
   echo           - Repeat what is typed at console
   date
   cut <f>        - Break a large file into multiple smaller files
   sed            - Stream editor
   ln <t> <f>     - Create a 'soft-link' from file <f> to file <t>
   grep           - 'global regular expression' search 
   passwd         - change user's own password
```

Old **Linux 6.0**
```
   mouseconfig
   timeconfig
   Xconfigurator
```

## Admin Commands

```
   mount   - Mount a file system (disk, USB, etc) 
             Map a device (disk, USB, etc) to the OS 'file-system'
   unmount - Unmount a file-system
   fsck    - Check status/integrity of file-system
   mkfs    - Make (create) a directory system on a device (disk, USB, etc)
   shutdown -h now - Power-down entire system now ... no warnings to
                     users, -h for 'halt'
   vmstat   - Show status of virtual memory performance
   procinfo - Show information on a process
   useradd  - Add a new 'user' to the system
   passwd   - Change any <user> password (including root)
```

**X Window System**
```
   Red Hat 7.0  and later uses base X Window system but does not provide
   access to X/Xt/Xm tools or development.  It is essentially deprecated
   for 'community' usage.

   But it appears X is still the underlying graphics base for 'gnome'
   and Linux graphics. 

   Need to investigate the history of this.

   See FreeX86.com and X.org
```
That said `startx` is still in `/usr/bin/startx`.

And `xterm` can be installed via `sudo apt install`.

To terminate `X Server`
```
   <ctrl><alt><backspace>
```

**Linux 6.0**
```
   SuperProbe
   startx - Start X Server
```

## Editors

```
   ed
   ex
   vi
   vim
   xedit
   emacs
```

### vim (vi) Commands

Edit Commands:
```
   i - insert mode
   I - insert at beginning of line
   a - insert after current pos
   A - insert at end-of-line
   <esc> - go to command mode 
   x - delete current char
   cw - delete word and enter insert mode
   dw - delete word
   <esc> - end insert mode, go to command mode
```

Command Mode:
```
   :w - write to current file
   :q - quit
   :wq - write to current file and then quit
   :q! - quit without saving, supress prompt to 'save'
   /<string> - find <string> in file (FORWARD search)
   ?<string> - find <string> in file (REVERSE search)
   n         - find next <string>
   u         - undo last edit
   <ctrl> r  - redo last edit
```

