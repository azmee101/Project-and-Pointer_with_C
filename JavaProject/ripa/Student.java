package ripa;

import java.io.IOException;

import application.Main;
import banking.BankAccount;
import banking.DataHandler;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

public class Student {
	BankAccount Bacc;
	
	@FXML
	TextField Name;
	@FXML
	TextField Nid;
	@FXML
	TextField insName;
	@FXML
	TextField id;
	@FXML
	TextField Bal;
	@FXML
	Label mylabel;
	
	public void Submit(ActionEvent event) throws IOException {
		String name = Name.getText();
		String nid = Nid.getText();
		String ins = insName.getText();
		String Id = id.getText();
		double balance = Double.parseDouble(Bal.getText());
		String AccNum = Main.bank.addAccount(name, nid, balance, ins, Id);
		
		mylabel.setText("Account Created Successfully.\nYour Account Number is: "+AccNum);
		DataHandler.saveData(Main.bank);
		//Home.main.changeScene("Employee Menu.fxml");
	}
	
	public void Home(ActionEvent event) throws IOException {
		Home.main.changeScene("../azmee/Main.fxml");
	}
	
	public void Back(ActionEvent event) throws IOException {
		Home.main.changeScene("../azmee/CreateAccount.fxml");
	}
	
	 public void clear03(ActionEvent event) {
	    	Name.clear();
			Nid.clear();
			id.clear();
			insName.clear();
			Bal.clear();
			mylabel.setText(null);
			 
	    	
	    }
}
