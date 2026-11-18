import javax.swing.JFrame;

public class Myframe extends JFrame {
      Myframe() {
/*'this'refer to the instance of the Myframe 
class also it sets the properties of the frame */
        this.setTitle("My First Swing Application");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setResizable(false);
        this.setSize(400, 300);
        this.setVisible(true);
        this.getContentPane().setBackground(java.awt.Color.BLACK);
      }
}
