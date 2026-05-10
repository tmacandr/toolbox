# Pop-up Dialogs Demo

The goal of this project is to demonstrate how to show (pop-up)
dialog windows from a main GUI display.

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

# Implemention
Did this:
```
1) Copy .ui from base .ui.  Call new file dialog.ui

2) Add dialog.ui to pop_up_demo.pro project file

3) Start qtcretor pop_up_demo.pro

4) Edit the dialog.ui compoents to be what you want it to be

5) Go to File-->New File or Project

   (a) On the "New File or Project -- Qt Creatore" dialog

       From "Files and Classes" select "Qt"

   (b) ... go through 'wizard' pages ... FIX ME!  WHAT DID I DO?

   (c) delete the generated .h/.cpp for the dialog

   (d) Did this:

          cp pop_up_demo_main_window.h dialog_1_window.h
          cp pop_up_demo_main_window.cpp dialog_1_window.cpp

   (e) Replace all 'pop-up' widget references to 'dialog_1' references,
       or some such deal.  FIX ME!

   (f) Here's where things get really ugly ...

       (i) Do DIRECT include of <ui_dialog_1.h> ...

       (ii) AND DELETE this namespace stuff:

            QT_BEGIN_NAMESPACE
            namespace Ui
            {
                class pop_up_demo_Main_Window;
            }
            QT_END_NAMESPACE
 
  
      (iii) And (at the bottom of the 'class') the 'ui' object
            pointer becomes SIMPLY:

                Ui_Dialog_1_Window *ui;

   (g) Then the 'slot' function back in the 'pop_up_demo_main_window.cpp'
       becomes:

              if ( ! dialog_1 )
              {
                  dialog_1 = new Dialog_1_Window(ui->centralwidget);
              }

              dialog_1->show();

       DON'T FORGET THE show() or nothing happens.

   (h) DON'T change or modify the ui files:

          moc_pop_up_demo_main_window.h/.cpp
          moc_dialog_1_window.h/.cpp

       These are GENERATED by the Qt Creator tool and/or via the
       qmake (build.sh) process.  They are "TRANSITORY".  Any edits
       to the .ui files will cause re-generation of the moc_*.h/.cpp
       files. 
```

I MUST repeat this from start to finish.  It was so friggin' ugly.  I
probably forgot important steps.

For now, go with this.

Another `black mark` for **Qt**.

