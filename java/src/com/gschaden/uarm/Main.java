package com.gschaden.uarm;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionAdapter;

import javax.swing.JFrame;


public class Main {

	JFrame frame;
	UArm uarm;

	public Main(UArm u) {
		this.uarm = u;
		frame = new JFrame();
		frame.setSize(800, 600);
		frame.setVisible(true);
		frame.addMouseMotionListener(new MouseMotionAdapter() {
			@Override
			public void mouseDragged(MouseEvent e) {
				int rotation = 180 - e.getX()*180/frame.getWidth();
				int a = e.getY()*180/frame.getHeight();
				uarm.gotoPosition(rotation, a, a);
			}
		});
		frame.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {			
				int rotation = 180 - e.getX()*180/frame.getWidth();
				int a = e.getY()*180/frame.getHeight();
				uarm.gotoPosition(rotation, a, a);
			}
		});
	}

	public static void main(String[] args) throws Exception {
		UArm uarm = new UArm("COM19");
		Main main = new Main(uarm);
		
	}
}
