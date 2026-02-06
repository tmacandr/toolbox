/*----------------------------------------------------------------------------
 * FILE: ButtonExample.java
 *
 * DESCRIPTION:
 *    Example of how to implement a button and text field in Java.
 *    I tried to start with a simple example from the Web ... and at
 *    this point I'm not sure from where ... and it quickly spiraled
 *    out of control when I tried to implement the callback on the
 *    button.  See the 'description' section below on the
 *    'ActionLister' class.
 *
 *    Then I ran into a lot of trouble in how items are static and what
 *    can and cannot be declared in a 'static' context.  In particular,
 *    while struggling to get the object of the 'ActionLister' class  
 *    instantiated apparently such an object cannot be declared in
 *    a function (i.e. method) that is 'static'.  So I reworked the 'main()'
 *    to create 'this' and then pass 'this' to a non-static (and public)
 *    init() function that can create abstract (i.e. 'ActionClass') objects.
 *--------------------------------------------------------------------------*/

import java.awt.event.*;
import javax.swing.*;

public class ButtonExample
{
   private static JFrame f = new JFrame("Button Example");

   private static final JTextField tf = new JTextField();

   private static JButton b = new JButton("Click Here");

   private static int count = 0;


   /*---------------------------------------------------
    * CLASS: ButtonActionClass
    *
    * DESCRIPTION:
    *    Callbacks in Java are implemented as instantiations
    *    of an 'abstract' class called 'ActionListener'.
    *
    *    Actually, one is not supposed to use the term
    *    'callback' ... it's to C like.
    *
    *    At this point all I can see is that one has
    *    to declare a new class for every callback
    *    action on every button ... and there can be
    *    more than one callback per button.  Each new
    *    class must 'implement' the 'abstract' class
    *    called 'ActionLister'.
    *
    *    Then, the new class must define/implement a
    *    funtion called 'actionPerformed()' that will
    *    be invoked when any of a number of 'actions'
    *    occur on the button ... which is indicated
    *    in the 'callback object' which is of an
    *    'ActionEvent' class.  The callback will parse
    *    the 'ActionEvent' object for more specifics,
    *    if desired.
    *
    *    OK ... when each new class is declared (carefull
    *    wording here), then a new instance of the object
    *    is made and then passed to the 'addActionListener()'
    *    methos of EACH button.  In this case, I just have
    *    one.
    *
    *    In this case, one instance of 'ButtonActionClass'
    *    is made and that object is passed to the 'b' button.
    *
    *    ... and that's how button callbacks are implemented
    *    in Java!
    *
    *    Actually, in the Java world (on the Web) it seems
    *    that when everybody calls  the button's
    *    'addActionLister()' then declare and instantiate a
    *    new 'ActionLister' class and object all right there
    *    as the argument to the method.  It seems like
    *    sloppy code ... especially when counting brakets,
    *    parentheses, and semi-colons ... but I guess they
    *    think this is clever.  It's just they way it's
    *    done since everybody knows this is how button
    *    callbacks are implemented.
    *----------------------------------------------------*/
   private class ButtonActionClass implements ActionListener
   {
       public void actionPerformed(ActionEvent e)
       {
                count++;

                if ( count < 4 )
                {
                    tf.setText("Welcome - Count = " + count);
                }
                else
                {
                    /*----------------------------
                     * ATTEN:
                     * Had to define 'exit' here
                     * because doing a <ctrl>-c
                     * at the console kills the
                     * app but leaves the Java
                     * run-time machine still
                     * running in the background.
                     *----------------------------*/
                    System.exit (0);
                }
       }
   }


   /*-------------------------------------------------
    * METHOD: init
    *
    * DESCRIPTION:
    *    Initializes everything.  Had to create this
    *    because the 'ButtonActionClass' object can't
    *    be 'referenced' in a 'static context, which
    *    is the 'main()'.  But ... the main() can call
    *    a non-static function and voila ... the object
    *    can be created.
    *-------------------------------------------------*/
   public void init ()
   {
        tf.setBounds(50,50, 150,20);

        b.setBounds(50,100,95,30);

        ButtonActionClass ba = new ButtonActionClass();

        b.addActionListener(ba);

        f.add(b);
	
	f.add(tf);

        f.setSize(400,400);

        f.setLayout(null);

        f.setVisible(true);
    }


   /*-------------------------------------------------
    * METHOD: ButtonExample
    *
    * DESCRIPTION:
    *    Now I'm being a pure-est ... and C++ like.
    *    This is the 'constructor' method on this
    *    class 'ButtonExample'.  It gets invoked
    *    (in particular) when the 'main()' creates
    *    the new 'ButtonExample' object.
    *
    *    I didn't really have to do this ... I've
    *    noticed that even though Java is this
    *    massively 'object-oriented' language and
    *    enforced to the max ... apparently one
    *    is not required to define 'constructor'
    *    or 'desctructor' methods on the class.
    *     So much for purity.
    *------------------------------------------------*/
   public ButtonExample ()
   {
      this.init();
   }


   /*-------------------------------------------------
    * METHOD: ButtonExample
    *
    * DESCRIPTION:
    *    The 'main()' ... which really bugs because
    *    the base class of the program defines the
    *    'main()' ... what?
    *
    *    And the instantiation of the 'this' is done
    *    in 'this' ... what?
    *
    *    But, as noted above, I can't declare an
    *    abstract class implemenation such as
    *    'ButtonActionClass' here because the 'main()'
    *    is a 'static' context ... and I have no idea
    *    why.
    *-------------------------------------------------*/
   public static void main(String[] args)
   {
       ButtonExample be = new ButtonExample();
   }
}

/* EOF */

