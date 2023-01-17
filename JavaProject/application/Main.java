package application;   
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene; 
import javafx.stage.Stage;
import javafx.scene.layout.AnchorPane;

import java.io.IOException;

import banking.Bank;
import banking.InSufficientBalanceException;
import banking.InvalidAccountException;
import banking.MaxWithdawException;
public class Main extends Application{
	public static Stage stage;
	public static Bank bank = new Bank("ARIOJ BANK LIMITED");
    @Override  
    public void start(Stage primaryStage){  
        try {
        	stage = primaryStage;
	        AnchorPane root = FXMLLoader.load(getClass().getResource("../azmee/Main.fxml"));
	        Scene scene=new Scene(root,600,400);      
	        primaryStage.setTitle("ARIOJ BANK LIMITED");  
	        primaryStage.setScene(scene);  
	        primaryStage.show();
        }catch(Exception e) {
        	e.printStackTrace();
        }
    }
    
    public void changeScene(String fxml) throws IOException {
		Parent root = FXMLLoader.load(getClass().getResource(fxml)); 
        stage.getScene().setRoot(root);
	}
    
    public static void createDemo() throws IOException, InvalidAccountException{
    	String zero = bank.addAccount("Azmee","001",6100.0,1001.0);
    	String one = bank.addAccount("Tofail","002",000.0,"009");
    	bank.addAccount("Anonymous", "005", 5000.0, "UAP", "999");
    	try {
    		bank.deposit(zero, 1000.00);
        	bank.deposit(zero, 1000.00);
        	bank.deposit(zero, 1000.00);
        	bank.deposit(zero, 1000.00);
        	bank.deposit(zero, 1000.00);
        	bank.deposit(zero, 1000.00);
			bank.withdraw(zero, 500.0);
			bank.deposit(zero, 1000.00);
	    	bank.withdraw(zero, 1000.00);
	    	bank.deposit(zero, 1000.00);
	    	bank.deposit(zero, 1000.00);
		} catch (InvalidAccountException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (InSufficientBalanceException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (MaxWithdawException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
        System.out.println(bank.getBankName());
        System.out.println(bank.getAccounts());
        System.out.println(zero);
        System.out.println(one);
        System.out.println(bank.findAccount(zero));
    }
    
    public static void main (String[] args) throws IOException, InvalidAccountException  
    {  
        createDemo();
        System.out.println(bank.getBankName());
        System.out.println(bank.getAccounts());
        
    	launch(args);  
    }
}