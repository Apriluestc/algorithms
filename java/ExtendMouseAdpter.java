import java.awt.event.*;
import javax.swing.*;
public class ExtendMouseAdpter extends MouseAdpter {
    JFrame f;
    public ExtendMouseAdpter() {
        f = new JFrame();
        f.setSize(300, 150);
        f.setVisible(true);
        f.addMouseListener(this);
        f.setDefaultCloseOperation(JFrame.HIDE_ON_CLOSE);
    }
    public void mouseClicked(MouseEvent e) {
        f.setTitle("点击坐标为("+e.getX()+", "+e.getY()+")");
    }
    public static void main(String[] args) {
        new ExtendMouseAdpter();
    }
}
