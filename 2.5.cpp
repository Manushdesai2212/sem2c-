#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

class Loan {
private:
    int loanID;
    string applicantName;
    double loanAmount;
    double annualInterestRate;
    int loanTenure;

public:
    Loan(int id, string name, double amount, double interestRate, int tenure) {
        loanID = id;
        applicantName = name;
        loanAmount = amount;
        annualInterestRate = interestRate;
        loanTenure = tenure;
    }

    double calculateEMI() {
        double P = loanAmount;
        double R = (annualInterestRate / 100) / 12;
        int T = loanTenure;

        double EMI = P * R * pow(1 + R, T) / (pow(1 + R, T) - 1);
        return EMI;
    }

    void displayLoanDetails() {
        double EMI = calculateEMI();
        cout << "\nLoan ID: " << loanID << endl;
        cout << "Applicant Name: " << applicantName << endl;
        cout << "Loan Amount: " << loanAmount << endl;
        cout << "Annual Interest Rate: " << annualInterestRate << "%" << endl;
        cout << "Loan Tenure: " << loanTenure << " months" << endl;
        cout << "EMI: " << EMI << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of people who need a loan: ";
    cin >> n;

    vector<Loan> loans;

    for (int i = 0; i < n; i++) {
        int id;
        string name;
        double amount;
        double interestRate;
        int tenure;

        cout << "\nEnter the loan id: ";
        cin >> id;

        cout << "Enter the name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter the total amount: ";
        cin >> amount;

        cout << "Enter the interest rate (%): ";
        cin >> interestRate;

        cout << "Enter the tenure (months): ";
        cin >> tenure;

        loans.emplace_back(id, name, amount, interestRate, tenure);
    }

    for (int i = 0; i < n; i++) {
        loans[i].displayLoanDetails();
    }

    cout << "\nManush Desai 24CE025\n";
}
