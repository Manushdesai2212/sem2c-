
#include <vector>
using namespace std;

class Account
 {
private:
    int accountNumber;
    string holderName;
    double balance;
    static int accountCount;

public:
    Account(int number, string name, double initialBalance) {
        accountNumber = number;
        holderName = name;
        balance = initialBalance;
        accountCount++;
    }

    void display() {
        cout << "Account No: " << accountNumber << ", Holder: " << holderName << ", Balance: Rs." << balance << endl;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    double getBalance() {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }

    static int getTotalAccounts() {
        return accountCount;
    }
};

int Account::accountCount = 0;

// Transfer without using pointer
void transferMoney(Account& from, Account& to, double amount) {
    if (from.withdraw(amount)) {
        to.deposit(amount);
        cout << "Transfer successful!" << endl;
    } else {
        cout << "Insufficient balance!" << endl;
    }
}

int main() {
    vector<Account> accounts;
    int choice;

    do {
        cout << "\nBank Account Management\n";
        cout << "1. Create Account\n2. Display Accounts\n3. Transfer Money\n4. Total Accounts\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int accNo;
            string name;
            double bal;
            cout << "Enter Account Number: ";
            cin >> accNo;
            cin.ignore();
            cout << "Enter Holder Name: ";
            getline(cin, name);
            cout << "Enter Initial Balance: ";
            cin >> bal;
            accounts.push_back(Account(accNo, name, bal));
            cout << "Account created!\n";
        }
        else if (choice == 2) {
            for (int i = 0; i < accounts.size(); i++) {
                accounts[i].display();
            }
        }
        else if (choice == 3) {
            int fromAcc, toAcc;
            double amt;
            bool fromFound = false, toFound = false;
            int fromIndex = -1, toIndex = -1;

            cout << "Enter From Account No: ";
            cin >> fromAcc;
            cout << "Enter To Account No: ";
            cin >> toAcc;
            cout << "Enter Amount: ";
            cin >> amt;

            for (int i = 0; i < accounts.size(); i++) {
                if (accounts[i].getAccountNumber() == fromAcc) {
                    fromFound = true;
                    fromIndex = i;
                }
                if (accounts[i].getAccountNumber() == toAcc) {
                    toFound = true;
                    toIndex = i;
                }
            }

            if (fromFound && toFound) {
                transferMoney(accounts[fromIndex], accounts[toIndex], amt);
            } else {
                cout << "Invalid account numbers!\n";
            }
        }
        else if (choice == 4) {
            cout << "Total accounts created: " << Account::getTotalAccounts() << endl;
        }

    } while (choice != 5);

    return 0;
}
