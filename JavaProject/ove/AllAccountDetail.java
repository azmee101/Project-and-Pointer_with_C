package ove;

import java.io.IOException;
import java.net.URL;
import java.util.ArrayList;
import java.util.ResourceBundle;

import application.Main;
import banking.BankAccount;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.ComboBox;
import javafx.scene.control.ListView;

public class AllAccountDetail implements Initializable {
	Main main = new Main();
	 @FXML
	 private ComboBox<String> comboBox;
	 @FXML
	 ListView<String> accountList;
	
	
	 
	 public void run() {
	
		 String s = comboBox.getSelectionModel().getSelectedItem().toString();
		 	if(s.equals("All")) {
	        	try {
	        		accountList.getItems().clear();
	    			ArrayList <BankAccount> accounts = new ArrayList<>();
	    			accounts = Main.bank.getAccounts();
	    			for(int i = 0 ; i < accounts.size() ; i++) {
	    				
	    				accountList.getItems().add(accounts.get(i).toString());
	    				
	    			}
	    			
	    		}catch(Exception e1) {
	    			e1.printStackTrace();
	    		}
	        }
	        if(s.equals("Current Account")) {
	        	try {
	    			accountList.getItems().clear();
	        		ArrayList <BankAccount> accounts = new ArrayList<>();
	    			accounts = Main.bank.getAccounts("current");
	    			for(int i = 0 ; i < accounts.size() ; i++) {
	    				
	    				
	    				accountList.getItems().add(accounts.get(i).toString());
	    				
	    				
	    			}
	    		}catch(Exception e1) {
	    			e1.printStackTrace();
	    		}
	        }
	        if(s.equals("Student Account")) {
	        	try {
	        		accountList.getItems().clear();
	        		ArrayList <BankAccount> accounts = new ArrayList<>();
	    			accounts = Main.bank.getAccounts("student");
	    			for(int i = 0 ; i < accounts.size() ; i++) {
	    				
	    				accountList.getItems().add(accounts.get(i).toString());
	    				
	    			}
	    		}catch(Exception e1) {
	    			e1.printStackTrace();
	    		}
	        }
	        if(s.equals("Savings Account")) {
	        	try {
	        		accountList.getItems().clear();
	        		ArrayList <BankAccount> accounts = new ArrayList<>();
	    			accounts = Main.bank.getAccounts("saving");
	    			for(int i = 0 ; i < accounts.size() ; i++) {
	    				
	    				accountList.getItems().add(accounts.get(i).toString());
	    				
	    			}
	    		}catch(Exception e1) {
	    			e1.printStackTrace();
	    		}
	        }
	 }
	 
	 @Override
	public void initialize(URL arg0, ResourceBundle arg1) {
		 ObservableList<String> list = FXCollections.observableArrayList("All","Savings Account","Current Account","Student Account");
         comboBox.setItems(list);
	}
	 
	 public void home(ActionEvent event) throws IOException{
			main.changeScene("../azmee/Main.fxml");
	 }
	 public void back(ActionEvent event) throws IOException{
			main.changeScene("../azmee/Employee.fxml");
	 }
}
