# Pop-up Dialogs Demo

The goal of this project is to demonstrate how to show (pop-up)
dialog windows from a main GUI display.

I thought it wouldn't be too bad, using that **Qt Creator** tool.
But it quickly spun out of control.

## First Attempt - Qt Creator

The approach was to define a base GUI using the **QT Creator** tool.  It
had a base button and a couple of menu-bar buttons.  Each of the `slot`
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

## Second Attempt - Programmatic

So I went to `google` and asked how to implement dialogs *programmatically*.

I thought, "OK ... I'll go dinasaur" and write gobs of code to both
define/create the dialogs, the sub-widgets (including the buttons), then
pop-up the dialogs, respond to user operations (button clicks), and then
finally `exit`.

So **google** dumps out some example code that uses these two classes
called **QUiLoader** and **QFile**.

