# Qt Button Demo Project

I figured the next goal would be to create a 'button' demo program
so I could figure out what their button **callback** mechanism was
like.

And already I'm off the rails.  First, a button handler function in
Qt is **not** called a _callback_.  That shows how old I am.  A button
event (and there can be many) is called a **signal** or a **slot**.

1. A **signal** is an _event_ from a _widget_ (e.g. a button).

2. A **slot** is a function (i.e. method) that is called in
   response to a **signal**.  Google mentioned something about
   it could also be a **C++ lambda**, whatever that is.  Reminds
   me of _Finite-State-Machine_ parlance, _lambda_ move as a _free_
   transition from one state to another.

Then **signals** are _connected_ to a **slot** using:
   ```
   QObject::connect()
   ```

Ok ... enough.  My whole first approach was wrong.  Basically, I think
it comes down to I have to (i.e. I'd be insane to try to do this
manually) use the tools:

   1. **Qt Designer** - This is an GUID drawing tool (IDE?).  It's
      used to layout the GUI, what's in it, names of _widget_
      objects, etc.

      At least they still call base graphics objects _widgets_.

   2. **Qt Creator** - This thing is the _master mind_ of the
      project.  It generates the base graphics elements (files?)
      and the glue code, and the handle code, and the **main.cpp**,
      etc.

What I missed yesterday in doing the **Qt** installation is that **all**
of the following tools were installed:

   1. **Qt Assistant** - Documentaiton, help, etc

   2. **Qt Designer** - GUI layout tool (but that's it!)

   3. **Qt Creator** - Project management, generator.  Actually,
      I'm not sure.  I haven't run it yet.

   4. **Qt Linguist** - I have no idea what that is.  But it
      sounds scary.  I guess Linux is trying to be _international_.

## Qt Designer

Started it up.

Selected "create" of one of the **button** templates.

Showed a base canvas with **Cancel** and **Ok** buttons.

I dragged-n-dropped two buttons from the _pallette_ on the left side of the
tool onto the canvas.

I named them _Count Up_ and _Reset_.

I then dragged-n-dropped what appears to be a _text field_ widget onto the
canvas.  I placed it to the right and sort of in-between the two buttons.

I then did a **Save As**.  And a file called **button_demo.ui** was
saved.

Then I had no idea what to do.

## Qt Creator

Stumbling around the **on-line** documentation:
```
   https://doc.qt.io/archives/qt-5.15/gettingstarted.html
```
They kept talking about all these files getting generated.  Some sort of
_Notepad_ demo and a project that contains:
```
   1) notepad.pro
   2) main.cpp
   3) nodepad.cpp
   4) notepad.h
   4) notepad.ui
```
And they talked about something called **Qt Creator**.  It was then that
I realized more _tools_ were installed yesterday than just **Qt Assistant**
and **Qt Designer**.  I then found on the **Show Applications** panes the
tools:

   1. **Qt Creator**

   2. **Qt Linguist**

So here goes my foray into **Qt Creator** ...
   ```
   ---> Scanning these:

   1) IDE Overview

      (a) Managing projects ...

      (b) Designing User Interfaces ...

          Ah! --> "If you need a traditional user interfce that is
                   clearly structured and enforces a platform look
                   and feel, you can use the integrated "Qt Designer".

          I guess I jumped the gun ...

      (c) Coding.  Languages:

              - C++ = OK
              - QML = Ug!

          I'm beginning to smell GUI definitions being defined/saved
          as XML and they call it QML.

      (d) Building and Running

          ... "qmake, Qbs, CMake, and Autotools"

          Ug ... yet another 'make' world to figure out.

      (e) Testing ... 'gdb', Microsoft Console Debugger (CDB) and
          JavaScript.

          Valgrind

          QML Profiler

      (f) Publishing - installation packages for mobile devices.  Hmmm.

   2) User Interface

   3) Configuring Qt Creator

   4) Building and Running an Example

   5) Tutorials 
   ```

## Jump in ... File-->New File or Project

Gonna try to just go for it.  Create a new **project**, try to tie the
**button_demo.ui** I made into the project and see if it will generate
the build products, etc.

   ```
      1) File-->New File or Project

         (a) Qt Widgets Application

         (b) Select "Choose ..." button

         (c) Name: button_demo
             Create In: $HOME/Programming/toolbox/Qt/01_button_callback 

         (d) Next>

         (e) Build system: qmake

         (f) Class Information:
                Class name: ButtonDemo
                Base class: QMainWindow
                Header file: button_demo.h
                Source file: button_demo.cpp
          ATTENTION ---> Generate form:  OFF!!
                Form file: <greyed out>

          Will I be able to use my "button_demo.ui"?

         (g) Next>

         (h) Translation File:    <-- What?
             Language: <none>
             Translation file: <greyed out>

         (i) Next>

         (j) Kit Selection   <-- What?

             Desktop <-- I guess

         (k) Next>

         (l) Project Management
             Add as a subproject to project: <greyed>
             Add to verions contorl: CHANGED FROM "Git" to <None>
             I already set the directory as part of the 'toolbox' clone.
             I hope this works.

         (m) Finish

      2) There was some 'progress bars' doing something ... and a file
         main.cpp is displayed in a sort of editor thing.

         And it's already showing 'warnings' or 'errors' ...

         "variable has incomplete type 'QApplication'.  <-- What?

         etc.

         Now what do I do?

      3) OK ... first problem.  The tool created a sub-directory in
         my work area called "button_demo".

         Ug.  OK.  Stop here.  Exit out and try to move all the
         products (files) that were generated up back up to the
         work area ... and then try to open the project from there.

         NOTE - the 'button_demo.ui' is in the 'up' directory.  So it
         should find that, right?
   ```

   THIS DID NOT WORK!

## Pivot - Start Over - New Project

Not using the .ui from the **Qt Designer**.  Create it as part of the
new project.

1. Went through the `File-->New Project` etc.

2. Still placed everything in a sub-directory!

3. Created a new _Form_.

   Added the two buttons (count and reset) and the text-field.

   Gave then unique names.

   Build All : Was OK

   Products go to some ugly-named subdirectory

   It ran ... but of course, did nothing.

4. Go back to Form edit.

   Select the 'count' button thing ... mouse-button-2 gives a pulldown
   menu.  One of the options is:

         **Go to Slot**

   That's what they call a _callback_.  This creates a new method
   (function) in the class file **buttondemo.cpp**

   Did the same for the 'reset' button.

5. Created an `unsigned int count = 0` in the class declaration
   **buttondemo.h**.

6. Updated the **slot** functions to increment **count** or to
   reset it to 0.

7. Then tried to figure out how to write the value to the text-field.

   This proved impossible.

8. Did build ... but compilation failed with error.  Some uselss
   information ... but still failing.

9. Exited from **Qt Creator**

   Moved all products up to parent work directory.

   Modified the **build.sh** to use the **button_demo.pro** for the
   **qmake**.

   This errored out and showed a meaningful error about something
   wrong in **buttondemo.h**.

   Turns out I placed the **unsigned int count = 0** in a scection of
   the **class** that wasn't allowed.  It's a special (C++ extension?)
   area called:

        **private slots:**

   What the frick is that?

   So I moved the **unsigned int count = 0;** to the plain old
   **private** section.

   The build worked.

10.  Build - was finally successful

     Run - ran ... but still did nothing ... at least that I could
     see.

11. Struggled again to try an figure out how to write text to the
    **count_line** _text-field_.

    Still came up with nothing.

    Settled on just writing to <stdout>.

12. Rebuild

    Run - and so that worked.  Can see counts going out to <stdout>.

So that's it.

I'll do a google query on how to set a _text-field_ in Qt.  But why should
I have to?  Shouldn't the Qt documentaiton help me?

So I'll capture all the base products and call this "done".

I'll then go and add an exit button.

But I'm done updating this README.  The fact that I had to go outside the
**IDE** to make things work is bogus.  Strike 2 against **Qt**.

Note - I just did a google query:
```
Which is more popular for GUI development, Java or Qt?
```
And the answer came back **Java**.

I'll do the next couple of demo problems (Menu GUI, then graphics demo).
But unless there's some miracle event I think I'm done with **Qt**.

