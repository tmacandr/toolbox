/*--------------------------------------------------------------------------
 * FILE: data_entry.java
 *
 * DESCRIPTION:
 *    Manages the 'data-entry' panel.  Extracts the data from the
 *    text-fiels and writes them (as ASCII text) to a file.
 *--------------------------------------------------------------------------*/

import java.awt.Color;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.BorderFactory;
//import javax.swing.JApplet;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.border.Border;


public class data_entry extends JFrame 
{
    public data_entry()
    {
        init();

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        setSize(300, 725);
    
        setVisible(true);
     }

     private JButton save_button   = new JButton("Save");
     private JButton cancel_button = new JButton("Cancel");
     private JButton exit_button   = new JButton("Exit");

     private JLabel name_label    = new JLabel("Name", 20, 20);
     private JLabel address_label = new JLabel("Address", 30, 20);
     private JLabel city_label    = new JLabel("City", 40, 20);
     private JLabel state_label   = new JLabel("State", 50, 20);
     private JLabel zip_label     = new JLabel("ZIP", 60, 20);
     private JLabel phone_label   = new JLabel("Phone", 80, 20);

     private JTextArea name_textarea     = new JTextArea("", 1, 20);
     private JTextArea address_text_area = new JTextArea("", 4, 20);
     private JTextArea city_text_area    = new JTextArea("", 1, 20);
     private JTextArea state_text_area   = new JTextArea("", 10, 10);
     private JTextArea zip_text_area     = new JTextArea("", 4, 20);
     private JTextArea phone_text_area   = new JTextArea("", 10, 10);

     class B1L implements ActionListener
     {
         public void actionPerformed(ActionEvent e)
         {
             String s = name_textarea.getText() + "\n";

             zip_text_area.append(s);
         }
     }

     class B2L implements ActionListener
     {
         public void actionPerformed(ActionEvent e)
         {
             address_text_area.setText("Inserted by Button 2");
             address_text_area.append(": " + name_textarea.getText());

             zip_text_area.append(address_text_area.getText() + "\n");
         }
     }

     class B3L implements ActionListener
     {
          public void actionPerformed(ActionEvent e)
          {
              String s = " Replacement ";
              address_text_area.replaceRange(s, 3, 3 + s.length());
          }
     }

     class B4L implements ActionListener
     {
         public void actionPerformed(ActionEvent e)
         {
             address_text_area.insert(" Inserted ", 10);
         }
     }

     private void init()
     {
         Container cp = getContentPane();

         cp.setLayout(new FlowLayout());

         // Create Borders for components:
         Border brd = BorderFactory.createMatteBorder(1, 1, 1, 1, Color.BLACK);

         name_textarea.setBorder(brd);

         address_text_area.setBorder(brd);

         sp3.setBorder(brd);
         sp4.setBorder(brd);
         sp5.setBorder(brd);
         sp6.setBorder(brd);

         // Initialize listeners and add components:
         B1L save_callback = new B1L();

         save_button.addActionListener(save_callback);

         cp.add(save_button);

         cp.add(name_textarea);

         cancel_button.addActionListener(new B2L());

         cp.add(cancel_button);
         cp.add(address_text_area);

         exit_button.addActionListener(new B3L());

         cp.add(exit_button);
         cp.add(sp3);
         cp.add(sp4);
         cp.add(sp5);
         cp.add(sp6);
     }
};

/* EOF */

