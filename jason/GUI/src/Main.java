package src;
/* This is a simple Swing application 
that creates a window with a label */

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.BorderFactory;
/*javax.swing is a package that provides classes for building graphical user interfaces (GUIs) in Java. 
JFrame is a class within this package that represents a window in a Swing application.
*/
import javax.swing.ImageIcon;
/* ImageIcon is a class within the javax.swing package 
that represents an image icon in a Swing application. */
import java.awt.Color;
import java.awt.Font;
/* Color is a class within the java.awt package 
that represents a color in a Swing application. */

import javax.swing.border.Border;

public class Main {
    public static void main(String[] args){
        //JFrame is a class that represents a window in a Java Swing application
        JFrame frame = new JFrame("My First Swing Application");
        /* this creates a new instance JFrame with the title 
        "My First Swing Application" */
        frame.setTitle("Jframe title");
        // sets the title of the frame to "Jframe title"
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        /* this sets the default close operation of the frame to
        EXIT_ON_CLOSE, which means that the application will exit 
        when the user closes the frame */
        frame.setResizable(false);
        /* this sets the resizable property of the frame to false,
        which means that the user will not be able to resize the frame */
        frame.setSize(400, 300);
        /* this sets the size of the frame to 400 pixels wide 
        and 300 pixels tall */
        frame.setVisible(true);
        /* this makes the frame visible on the screen */
        frame.getContentPane().setBackground(java.awt.Color.BLACK);
// sets the background color of the content pane of the frame to blue

        //image icon
        //ImageIcon icon = new ImageIcon("icon.png");
        //thi sets logo of the frame to the image located at "icon.png"
        //frame.setIconImage(icon.getImage());  


// Jlabel is a class that represents area for displaying text 
        JLabel label = new JLabel("Hello, World!");
        /* this creates a new instance of JLabel with the text*/
     label.setText("Label text");
     frame.add(label);
/* this adds the label to the frame 
 which means the label will be displayed within the frame */
 //label.seticon(icon);
 // this will set the icon of the label to the image located at "icon.png"
 label.setHorizontalTextPosition(JLabel.CENTER);
/* this sets the horizontal position of the text 
within the label to CENTER,*/
label.setForeground(Color.WHITE);
// this sets the foreground color of the text within the label to white
label.setFont(new Font("MV Boli", Font.PLAIN, 20));
//sets the font to "MV Boli", the style to plain, and the size to 20
//label.setIconTextGap(-25);
//this sets the gap between the text and the icon within the label 
label.setBackground(Color.YELLOW);
/* this sets the background color of the label to yellow */
label.setOpaque(true);
/* this makes the background of the label opaque, 
meaning it will be filled with the background color */
Border border = BorderFactory.createLineBorder(Color.GREEN, 3);
/* this creates a new instance of a line border with the color green 
and a thickness of 3 pixels */
label.setBorder(border);
// this sets the border of the label to the line border created above
 label.setVerticalAlignment(JLabel.CENTER);
/* this sets the vertical alignment of the text within the label to CENTER*/
label.setHorizontalAlignment(JLabel.CENTER);
// this sets the horizontal alignment to CENTER
label.setBounds(0, 0, 400, 300);
// this sets the position and size of the label within the frame 
frame.setLayout(null);
/* this sets the layout of the frame to null, 
allowing for absolute positioning of components */
frame.pack();
/* this packs the frame to fit its components */

/*JPanel is a class that represents a container for other components */
  JPanel panel = new JPanel();
  /* this creates a new instance of JPanel */
  panel.setBackground(Color.ORANGE);
  panel.setBounds(0, 0, 100, 100);
  frame.add(panel);


    }
}
