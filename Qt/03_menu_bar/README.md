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

