package application;
public class Bank implements Serializable{
	/**************************** Constructors ***************************/
	public Bank() 
	public Bank(String bankName) 

	/**************************** Methods ***************************/
	
	/**************************** Getter Methods ***************************/
	public String getBankName() 	
	public ArrayList<BankAccount> getAccounts() 
	public ArrayList<BankAccount> getAccounts(String type) 

	/**************************** Add account related methods ***************************/
	private void addAccount(BankAccount acc) 
	public String addAccount(String memberName, String memberNid, double accountBalance,double maxWithdrawLimit)
	public String addAccount(String memberName, String memberNid, double accountBalance, String tradeLicenseNumber) 
	public String addAccount(String memberName, String memberNid, double accountBalance, String institution, String studentId)
	
	/************************* Transaction related methods ************************/
	public void deposit(String accountNumber, double amount) throws InvalidAccountException 
	public void withdraw(String accountNumber, double amount) throws InvalidAccountException, InSufficientBalanceException, MaxWithdawException 
	public void transfer(String fromAccount, String toAccount, double amount) throws InvalidAccountException, InSufficientBalanceException, MaxWithdawException 
	public double getBalance(String accountNumber) throws InvalidAccountException 
	public ArrayList<Transaction> getAccTransactions(String accountNumber) throws InvalidAccountException
	public BankAccount findAccount(String accountNumber) throws InvalidAccountException 
	

	/**************** Customer specific methods ***********************/
	public ArrayList<BankAccount> findAccounts(String memberNid)
	public BankAccount findAccount(String memberNid, String accountNumber) throws InvalidAccountException
	public boolean isValidAccountHolder(String memberNid) 
	public ArrayList<Transaction> getAccTransactions(String memberNid, String accountNumber) throws InvalidAccountException
	
	/**************** Input/Output related methods ***********************/
	public void saveData() throws FileNotFoundException, IOException 
	public void loadData() throws ClassNotFoundException, IOException 
}
