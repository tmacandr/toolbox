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

