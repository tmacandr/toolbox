# Qt Data Entry Demo

Part 3 - Define/implement a simple data entry GUI.

Have a base window that has:
```
   Name:
   Age:
   Address:
   City:
   State:
   ZIP:

   Save Reset Exit
```
Implement **slots** for each of the three buttons.

On **Save** collect (read) all the data values to an ASCII text file.

On **Reset** clear each of the _text-fields_.

# Implementation

Did the following:

1. Start **Qt Creator**

   command-line start: qtcreator &

2. Select **Qt Widgets Application**

   ```
      Files to be added in
      $HOME/Programming/toolbox/Qt/02_data_entry/data_entry:

      data_entry.pro
      main.cpp
      mainwindow.cpp
      mainwindow.h
      mainwindow.ui
   ```

3. Oh ... wait ... rename files to 'data_entry'.

3. Select **Forms**

   **data_entry.ui**

   Work layout

   Buttons
   Labels with text-fields

4. Did 'Save All' and the 'Build All' ... and as with the 02 demo, it
   didn't work.

5. So I exit out of **Qt Creator**.

6. Add my own **build.sh**

   Get the error:
   ```
   data_entry.cpp:1:10: fatal error: mainwindow.h:
       No such file or directory 1 | #include "mainwindow.h"
   ```

   So, when I renamed the .ui file and the tool said "rename all files"
   to match ... they don't update the internal references.

   Screw it!  Too tedious.  Delete and start over.

   Wait ... I lose the .ui?

7. Try again:

   ```
   Files to be added in
   /home/tmacandr/Programming/toolbox/Qt/02_data_entry/data_entry:

   data_entry.cpp
   data_entry.h
   data_entry.pro
   data_entry.ui
   main.cpp
   ```

8. I still had to fix the header files.  They didn't have the right
   include to 'ui_data_entry.h' and the name of the object was still
   the generice name, not the 'data_entry' name.

   Once I made the 'fixes', the compile/link worked.

9. Run

   Worked.

10. Implemented the 'exit' button 'slot'.

    When I reloaded into the tool and tried to 'go to' the 'slot', where
    it would be created/added to the 'data_entry.cpp', it bombed saying
    the name of the object was wrong, or some such.

    And so it was.  I still had the main object in the .ui file called
    "MainWindow".  I renamed it to "data_entry" and this broke things
    lose.  Was able to implement the exit 'slot' function.

11. Build/run

    Looks OK now.

# Conclusion

Still don't like this 'in the tool' ... then 'out of the tool' ... then
back 'in' ... then 'out' ... etc.

I'll implement the 'Save' and the 'Reset'.

BTW ... I still don't know what the 'menu' bar is doing there.  The
tool prompts to "type here" ... and then what appears to be a kind
of cascade/root menu button is created.  But otherwise, I can't
figure out what they're heading for.

