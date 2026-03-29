# Menu-bar Demo

Trying to implement a skeleton GUI based on the "Digital Chart of
the World" app.

Defines buttons on the 'menu-bar':

   File
      Count
      Exit
   Ctrl
      Zoom in
      Zoom out
      Move North
      Move South
      Move East
      Move West
   Themes
      LibRef
      Population
      Drainage
      Polit_Ocean
   Help

# Define Slots (callback functions)

This is where the **Qt Creator** goes bogus.  There's no direct way to use
the tool (IDE) to define slots (functions) to handle operator selection
of one of the buttons (from the menu-bar).

At this point, I'm hand defining **slots** via:

   1. Type the name of each button to go into the menubar using
      the IDE tool ... where it says "Type here".

      For example, typing "Zoom in" becomes an 'action' called
      "actionZoom_in".
 
   2. Define the 'slot' in the main class in that
      ```
         public slots:

            void zoom_in_action_slot();
      ```

   2. In the constructor and after **ui->setup()**:
      ```
          connect(ui->actionZoom_in,
            &QAction::triggered,
            this, 
            &<name-of-main-class>::zoom_in_action_slot);
      ```

This has to be done for each button in the menu-bar.

Very clunky.  Why did they allow 'slot' connections via the IDE for
base button widgets, but not 'action' widgets?

# About 'slot' functions and 'paint' ... and Menu-bar root button

1. Defined "action" slot (functions) for
   Ctrl cascade button (Zoom in ... Move west)
   Themes cascade button (LibRef .. Polit Ocean)
    
   These are mostly empty ... to be implemented.
    
2. Tried to define a 'slot' for the "Help" button.
    
   The connetion was made, but the function is not
   being invoked.  So soemthing is off.
    
3. Defined a 'paint' event function
    
   The intent was that each 'slot' function would write
   to the 'main' window/widget.  But when I tried that
   I got the following error:
   ``` 
          QWidget::paintEngine: Should no longer be called
          QPainter::begin: Paint device returned engine == 0, type: 1
   ``` 
   This means that one can't do 'paint' operations in a
   button 'slot' function ... or any function except a
   'paint' function.
    
   But now the 'slot' function(s) are useless and the
   'paint()' occurs ALL THE TIME ... even at start-up.
    
   So this causes two problems:
   ``` 
          (a) There has to be some sort of 'logic'
              set in the 'slot' functions that control
              how and/or what the 'paint()' callback
              can do.
    
          (b) A 'paint()' function has to be MINIMALIST
              because it can't take too long to render and/or
              draw into the main canvas.
    ``` 
    So this mechanism to do drawing/painting vis-a-vis the 'slot'
    functions is 'problematic' at this point.  I'll have to think
    about this 'protocol' and try to figure how:
    ``` 
       (a) cooordinate the 'slot' functions with the ONE paint
           function.
    
       (b) How to get the single menu-bar button "HELP" to
           have a 'slot' function.  But now I'm beginning
           to think it's not allowed ... or there's massive
           rigmarole to make it happen.
    
       (c) I need to figure out what the 'QPaintEvent' object
           looks like ... and if there's something I can use
           in it.  Even checking the Web seems bogus.  The
           arrogant cusses on "StackOVerflow" always hide
           behind hubris when they (i.e. the "experts")
           won't admit they don't know the answer.
    ```

