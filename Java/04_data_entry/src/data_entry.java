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
//import javax.swing.JApplet;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.border.Border;


public class data_entry extends JFrame 
{
    /*-------------------------------------------
     * METHOD: data_entry
     *
     * DESCRIPTION:
     *    Class constructor.
     *-------------------------------------------*/
    public data_entry()
    {
        data_entry_init();

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        setSize(300, 725);
    
        setVisible(true);
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

     private JTextField name_textfield     = new JTextField("", num_columns);
     private JTextField address_text_area = new JTextField("", num_columns);
     private JTextField city_text_area    = new JTextField("", num_columns);
     private JTextField state_text_area   = new JTextField("", num_columns);
     private JTextField zip_text_area     = new JTextField("", num_columns);
     private JTextField phone_text_area   = new JTextField("", num_columns);

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

             zip_text_area.setText(s);
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
             address_text_area.setText(s);
             city_text_area.setText(s);
             state_text_area.setText(s);
             zip_text_area.setText(s);

             s = "phone # here";

             phone_text_area.setText(s);
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
              address_text_area.setText(s);
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
         Container container = getContentPane();

         FlowLayout flow = new FlowLayout();

         container.setLayout(flow);

         // Create a Border object of 1 pixel width/height/etc
         // that will be applied to each text-field object.
         Border border = BorderFactory.createMatteBorder
                                       (1, 1, 1, 1, Color.BLACK);

         name_textfield.setBorder(border);
         address_text_area.setBorder(border);
         city_text_area.setBorder(border);
         state_text_area.setBorder(border);
         zip_text_area.setBorder(border);
         phone_text_area.setBorder(border);

         // 'Add' each of the base objects to the 'container'
         container.add(name_label);
         container.add(address_label);
         container.add(city_label);
         container.add(state_label);
         container.add(zip_label);
         container.add(phone_label);

         container.add(name_textfield);
         container.add(address_text_area);
         container.add(city_text_area);
         container.add(state_text_area);
         container.add(zip_text_area);
         container.add(phone_text_area);

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
     }
};

/* EOF */

