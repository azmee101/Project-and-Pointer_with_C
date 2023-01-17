package ishrat;

import java.io.IOException;

import application.Main;
import banking.InSufficientBalanceException;
import banking.InvalidAccountException;
import banking.MaxWithdawException;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.TextField;

public class transacionsController {
	Main main = new Main(); // Added by azmee
	 @FXML
	 TextField acNumTf;
	 @FXML
	 TextField amtTf;
	 @FXML
	 TextField fromAcTf;
	 @FXML
	 TextField toAcTf;
	 
	 
	public void withdraw() throws InSufficientBalanceException, MaxWithdawException {
		 String accNum = acNumTf.getText();
		 double amt = Double.parseDouble(amtTf.getText());
		 try {
			Main.bank.withdraw(accNum, amt);
		} catch (InvalidAccountException e) {
			e.printStackTrace();
		}
	 }
	 
	 public void deposit() {
		 String accNum = acNumTf.getText();
		 double amt = Double.parseDouble(amtTf.getText());
		 try {
			Main.bank.deposit(accNum, amt);
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
	 public void transfer() throws InSufficientBalanceException, MaxWithdawException {
		 String fromAccNum = fromAcTf.getText();
		 String toAccNum = toAcTf.getText();
		 double amt = Double.parseDouble(amtTf.getText());
	 	try {
			Main.bank.transfer(fromAccNum,toAccNum,amt);
		} catch (InvalidAccountException e) {
			e.printStackTrace();
		}
		 
	 }
}
