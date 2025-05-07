/* THIS PROGRAM IS PREPARED BY 24CE025_manush
   Date of Modification- 15 March 2025
   4.4 INHERITANCE-ACCOUNT MANAGEMENT INFO */

   #include<iostream>
   #include<fstream>
   #include<string>
   using namespace std;
   
   class BankingAccount
   {
   protected:
       int accno;
       float accbal;
       float prebal;
   public:
       BankingAccount(int n, float b)
       {
           accno = n;
           accbal = b;
       }
       virtual void deposit(float amount, const string& transaction_file)
       {
           prebal = accbal;
           accbal += amount;
           ofstream file(transaction_file, ios::app);
           if (file.is_open())
           {
               file << "Deposited: " << amount << " | Balance: " << accbal << endl;
               file.close();
           }
           else
           {
               cout << "Error opening transaction file." << endl;
           }
       }
       virtual void withdraw(float amount, const string& transaction_file)
       {
           prebal = accbal;
           if (accbal >= amount)
           {
               accbal -= amount;
               ofstream file(transaction_file, ios::app);
               if (file.is_open())
               {
                   file << "Withdrawn: " << amount << " | Balance: " << accbal << endl;
                   file.close();
               }
               else
               {
                   cout << "Error opening transaction file." << endl;
               }
           }
           else
           {
               cout << "Insufficient funds." << endl;
           }
       }
       void undoLastTransaction(const string& transaction_file)
       {
           accbal = prebal;
           ofstream file(transaction_file, ios::app);
           if (file.is_open())
           {
               file << "Transaction undone | Balance: " << accbal << endl;
               file.close();
           }
           else
           {
               cout << "Error opening transaction file." << endl;
           }
       }
   };
   
   class SavingAccount : public BankingAccount
   {
       int interestrate;
   public:
       SavingAccount(int num, float bal, int r) : BankingAccount(num, bal)
       {
           interestrate = r;
       }
       void applyinterest(const string& transaction_file)
       {
           float interest = (accbal * interestrate) / 100;
           accbal += interest;
           ofstream file(transaction_file, ios::app);
           if (file.is_open())
           {
               file << "Applied interest: " << interest << " | Balance: " << accbal << endl;
               file.close();
           }
           else
           {
               cout << "Error opening transaction file." << endl;
           }
       }
   };
   
   class currentaccount : public BankingAccount
   {
       float limit;
   public:
       currentaccount(int num, float bal, float lim) : BankingAccount(num, bal)
       {
           limit = lim;
       }
       void withdraw(float amount, const string& transaction_file) override
       {
           prebal = accbal;
           if (accbal + limit >= amount)
           {
               accbal -= amount;
               ofstream file(transaction_file, ios::app);
               if (file.is_open())
               {
                   file << "Withdrawn: " << amount << " | Balance: " << accbal << endl;
                   file.close();
               }
               else
               {
                   cout << "Error opening transaction file." << endl;
               }
           }
           else
           {
               cout << "Exceeds overdraft limit." << endl;
           }
       }
   };
   
   void showTransactionHistory(const string& transaction_file)
   {
       ifstream file(transaction_file);
       string line;
       if (file.is_open())
       {
           while (getline(file, line))
           {
               cout << line << endl;
           }
           file.close();
       }
       else
       {
           cout << "No transaction history available." << endl;
       }
   }
   
   int main()
   {
       int choice, acc_counter = 0;
       int number, rate;
       float balance, limit;
       SavingAccount* s = nullptr;
       currentaccount* c = nullptr;
       string transaction_file;
   
       cout<<"MENU-"<<endl;
   
       cout << "1  Create saving account\n2  Create current account\n"
            << "3  Deposit to saving account\n4  Withdraw from saving account\n"
            << "5  Deposit to current account\n6  Withdraw from current account\n"
            << "7  See transaction history\n8  Undo last transaction\n9  Exit";
   
       do
       {
           cout << endl << "Enter your choice: ";
           cin >> choice;
   
           switch (choice)
           {
           case 1:
               cout << "Enter account number for saving account: ";
               cin >> number;
               cout << "Enter initial balance for saving account: ";
               cin >> balance;
               cout << "Enter interest rate: ";
               cin >> rate;
               s = new SavingAccount(number, balance, rate);
               transaction_file = "SavingAccount_" + to_string(number) + "_transactions.txt";
               acc_counter++;
               cout<<endl<<"YOUR SAVINGS ACCOUNT HAS BEEN CREATED!"<<endl;
               break;
   
           case 2:
               cout << "Enter account number for current account: ";
               cin >> number;
               cout << "Enter initial balance for current account: ";
               cin >> balance;
               cout << "Enter overdraft limit: ";
               cin >> limit;
               c = new currentaccount(number, balance, limit);
               transaction_file = "currentaccount_" + to_string(number) + "_transactions.txt";
               acc_counter++;
               cout<<endl<<"YOUR CURRENT ACCOUNT HAS BEEN CREATED!"<<endl;
   
               break;
   
           case 3:
               if (s)
               {
                   float deposit_amount;
                   cout << "Enter deposit amount: ";
                   cin >> deposit_amount;
                   s->deposit(deposit_amount, transaction_file);
                   cout<<endl<<"MONEY DEPOSITED TO SAVINGS ACCOUNT!"<<endl;
   
               }
               else
               {
                   cout << "No saving account created." << endl;
               }
               break;
   
           case 4:
               if (s)
               {
                   float withdraw_amount;
                   cout << "Enter withdraw amount: ";
                   cin >> withdraw_amount;
                   s->withdraw(withdraw_amount, transaction_file);
                   cout<<endl<<"MONEY WITHDRAWED FROM SAVINGS ACCOUNT!"<<endl;
   
               }
               else
               {
                   cout << "No saving account created." << endl;
               }
               break;
   
           case 5:
               if (c)
               {
                   float deposit_amount;
                   cout << "Enter deposit amount: ";
                   cin >> deposit_amount;
                   c->deposit(deposit_amount, transaction_file);
                   cout<<endl<<"MONEY DEPOSITED TO CURRENT ACCOUNT!"<<endl;
   
               }
               else
               {
                   cout << "No current account created." << endl;
               }
               break;
   
           case 6:
               if (c)
               {
                   float withdraw_amount;
                   cout << "Enter withdraw amount: ";
                   cin >> withdraw_amount;
                   c->withdraw(withdraw_amount, transaction_file);
                   cout<<endl<<"MONEY WITHDRAWED FROM CURRENT ACCOUNT!"<<endl;
   
               }
               else
               {
                   cout << "No current account created." << endl;
               }
               break;
   
           case 7:
               showTransactionHistory(transaction_file);
               break;
   
           case 8:
               if (s)
               {
                   s->undoLastTransaction(transaction_file);
               }
               else if (c)
               {
                   c->undoLastTransaction(transaction_file);
               }
               else
               {
                   cout << "No account created." << endl;
               }
               break;
   
           case 9:
               cout << "Exiting system." << endl;
               break;
   
           default:
               cout << "Invalid choice." << endl;
               break;
           }
       }
       while (choice != 9);
   
       delete s;
       delete c;
   
       cout<<endl<<"Manush desai 24ce025"<<endl;
   }