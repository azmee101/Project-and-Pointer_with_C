package ripa;

import java.io.IOException;

import application.Main;
import banking.BankAccount;
import banking.DataHandler;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

public class Current {
	BankAccount Bacc;
	
	@FXML
	TextField Name;
	@FXML
	TextField Nid;
	@FXML
	TextField Trade;
	@FXML
	TextField Balance;
	@FXML
	Label mylabel;
	
	public void Submit(ActionEvent event) throws IOException {
		String name = Name.getText();
		String nid = Nid.getText();
		String trade = Trade.getText();
		double balance = Double.parseDouble(Balance.getText());
		String AccNum = Main.bank.addAccount(name, nid, balance, trade);
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
	
	  public void clear02(ActionEvent event) {
	    	Name.clear();
			Nid.clear();
			Trade.clear();
			Balance.clear();
			mylabel.setText(null);
			 
	    	
	    }
}