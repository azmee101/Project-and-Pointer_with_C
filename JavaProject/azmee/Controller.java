package azmee;

import java.io.IOException;

import javafx.application.Platform;
import application.Main;
import javafx.event.ActionEvent;

public class Controller {
	Main main = new Main();
	
	public void exit(ActionEvent event) {
		Platform.exit();
		System.exit(0);
	}
	
	//Scene Switching Methods
	
	public void switchToEmployeeMenu(ActionEvent event) throws IOException {
		main.changeScene("../azmee/Employee.fxml");
	}
	
	public void switchToMainMenu(ActionEvent event) throws IOException {
		main.changeScene("../azmee/Main.fxml");
	}
	public void switchToCreateAccountMenu(ActionEvent event) throws IOException {
		main.changeScene("../azmee/CreateAccount.fxml");
	}	
	
	
	//Link to files of Ripa
	public void savingsAccount(ActionEvent event) throws IOException{
		main.changeScene("../ripa/Savings.fxml");
	}
	
	public void currentAccount(ActionEvent event) throws IOException{
		main.changeScene("../ripa/Current.fxml");
	}
	
	public void studentAccount(ActionEvent event) throws IOException{
		main.changeScene("../ripa/Student.fxml");
	}
	
	//Link to files of Ishrat
	public void depositAndWithdraw(ActionEvent event) throws IOException{
		main.changeScene("../ishrat/Deposit.fxml");
	}
	
	public void transfer(ActionEvent event) throws IOException{
		main.changeScene("../ishrat/Transfer.fxml");
	}
		
	//Link to files of Joysree
	public void accountHolder(ActionEvent event) throws IOException{
		main.changeScene("../joysree/accountHolder.fxml");
	}
	
	public void accountDetails(ActionEvent event) throws IOException{
		main.changeScene("../joysree/accountDetails.fxml");
	}
	
	//Link to files of Ove
	public void transactionDetails(ActionEvent event) throws IOException{
		main.changeScene("../ove/Transactions.fxml");
	}
	
	public void AllAccountDetail(ActionEvent event) throws IOException{
		main.changeScene("../ove/AllAccountDetail.fxml");
	}
	
}
