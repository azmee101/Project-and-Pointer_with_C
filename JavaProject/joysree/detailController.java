package joysree;

import java.io.IOException;

import application.Main;
import banking.InvalidAccountException;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

public class detailController {
	Main main = new Main();
	@FXML
	 TextField acNumTf;
	
	 @FXML
	 Label detail;
	 
	 public void findAccount() throws InvalidAccountException{
		 String accNum = acNumTf.getText();
			try {
				String bankAcc = Main.bank.findAccount(accNum).toString();
				detail.setText(bankAcc);
			} catch (InvalidAccountException e) {
				e.printStackTrace();
			}
	 }
	 
	 public void accountDetails(ActionEvent event) throws IOException{
			main.changeScene("../joysree/accountDetails.fxml");
	 }
	 
	 public void transactionDetails(ActionEvent event) throws IOException{
			main.changeScene("../ove/Transactions.fxml");
		}
	 
	 public void home(ActionEvent event) throws IOException{
			main.changeScene("../azmee/Main.fxml");
	 }
	 public void back(ActionEvent event) throws IOException{
			main.changeScene("../azmee/Main.fxml");
	 }
	 
	 public void exit(ActionEvent event) {
		 System.exit(0);
	 }
	 
	 
}
