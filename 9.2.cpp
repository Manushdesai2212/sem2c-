/* THIS PROGRAM IS PREPARED BY Manush desai 24CE025
   Date of Modification- 3 May 2025
   9.2 ERROR HANDALING- BANK MANAGEMENT*/
   #include <iostream>
   #include <string>
   #include <ctime> // For timestamp in log
   
   using namespace std;
   
   // A class to represent a bank account
   class BankAccount {
   private:
       string accountNumber;   // Unique identifier for the account
       double balance;         // Account balance
       string transactionHistory[100]; // Simple transaction history array (limit of 100 transactions)
   
       int transactionCount;   // Count of transactions for logging purposes
   
   public:
       // Constructor to initialize a bank account
       BankAccount(string accNumber, double initialBalance)
           : accountNumber(accNumber), balance(initialBalance), transactionCount(0) {}
   
       // Method to log transactions
       void logTransaction(const string& transactionDetail) {
           if (transactionCount < 100) {
               time_t now = time(0);
               char* dt = ctime(&now);
               transactionHistory[transactionCount++] = dt + string(" - ") + transactionDetail;
           }
       }
   
       // Method to deposit money into the account
       void deposit(double amount) {
           if (amount > 0) {
               balance += amount;
               logTransaction("Deposited $" + to_string(amount));
               cout << "Deposited $" << amount << " successfully. New balance: $" << balance << endl;
           } else {
               cout << "Error: Deposit amount must be greater than 0." << endl;
               logTransaction("Failed deposit of negative amount: $" + to_string(amount));
           }
       }
   
       // Method to withdraw money from the account
       void withdraw(double amount) {
           if (amount <= 0) {
               cout << "Error: Withdrawal amount must be greater than 0." << endl;
               logTransaction("Failed withdrawal of negative or zero amount: $" + to_string(amount));
           } else if (amount > balance) {
               cout << "Error: Insufficient funds to withdraw $" << amount << endl;
               logTransaction("Failed withdrawal due to insufficient funds: $" + to_string(amount));
           } else {
               balance -= amount;
               logTransaction("Withdrew $" + to_string(amount));
               cout << "Withdrew $" << amount << " successfully. New balance: $" << balance << endl;
           }
       }
   
       // Method to display the current balance
       void displayBalance() const {
           cout << "Current balance: $" << balance << endl;
       }
   
       // Method to display transaction history
       void displayTransactionHistory() const {
           cout << "\nTransaction History for Account " << accountNumber << ":\n";
           for (int i = 0; i < transactionCount; ++i) {
               cout << transactionHistory[i] << endl;
           }
       }
   };
   
   int main() {
       string accountNumber;
       double initialBalance;
   
       // Get account details from user
       cout << "Enter account number: ";
       cin >> accountNumber;
       cout << "Enter initial balance: $";
       cin >> initialBalance;
   
       // Create a bank account with the entered account number and balance
       BankAccount account(accountNumber, initialBalance);
   
       int option;
       double amount;
   
       while (true) {
           // Menu for user to select an operation
           cout << "\nBanking System Menu\n";
           cout << "1. Deposit Money\n";
           cout << "2. Withdraw Money\n";
           cout << "3. Check Balance\n";
           cout << "4. View Transaction History\n";
           cout << "5. Exit\n";
           cout << "Select an option: ";
           cin >> option;
   
           switch (option) {
               case 1:
                   cout << "Enter deposit amount: $";
                   cin >> amount;
                   account.deposit(amount);
                   break;
   
               case 2:
                   cout << "Enter withdrawal amount: $";
                   cin >> amount;
                   account.withdraw(amount);
                   break;
   
               case 3:
                   account.displayBalance();
                   break;
   
               case 4:
                   account.displayTransactionHistory();
                   break;
   
               case 5:
                   cout << "Exiting the banking system...\n";
                   return 0;
   
               default:
                   cout << "Invalid option! Please try again.\n";
                   break;
           }
       }
   
           cout << endl << "Manush desai 24CE025" << endl;
   }