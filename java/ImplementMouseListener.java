import java.awt.event.*;
import javax.swing.*;
public class ImplementMouseListener implements MouseListener {
    JFrame f;
    public ImplementMouseListener() {
        f = new JFrame();
        f.setSize(300, 150);
        f.setVisible(true);
        f.addMouseListener(this);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    public void mousePressed(MouseEvent e) {}
    public void mouseReleaseed(MouseEvent e) {}
    public void mouseEntered(MouseEvent e) {}
    public void mouseExited(MouseEvent e) {}
    public void mouseClicked(MouseEvent e) {
        f.setTitle("点击坐标为("+e.getX()+", "+e.getY()+")");
    }
    public static void main(String[] args) {
        new ImplementMouseListener();
    }
}
