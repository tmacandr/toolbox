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

