# Java Data Entry Demo

The goal here is to show how to define/implement a data-entry
GUI and then save the values to a file.

## Requirements

This is essentially a duplicate of the 'data-entry' demo
in the **Qt** area.  The following entries are to be processed:
```
   Name:
   Address:
   City:
   State:
   ZIP:

   Save Reset Exit
```

The **Java** application is to implement the following window, which
is what was previously implemented in **Qt** using the **qtcreator**
tool:

![base_window](./images/base_window.jpg "base-window")

The following behavior is to be implemented:

   1. On selection of the **Save** button, the Java application
      will get (extract) each of the values (`Name`, `Age`', etc)
      and save them to a file called `data_entry.txt`.  The data
      will be saved as ASCII.

   2. On selection of the **Reset** button, each of the date-entry
      fields will be cleared.

   3. On selection of the **Exit** button, the application will
      simply exit.  Thus, data is only saved if the user presses
      the **Save** button.

The **crux** of the matter here is that the application will be
implemented entirely programmatically.  In other words, no GUI
tool is used, as was done for the **Qt** implementation.

Apparently, in reading the **Oracle** page [1], this is the hard
way to go about doing GUI work.

## Implemenation

The bulk of the functionality is implemented in a class called
`data_entry` (ref: `data_entry.java`).

The `main` is straight forward in that all it does is instantiate
a `data_entry` object.

### GUI Alignment

There are apparently several choices here:

   1. Painstakingly specify the (x,y) location of each GUI object,
      essentially by trial-and-error.

   2. Use the **Spring** class to align the objects.

      The `Spring` class implements a placement/rendering  mechanism
      that gives the GUI objects `spring like` behavior.  They
      align with each other as if **springs** were holding them
      in place ... such the name of the class **Spring**.

      The **Spring** class implements different types of alignment
      mechanisms, as described in [1].

      I started with the `base` mechanism, and this proved very
      difficult. 

   3. There are other `alignment` mechanisms offered via the Java
      **awt** library.  But I settled on `Spring`.  Maybe I did this
      because it reminded me of the `attachment` mechanism offered
      in the **X Window System** (namely the `Xt/Xm` libraries).  But
      choosing something because it's familiar may not always be
      prudent ... especially since the Java system is so big and
      offers so much more functionality than **X/Xt/Xm**.

The Oracle **Java** page [1] indicates that the `sane` (my words) way
to do GUI work is to use an IDE (`Integrated Development Environment`).
In particular they recommend **NETbeans**, and that will make all the
pain of **Spring** work go away.

A `google` query also suggests using **NETbeans** or **Eclipse**.  But
they highly recommend some thing I've never heard of called
**IntelliJ IDEA**.  It's `free` for a base version ... but costs
about $150 (or more for more features) for something like a 2 or 3
year license.  But apparently it is the most popular tool for Java
GUI development.

So I guess there's a bit of `cognitive dissonance` going on here.  While
I downloaded/installed the **qtcreator** tool for the **Qt** version of
the `data_entry` demo, I'm not doing so here.  I'm going to try to push
my way through a programmatic implementation of the **Spring** mechanism
for the GUI alignment/presentation.

## Attempt 1 

The first attempt was to go for it all in one push.  The `data_entry` class
did an inheritcance (`extends`) a **JFrame** as the parent widget.  Is
the term _widget_ used in Java?

It then just plowed through and created `Jbutton` objects for the `Save`,
`Reset` and `Exit` buttons.  Then it created `JLabel` and `JTextField`
pairs for the `Name`, `Address`, `City`, `State`, `ZIP`, and `Phone`
entry fields.

Then it implemented instances of the abstract class called `ActionListener`.
This is how button `callbacks` are implemented in Java.  I found this
clunky ... to instantiate an _abstract_ class and then implement the
_virtual_ method **actionPerformed()**.  This acts as the `callback` for
a button.

A _constructor_ method (`data_entry()`) was implemented.  It called an
initialization function (`init()`), set the size of the **JFrame** and
then invoked `setVisable()` to render the GUI.

The `init()` did most of the work.  It created at `Container` from the
`JFrame`.  All objects would be _in_ the `Container`.  A `FlowLayout`
was instantiated under the assumption that this would make it easy to
control/define the layout (per the window above).
 
So far so good ...

And then everyting fell apart.

All the GUI components were jumbled in a heap in the upper left corner
of the window.  And the only reason why the windows was even shown
was because the `size` was set to 300x725 pixels.

## Attempt 2

So I stumbled around the Web and came upon the **Spring** class [1].  So
I continued on the _do everything_ based on the demo mechanics, particularly
the function:
```
   <layout-obj>.putConstraint
                   (<direction>, <from-obj>
                    <padding>,
                    <direction>, <to-obj>);
```

The attachment mechanism didn't seem to make sense.  The first case where
the WEST (left) of the `name_label` was attached to the WEST (left?) of
the `container`.  This made no sense.  But the WEST of the `name_textfield`
attached to the EAST of the `name_label`.  This made sense.

But after plowing through as much as I could figure, trial-and-error of
different combinations, nothing was working.

## Attempt 3

So an attempt to _go small_ was made.  In this case, the GUI was reduced
to one `JLabel`, one `JTextField` and one `JButton`.

The alignment was to be as follows:

scan-of-simple-GUI-image-here

After more trial-and-error ... and then, by happenstance, remembering some
more of the mechanics offered in **X/Xt/Xm** the following connections
were made:

scan-of-simple-attach-that-worked

## Attempt 4

Returning to the full data-entry panel, the following **attachment**
mechanism was implemented.

scan-of-full-up-attachment-plan

And of course, at this point, the call to `setSize()` isn't needed anymore.

# REFERENCES

[1] https://docs.oracle.com/javase/tutorial/uiswing/layout/spring.html

