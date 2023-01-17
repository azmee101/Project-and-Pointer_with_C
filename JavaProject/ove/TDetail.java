package ove;

import java.io.IOException;
import java.util.ArrayList;

import application.Main;
import banking.InvalidAccountException;
import banking.Transaction;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.ListView;
import javafx.scene.control.TextField;

public class TDetail {
	Main main = new Main();
	 @FXML
	 TextField acNumTf;
	 @FXML
	 ListView<String> listView;
	 
	 
	 public void getAccTransaction() throws InvalidAccountException{
		 String accNum = acNumTf.getText();
	 	try {
	 		ArrayList <Transaction> transactions = new ArrayList<>();
			transactions = Main.bank.getAccTransactions(accNum);
			for(int i = 0 ; i < transactions.size() ; i++) {
				
				listView.getItems().add(transactions.get(i).toString());
				
			}
		
		} catch (InvalidAccountException e) {
			e.printStackTrace();
		}
	 }
	 
	 public void home(ActionEvent event) throws IOException{
			main.changeScene("../azmee/Main.fxml");
	 }
	 public void back(ActionEvent event) throws IOException{
			main.changeScene("../azmee/Employee.fxml");
	 }
}
