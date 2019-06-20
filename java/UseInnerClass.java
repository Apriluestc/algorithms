import java.awt.event.*;
import javax.swing.*;
public class UseInnerClass {
    JFrame f;
    public UseInnerClass() {
        f = new JFrame();
        f.setSize(300, 150);
        f.setVisible(true);
        f.addMouseListener(new addMouseAdpter() {
            public void mouseClicked(mouseEvent e) {
                f.setTitle("点击坐标为("+e.getX()+", "+e.getY()+")");
            }
        });
        f.addWindowListener(new WindowAdpter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
    }
    public static void main(String[] args) {
        new UseInnerClass();
    }
}
