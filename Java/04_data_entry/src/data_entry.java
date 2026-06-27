/*--------------------------------------------------------------------------
 * FILE: data_entry.java
 *
 * DESCRIPTION:
 *    Manages the 'data-entry' panel.  Extracts the data from the
 *    text-fiels and writes them (as ASCII text) to a file.
 *--------------------------------------------------------------------------*/
package src;

import java.awt.Color;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.border.Border;
import javax.swing.SpringLayout;


public class data_entry
{
    private JFrame frame;


    /*-------------------------------------------
     * METHOD: data_entry
     *
     * DESCRIPTION:
     *    Class constructor.
     *-------------------------------------------*/
    public data_entry()
    {
        data_entry_init();

        frame.setSize(300, 725);
    
        frame.setVisible(true);
    }

    /*
     * Display objects:
     *    1) Three buttons for "Save", "Cancel", and "Exit".
     *    2) Labels and text-fields for the following
     *       data-entry items:
     *          Name
     *          Address
     *          City
     *          State
     *          ZIP
     *          Phone
     */ 
     private JButton save_button   = new JButton("Save");
     private JButton cancel_button = new JButton("Cancel");
     private JButton exit_button   = new JButton("Exit");

     private JLabel name_label    = new JLabel("Name");
     private JLabel address_label = new JLabel("Address");
     private JLabel city_label    = new JLabel("City");
     private JLabel state_label   = new JLabel("State");
     private JLabel zip_label     = new JLabel("ZIP");
     private JLabel phone_label   = new JLabel("Phone");

     int num_columns = 20;

     private JTextField name_textfield     = new JTextField("Name", num_columns);
     private JTextField address_textfield = new JTextField("Addr", num_columns);
     private JTextField city_textfield    = new JTextField("City", num_columns);
     private JTextField state_textfield   = new JTextField("State", num_columns);
     private JTextField zip_textfield     = new JTextField("ZIP", num_columns);
     private JTextField phone_textfield   = new JTextField("Phone", num_columns);

     /*
      * Button 'callbacks' in Java are implemented as 'instances' of
      * the 'ActionListener' class.
      *
      * Need one each for "Save", "Cancel", and "Exit"
      */
     class Save_Button_Lister implements ActionListener
     {
         /*-------------------------------------------
          * METHOD: actionPerformed 
          *
          * DESCRIPTION:
          *    Handler when 'Save' is selected.
          *-------------------------------------------*/
         public void actionPerformed(ActionEvent e)
         {
             String s = name_textfield.getText() + "\n";

             zip_textfield.setText(s);
         }
     }

     class Cancel_Button_Listener implements ActionListener
     {
         /*-------------------------------------------
          * METHOD: actionPerformed 
          *
          * DESCRIPTION:
          *    Handler when 'Cancel' is selected.
          *-------------------------------------------*/
         public void actionPerformed(ActionEvent e)
         {
             String s = "Cancel not implmented";

             name_textfield.setText(s);
             address_textfield.setText(s);
             city_textfield.setText(s);
             state_textfield.setText(s);
             zip_textfield.setText(s);

             s = "phone # here";

             phone_textfield.setText(s);
         }
     }

     class Exit_Button_Listener implements ActionListener
     {
         /*-------------------------------------------
          * METHOD: actionPerformed 
          *
          * DESCRIPTION:
          *    Handler when 'Exit' is selected.
          *-------------------------------------------*/
          public void actionPerformed(ActionEvent e)
          {
              String s = " Fooled ya - Exit not implemented";
              address_textfield.setText(s);
          }
     }


    /*-------------------------------------------
     * METHOD: data_entry
     *
     * DESCRIPTION:
     *    Instantiate the GUI components, format
     *    the layout, and connect the 'callbacks'.
     *-------------------------------------------*/
     private void data_entry_init()
     {
         frame = new JFrame("Data Entry Demo");

         frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

         Container container = frame.getContentPane();

         FlowLayout flow = new FlowLayout();

         SpringLayout layout = new SpringLayout();

         container.setLayout(layout);

         // Create a Border object of 1 pixel width/height/etc
         // that will be applied to each text-field object.
         Border border = BorderFactory.createMatteBorder
                                       (1, 1, 1, 1, Color.BLACK);

         name_textfield.setBorder(border);
         address_textfield.setBorder(border);
         city_textfield.setBorder(border);
         state_textfield.setBorder(border);
         zip_textfield.setBorder(border);
         phone_textfield.setBorder(border);

         // 'Add' each of the base objects to the 'container'
         container.add(name_label);
         container.add(address_label);
         container.add(city_label);
         container.add(state_label);
         container.add(zip_label);
         container.add(phone_label);

         container.add(name_textfield);
         container.add(address_textfield);
         container.add(city_textfield);
         container.add(state_textfield);
         container.add(zip_textfield);
         container.add(phone_textfield);

         container.add(save_button);
         container.add(cancel_button);
         container.add(exit_button);

         // Create 'listener' objecs and connect to the buttons:
         //        Save
         //        Cancel
         //        Exit
         Save_Button_Lister save_listener = new Save_Button_Lister();

         save_button.addActionListener(save_listener);

         Cancel_Button_Listener cancel_listener = new Cancel_Button_Listener();

         cancel_button.addActionListener(cancel_listener);

         Exit_Button_Listener exit_listener = new Exit_Button_Listener();

         exit_button.addActionListener(exit_listener);

         // Define geometry of objects
         // name
         layout.putConstraint
                   (SpringLayout.WEST, name_label,
                    6,                  // padding
                    SpringLayout.WEST, container);

        layout.putConstraint
                  (SpringLayout.NORTH, name_label, 
                   6,
                   SpringLayout.NORTH, container);

        layout.putConstraint
                  (SpringLayout.WEST, name_textfield,
                   6,
                   SpringLayout.EAST, name_label);

        layout.putConstraint
                  (SpringLayout.NORTH, name_textfield,
                   6,
                   SpringLayout.NORTH, container);

        // address
        layout.putConstraint
                  (SpringLayout.WEST, address_label, 
                   6,
                   SpringLayout.WEST, container);

        layout.putConstraint
                  (SpringLayout.NORTH, address_label,
                   6,
                   SpringLayout.SOUTH, name_label);

        layout.putConstraint
                  (SpringLayout.WEST, address_textfield, 
                   6,
                   SpringLayout.EAST, address_label);

        layout.putConstraint
                  (SpringLayout.NORTH, address_textfield,
                   6,
                   SpringLayout.SOUTH, name_textfield);

         // city
         layout.putConstraint
                   (SpringLayout.WEST, city_label, 
                    6,                  // padding
                    SpringLayout.WEST, container);         

        layout.putConstraint
                  (SpringLayout.NORTH, city_label,
                   6,
                   SpringLayout.SOUTH, address_label);

        layout.putConstraint
                  (SpringLayout.WEST, city_textfield,
                   6,
                   SpringLayout.EAST, city_label);

        layout.putConstraint
                  (SpringLayout.NORTH, city_textfield,
                   6,
                   SpringLayout.SOUTH, address_textfield);

        // state
        layout.putConstraint
                  (SpringLayout.WEST, state_label,
                   6,
                   SpringLayout.WEST, container);

        layout.putConstraint
                  (SpringLayout.NORTH, state_label,
                   6,
                   SpringLayout.SOUTH, city_label);

        layout.putConstraint
                  (SpringLayout.WEST, state_textfield,
                   6,
                   SpringLayout.EAST, state_label);

        layout.putConstraint
                  (SpringLayout.NORTH, state_textfield,
                   6,
                   SpringLayout.SOUTH, city_textfield);

         // zip
         layout.putConstraint
                   (SpringLayout.WEST, zip_label,
                    6,                  // padding
                    SpringLayout.WEST, container);

        layout.putConstraint
                  (SpringLayout.NORTH, zip_label,
                   6,
                   SpringLayout.SOUTH, state_label);

        layout.putConstraint
                  (SpringLayout.WEST, zip_textfield,
                   6,
                   SpringLayout.EAST, zip_label);

        layout.putConstraint
                  (SpringLayout.NORTH, zip_textfield,
                   6,
                   SpringLayout.SOUTH, state_textfield);

        // phone
        layout.putConstraint
                  (SpringLayout.WEST, phone_label,
                   6,
                   SpringLayout.WEST, container);

        layout.putConstraint
                  (SpringLayout.NORTH, phone_label,
                   6,
                   SpringLayout.SOUTH, zip_label);

        layout.putConstraint
                  (SpringLayout.WEST, phone_textfield,
                   6,
                   SpringLayout.EAST, phone_label);

        layout.putConstraint
                  (SpringLayout.NORTH, phone_textfield,
                   6,
                   SpringLayout.SOUTH, zip_textfield);

         // buttons
        layout.putConstraint
                  (SpringLayout.WEST, save_button,
                   6,
                   SpringLayout.WEST, container);

        layout.putConstraint
                  (SpringLayout.NORTH, save_button,
                   6,
                   SpringLayout.SOUTH, phone_label);

        layout.putConstraint
                  (SpringLayout.WEST, cancel_button,
                   6,
                   SpringLayout.EAST, save_button);

        layout.putConstraint
                  (SpringLayout.NORTH, cancel_button,
                   6,
                   SpringLayout.SOUTH, phone_label);

        layout.putConstraint
                  (SpringLayout.WEST, exit_button,
                   6,
                   SpringLayout.EAST, cancel_button);

        layout.putConstraint
                  (SpringLayout.NORTH, exit_button,
                   6,
                   SpringLayout.SOUTH, phone_label);

         frame.pack();
     }
};

/* EOF */

