package ripa;


import java.io.IOException;
import javax.swing.JOptionPane;

import application.Main;
import javafx.event.ActionEvent;

public class Home {
	
	public static Main main= new Main();
	
	public void Employee(ActionEvent event) throws IOException {
		main.changeScene("Employee Menu.fxml");
		
	}
	public void Exit(ActionEvent event) {
		JOptionPane.showMessageDialog(null,"Thanks For Banking With Us.");
		System.exit(0);
	}
}