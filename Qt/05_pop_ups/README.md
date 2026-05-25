# Pop-up Dialogs Demo

The goal of this project is to demonstrate how to show (pop-up) dialog
windows from a main GUI display.

I thought it wouldn't be too bad, using that **Qt Creator** tool.
But it quickly spun out of control.

## Attempt  1 - Qt Creator

The first approach was to define a base GUI using the **QT Creator** tool.
It had a base button and a couple of menu-bar buttons.  Each of the `slot`
functions for the buttons would pop-up a different dialog.  Each dialog
in turn would have a button or two ... do some 'dilly-dally' work, and
then have an `exit` button.

I thought I could use the `Qt Creator` tool to create the base window,
which I did.  But then also use it to create the three different
(pop-up) dialogs.  After creating the base window, the code, the `slot`
functions, etc ... got that all working ... an attempt was made to create
the dialogs.  And that's when thing began to fall apart.

The **Qt Creator** tool has no intuitive mechanism to create dialogs.  Well,
I at least struggled mightily to find some mechanism, and couldn't find
any.

## Attempt 2 - QDialog

I did a *google* query on how to pop-up a dialog in **Qt**.  It came back
with some example code using a class called **QDialog**.  So, following
the demo (bare-bones) code, and without doing any real (in-depth) research
about this class, I just *went for it*.

And sure enough I got three little dialogs to pop-up when each of the three
buttons were selected.

Yay!

But there was nothing there.  They were empty shells.  There was a banner
at the top (with no title) and the standar **X** exit button at the upper
left ... but that was it.

It was looking like a really tough job to keep going.

## Attempt 3 - Copy the .ui File

So I thought I'll just copy the **.ui** file that defies the  base window
and implement the first dialog window by editing the contents from the
base window.

The **.ui** file is a quasi **XML** file that declares and defines the
base **widget** and attributes of a window.

This was where **X/Xt/Xm** was heading when I bailed on GUI programming
back in the 1990s.  It was getting to the point where one didn't need
to be an *engineer* to do GUI applications.  Some editing of template
files was all that was need to define even the most sophisticated
GUIs.  I saw the *writing on the wall*.

So, 25 years later, I'm full circle and trying to define a GUI using
**XML**.

And after coming up with (admittedly) an ugly dialog definition, and
named the file `dialog_1_window.ui`, the next step was to figure out
how to *load* this file, process the contents, attach the needed
*slot* functions, and actually pop it up at run time.

So I went to `google` and asked how to load **.ui** files *programmatically*.
It gave some example code on how to load the *.ui* file and render it.

But all I got was misery.  I tried to use the C++ code for the base window
as a *template* (so to speak) assuming the class definition and the naming
convention in the *.ui* file should be the same.  This gave me a bevy of
compilation errors.

Also, **google** gave some example code that uses these two classes
called **QUiLoader** and **QFile**.  These are the base mechanisms to load
the **.ui** file, parse the (quasi XML) content, and then render the
contents.

And I struggled mightily to figure out why the compiler couldn't find the
**QUiLoader** class.  It turned out the first problem was that when I asked
the question to *google*, then answer came back for *Qt* **Version 6**, which
is the latest and *google* assumes everybody is using.  But I installed
*Qt* **Version 5**.  Ug.

But still **QUiLoader** is still in **Qt 5**.  But it's part of an *off*
area of the base installation.  And I couldn't figure it out.

## Attempt 4  - All Programmatically

I thought, "OK ... I'll go dinasaur" and write gobs of code to both
define/create the dialogs, the sub-widgets (including the buttons), then
pop-up the dialogs, respond to user operations (button clicks), and then
finally `exit`.

This was to be `Attempt 1 - QDialog` on steriods ...

I was all prepared to go this approach and then thought this is just **not**
the right approach.  While I'm sure it would work, the amount of time it
would take me to read all the `help` information from the **Qt Assistant**
tool would probably take me months before I was *done*.

So I gave up on this approach before even really trying.

## Attempt 5 - Back to QUiLoader

And so after giving up on #4 I thought I'd better give that **QUiLoader**
thing another try.  There must've been something (or several?) that I
missed.

Ug ... this failed because I finally asked **google** why I was getting build
errors.  It said
```
   the Qt UI Tools development library is not installed on your system or
   the environment is not configured to find it. Unlike core modules, uitools
   is often a separate package.
```
... which I think came from **Stack Overflow**.

So ... abandon ship here too ...

## Final - Attempt 6 - 'qtcreator',  Build Control Code from Scratch

Finally went with this ... though maybe a `Qt` purist wouldn't buy into this.

I used the `qtcreator` tool to define a base project.  Per below, the base
window is defined in the **.ui** file (which will be generated by the
_qtcreator_ tool).

The base project is generated, built, and run.

Then the _qtcreator_ tool is started and a second dialog window is created
using the *File-->New* process.  The components of this second dialog are
saved to a second **.ui** file.

At this point, a C++ class is created to manage this first dialog.  But
the **problem** is that, even though the hand-written C++ files are
added to the project (so that they are part of the build) I wasn't able
to figure out how to 'incorporate' the C++ package into the _qtcreator_
tool so that it would sync with the corresponding _.ui_ file.  The
intent was, that by doing so, I could use the tool to create the **slot**
functions for the buttons on the dialog.  I was hoping that at least
this part wouldn't have to be _manual_.

Actually, I should back up.  What I was orignally _not_ able to do was to
create the second dialog **AND** have the tool generate the control
(C++) code for the dialog ... as it does for the _main_ window.  On the
one hand it may be that I missed it somehow in the tool ... but on the
other hand, why is it so difficult to do something so basic.

Then, for the other two dialogs, I basically repeated the process that
was used to create the first dialog.  An overview of the process is
as follows:

   1. Generate new dialog using _File->New_ and generate a
      new **.ui** file

   2. Have the tool generate the corresponding graphics
      generation code.

   3. Write (from scratch) a C++ class to manage the new **.ui**,
      using the code that was generated in step (2).

   4. Add the (hand-written) C++ package to the project file.

   5. Repeat (3) and (4) for any other needed dialogs.

A **example** is given below.  It creates a `main` window (steps
1 and 2) and then creates three pop-up dialogs (steps 3 and 4).

The specific steps are as follows:

   1. From an empty directory, start Qt Creator
      ```
      (a) qtcreator &

      (b) Create a new project: 'pop_up_demo'

          (i) File-->New File or Project

          (ii) Select from "Projects" area

               Select "Application"

               Select "Qt Widgets Application"

               Select "Choose" button (at bottom right)

          (iii) Project Location:

               Name: pop_up_demo

               Browse to location:  <project-directory>

               Next>

          (iv) Build System: qmake

               Next>

          (v) Class Information:

              Class name: pop_up_demo_Main_Window
              Base class: QMainWindow

              Header file: pop_up_demo_main_window.h
              Source file: pop_up_demo_main_window.cpp

              Generate form: <check>

              Form file: pop_up_demo_main_window.ui

              Next>

          (vi) Translation File:

              Next>

          (vii) Kit Selection

              Next>

          (viii) Project Management

              Add to version control: <none>  <-- I'll take care of this later

              Finish>
      ```

      Note - compile errors and/or warnings will probably be shown in the
      generated code.  Ignore for now.

   2. Build main GUI window
      ```
      (a) In the "Projects" pane expand the "pop_up_demo [main]" (it may
          already be expanded).

      (b) Select/expand "Forms"

      (c) Edit

          Double-click: 'pop_up_demo_main_window.ui' on tool canvas ...

          (i) Define "File" menu bar button

              Define "File-->Dialog 1 ... button

              Define "File-->Exit button

          (ii) Define a menu-bar button "More"

              Define a "More-->Dialog 2 ..." button

          (iii) On main widget canvas:

               Select the "Push Button" from the palette on the left

               Drag-and-drop on the main canvas

               Set the text of the button to: "Dialog 3 ..."

               Change Object Name: "dialog_3_button"

               Select "Go to slot ..." from pop-up menu

               Select <QAbstractButton>-->clicked()
      ```
      This creates a **slot** (callback) function called:

          **pop_up_demo_Main_Window::on_dialog_3_button_clicked()**

      Be sure to add `<iostream>` at the top ... and add a `std::cout`
      statement to the `slot` function.
      ```
          (iv) Save all

               File-->Save all
      ```

   3. Build Project:
      ```
      Build-->Build All

          ignore the (many) errors ...

      File-->Save all 

      File-->Exit
      ```

   4. Out-of-tool clean up.
      ```
          cd pop_up_demo

          mv * ..

          cd ..

          rmdir pop_up_demo

          rm -Rf build-pop_up_demo-Desktop-Debug
      ```

   5. Define **build.sh** script for command-line **qmake** build process:
      ```
        ---------------------------------------------
        #!/bin/bash

        qmake -o Makefile pop_up_demo.pro

        make clean

        make
        ---------------------------------------------
      ```

   6. First Build and Run:
      ```
      (a) build.sh

      (b) Run:

             pop_up_demo

          Verify GUI ... e.g. output from Dialog 3 button (only), etc
      ```

   7. Implement **action** functions:

      Add `connect()` for `Dialog 1`, `Exit`, and `Dialog 2` buttons
      that are off the main menu-bar

      Add `action` (callback) functions to class header.

      Now, these might not need to be added to the **private slots:**
      section of the `class`, but they are placed there to indicate
      they're a kind of `slot` function:

      Edit: **pop_up_demo_main_window.h**

      ```
           ------------------------------------------------------
           private slots:
               void on_dialog_3_button_clicked(); // <-- already defined

               void dialog_1_action_slot();

               void exit_action_slot();

               void dialog_2_action_slot();
           ------------------------------------------------------
      ```
      Implement `connect()` mechanics in the constructor

      Edit: **pop_up_demo_main_window.cpp**

      **AFTER** the `ui->setupUi(this);` add the following:
      ```
           ------------------------------------------------------
           connect(ui->actionDialog_1,
                   &QAction::triggered,
                   this,
                   &pop_up_demo_Main_Window::dialog_1_action_slot);

           connect(ui->actionExit,
                   &QAction::triggered,
                   this,
                   &pop_up_demo_Main_Window::exit_action_slot);

           connect(ui->actionDialog_2,
                   &QAction::triggered,
                   this,
                   &pop_up_demo_Main_Window::dialog_2_action_slot);
           ------------------------------------------------------
      ```

      Implement stubs for the `action` functions:

      Verify the `#include <iostream>`
      ```
           ------------------------------------------------------
           void pop_up_demo_Main_Window::dialog_1_action_slot()
           {   
               std::cout << "pop up 1\n";
           }

           void pop_up_demo_Main_Window::exit_action_slot()
           {
               std::exit(0);
           }

           void pop_up_demo_Main_Window::dialog_2_action_slot()
           {
               std::cout << "pop up 2\n";
           }
           ------------------------------------------------------
      ```
      Remember, the `on_dialog_3_button_clicked()` was already implemented
      by the **qtcreator** tool.

   8. Verify Build

      You can run the `Makefile` at this point, since no new files have been
      added to the project.
      ```
         make

         run:  

            pop_up_demo
      ```

      Verify `slot` and `action` functions.

   9. Begin Definition of **Dialog 1** Window

      (a) Start QtCreator
          ```
          qtcreator pop_up_demo.pro &
          ```

      (b) Select `File-->New File or Project`
          ``` 
          From the "Files and Classes" pane, select

              "Qt"

          From the middle pane then select:

                "Qt Designer Form Class" ("ui" icon)

          Select "Choose ..." to advance to the 'wizard' process ...
          ```

      (c) Follow steps of the Wizard:
          ``` 
          (i) Chose a Form Template

              Select "Dialog with Buttons Bottom"

              This will give a dialog with 'Cancel' and 'OK' buttons
              where the 'slot' functions are implemented for "free".

              There's no editable code generated for these 'slot'
              functions.  But they do 'opererate'.  The "cancel"
              is fine, but to capture the "OK" button, see below.

              Next>

          (ii) Name: dialog_1.ui

              Path: <same as project location>

              Next>

          (iii) Project Management:

              Add to project: pop_up_demo.pro

              Add to version control:  <NONE>  <--- Again, I'll work this later

              Finish
          ```

      (d) Define GUI
          ```
             Select the 'canvas' and the select 'Change objectName...'

             Set name to: Dialog_1_Window

             Add "Push Button" from palette (drag-and-drop)

             Change text:  "Push 1"

             Change Object Name: "dialog_1_push_1"
          ```

      (e) "Save All" ... 

      (f) Select the "Rebuild All" button.  I'm not sure, but I think this
          is where/when the tool generates the GUI definition file:

                    dialog_1.ui

      (g) Select "Save All" again

      (h) Now, 'exit' the 'qtcreator'
          ```
          ------------------------------------------------------
          NOTE:
             If you select "Go to slot-->QAbstractButton:clicked()

             a error dialog pops up saying:

                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                "No documents matching "ui_dialog_1.h" could be found.
                 Rebuilding the project might help."
                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

             It doesn't.
          ------------------------------------------------------
          ```

          But, as described below, when the **build.sh** is run, the
          tool generates a file with just that name (**ui_dialog_1.h**).
          It contains all the C++ commands to build and render the
          `dialog_1` window.

          So, the error pop-up is quite confusing ... and thus the source
          of my frustration with the **Qt Creator** tool.

   10. Clean and re-build the project

       Must invoke **build.sh** so the `ui_dialog_1.h` is generated.

       ```
       (i) make clean

       (ii) build.sh
       ```
       Verify that a GUI file called **ui_dialog_1.h** has been generated.

       This file contains the `class` named **Ui_Dialog_1_Window**.  It
       implements all the functionality to create the `dialog_1` window.

   11. Create new `class` - **dialog_1.h**

       This new package will be used to instantiate/create the GUI components
       from the generated file **ui_dialog_1.h**.

       Open the file `ui_dialog_1.h` and verify that the name of the `class`
       is
       ```
                   Ui_Dialog_1_Window
       ```

       Create a file: **dialog_1.h**
       ```
       ------------------------------------------------
       #ifndef DIALOG_1_WINDOW_H
       #define DIALOG_1_WINDOW_H

       // ATTEN - None of that 'namespace' stuff here.
       //         Do a direct 'include' to the 'ui' header file
       #include <QDialog>

       #include "ui_dialog_1.h" // <-- Generated by qtcreator from dialog_1.ui

       // Per ui definition, inherit from 'QDialog' class/widget
       class Dialog_1_Window : public QDialog
       {
           Q_OBJECT

       public:
           Dialog_1_Window(QWidget *parent = nullptr);
           ~Dialog_1_Window();

       private slots:

       private:
           Ui_Dialog_1_Window *ui;   // <--- Class declared in 'ui_dialog_1.h
       };
       #endif // DIALOG_1_WINDOW_H
       ------------------------------------------------
       ```

       Create body - **dialog_1.cpp**
       ```
       ------------------------------------------------
       #include <iostream>

       #include <QPushButton>

       #include "dialog_1.h"

       Dialog_1_Window::Dialog_1_Window(QWidget *parent)

           : QDialog(parent),
             ui(new Ui_Dialog_1_Window)  // <-- Again, no 'namespace' stuff

       {
           ui->setupUi(this);
       }

       Dialog_1_Window::~Dialog_1_Window()
       {
           delete ui;
       }
       ------------------------------------------------
       ```

   12. Add new class `dialog_1.h/.cpp` to the project:

       Edit: **pop_up_demo.pro**

       Add:
       ```
       ------------------------------------------------
       SOURCES += \
           main.cpp \
           pop_up_demo_main_window.cpp \
           dialog_1.cpp

       HEADERS += \
           pop_up_demo_main_window.h \
           dialog_1.h
       ------------------------------------------------
       ```

       Build

       In this case, do a `make clean` first

       Then: **build.sh**

       Verify no compile errors or undefined symbols.

       But don't need to _run_ ... nothing is connected yet ...

   13. Add the **Dialog_1_Window** class to the `pop_up_demo_Main_Window`.

       Edit: **pop_up_demo_main_window.h**
       ```
       ------------------------------------------------
       #include <QMainWindow>  // <-- add after QMainWidow

       #include "dialog_1.h"
               .
               .
               .
       private:
           Ui::pop_up_demo_Main_Window *ui;

           Dialog_1_Window *dialog_1 = nullptr;
       ------------------------------------------------
       ```

       Edit: **pop_up_demo_main_window.cpp**

       Add the following to the **destructor**.

       ```
       ------------------------------------------------
       pop_up_demo_Main_Window::~pop_up_demo_Main_Window()
       {
           if (dialog_1)
           {
               delete dialog_1;
           }

           delete ui;
       }
       ------------------------------------------------
       ```

       Then add the following **action** function.
       ```
       ------------------------------------------------
       void pop_up_demo_Main_Window::dialog_1_action_slot()
       {
           std::cout << "pop up 1\n";

           if ( not dialog_1 )
           {
               dialog_1 = new Dialog_1_Window(this);
           }

           dialog_1->show();
       }
       ------------------------------------------------
       ```

       Build
       ```
          make clean

          make
       ```

       Run

       Select **button 1** and verify that `dialog_1` pops up.

       ```
       NOTE:
          The "cancel" and "OK" buttons work.  But there's no 'user'
          (slot) code connected yet.  See below.
       ```

       Select "OK" (or "Cancel") to dismiss dialog 1.

   14. Implement `slot` on `dialog_1` pushbutton

       Start by creating a **slot** function in **dialog_1.h**

       Edit:  **dialog_1.h**

       Add the following declaration in the **private slots:** section
       of the `class`:
       ```
       ------------------------------------------------
       private slots:

          void dialog_1_push_1_clicked();
       ------------------------------------------------
       ```

       Implement the **slot** function as follows: 
     
       Edit: **dialog_1.cpp**

       Modify the **constructor** to use the **connect()** function to
       map the pushButton **signal** to the **slot** function.
       ```
       ----------------------------------------------
       Dialog_1_Window::Dialog_1_Window(QWidget *parent)

          : QDialog(parent),
            ui(new Ui_Dialog_1)

       {
           ui->setupUi(this);

           QPushButton *pb1 = ui->dialog_1_push_1;

           connect(pb1,
                   &QPushButton::clicked,
                   this,
                   &Dialog_1_Window::dialog_1_push_1_clicked);
       }
       ----------------------------------------------
       ```

       Next, implement the **slot** function.  Add the following function:
       ```
       ----------------------------------------------
       void Dialog_1_Window::dialog_1_push_1_clicked()
       {
          std::cout << "Dialog 1 - Push 1\n";
       }
       ----------------------------------------------  

       Build/Run/Verify:
       ```
          make clean

          build.sh

          pop_up_demo
       ```

       Select `Dialog 1 ...` menu button.  From pop-up of `Dialog 1` select
       `Push 1`.  Verify print to <stdout>.
 
   15. How to handle the "Cancel" and "OK" buttons.

       A) There is a class/widget hierarchy defined for the **Cancel** and
       **OK** buttons on `Dialog_1_Window`.  Each button is _contained_
       in what is called a **QDialogButtonBox** widget (class).  A **slot**
       function can be attached to either or both buttons, programmatically
       that is.  The _connect()_ mechanism (as was shown above) is used.

       The _trick_ here is that the the default behavior of the **Cancel**
       and **Ok** buttons is still enabled.  A **slot** function is _added_
       to the behavior of the buttons.  This means that while the **slot**
       function is invoked, the pop-up dialog is still _dismissed_.

       The following is how to _attach_ a **slot** function to the **Ok**
       button on `Dialog_1_Window`.

       Edit: **dialog_1.h**

       Add the declaration of a new **slot** function for the **Ok**
       button:

       ```
       ------------------------------------------------
       private slots:

              .
              .
              .

           void dialog_1_OK_button_clicked();
       ------------------------------------------------
       ```

       B) Edit: **dialog_1.cpp**

       Implement the **connect()** mechanism for the **slot** function
       for the **Ok** button:

       ```
       ------------------------------------------------
              .
              .
              .
       #include <QDialogButtonBox>
              .
              .
              .

       Dialog_1_Window::Dialog_1_Window(QWidget *parent)

             : QDialog(parent),
               ui(new Ui_Dialog_1_Window)  // <-- Again, no 'namespace' stuff

       {
           ui->setupUi(this);

              .
              .
              .

           QDialogButtonBox *btn_box;

           btn_box = ui->buttonBox;

           QPushButton *ok_btn = btn_box->button(QDialogButtonBox::Ok);

           connect(ok_btn,
                   &QPushButton::clicked,
                   this,
                   &Dialog_1_Window::dialog_1_OK_button_clicked);
       }
       ------------------------------------------------
       ```

       C) Implement the **connect()** mechanism for the **slot** function
       for the **Ok** button:

       ```
       ------------------------------------------------
       void Dialog_1_Window::dialog_1_OK_button_clicked()
       {
           std::cout << "Dialog 1 - OK button\n";
       }
       ------------------------------------------------
       ```

       D) Build

       Only the `make` is needed to build.


       ```
          make clean

          make
       ```       

       E) Run

       ```
       Select "File-->Dialog 1"

       Select the "Ok" button
       ```

       Verify that both the `dialog_1_OK_button_clicked()` function is
       invoked **and** that `Dialog 1` window is dismissed.
 
   16. Implement **Dialog 2** and **Dialog 3**

       With all due respect, to implement **Dialog 2** repeat steps
       (9) to (15) above ... except all names are with respect to
       "dialog 2" instead of "1" ... and the rendering of **Dialog 2**
       is implemented in the **action** function:
       ```
          dialog_2_action_slot()
       ```

       Likewise, to implement **Dialog 3** repeat the steps (9) to (15)
       where names are for "dialog 3".  In this case the rendering of
       **Dialog 3** will be performed in the **slot** function:
       ```
          on_dialog_3_button_clicked()
       ```

       Also, don't forget to `delete` each of the dialog objects in the
       `~pop_up_demo_Main_Window()` (destructor) method.

## Other Attempt Using Qt Creator That Did NOT Work

The creation of the dialogs and the corresponding code that controls them
can only be described as **clunky**.

As a last attempt I tried to create the first dialog **immediately** after
creating the main window.  This was done using the `File-->New` steps.

It seemed to be working.  But when I got to the point where I tried to
create the **slot** function for the _pushbutton_ on `Dialog_1` I got
that same **dang** error:

```
      Error finding/adding a slot

      No documents matching "ui_dialog.h" could be found.
      Rebuilding the project might help.
```

This after doing the same thing to create the **slot** in the main window
where the tool auto-generated the corresponding control .cpp files.  Why
does it **not** do the same for other windows?  What is the **trick**
here?  Is there some hidden button or process that does this.  The tool
clearly expects to find a file **ui_dialog_1.h**.  If I have to create
it myself, why do I need the tool?  It's really annoying.

So ... go with the procedure above.

