#include <iostream>
#include <cmath>
#include<string>
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
        cout <<endl<< "Loan ID: " << loanID << endl;
        cout <<"Applicant Name: " << applicantName << endl;
        cout << "Loan Amount: " << loanAmount << endl;
        cout << "Annual Interest Rate: " << annualInterestRate << "%" << endl;
        cout << "Loan Tenure: " << loanTenure << " months" << endl;
        cout << "EMI: " << EMI << endl;
    }
};

int main() {

    int id,n;
    string name;
    double amount;
    double interestRate;
    int tenure;
    cout<<"Enter the number of person who need a loan:";
    cin>>n;
    for(int i=1;i<=n;i++)
    {

    cout<<endl<<"Enter the loan id:";
    cin>>id;

    cout<<"Enter the name:";
    cin.ignore();
    getline(cin,name);

    cout<<"Enter the total amount:";
    cin>>amount;

    cout<<"Enter the Interestrate:";
    cin>>interestRate;

    cout<<"Enter the tenure:";
    cin>>tenure;
    }

    for(int i=1;i<=n;i++)
    {
    Loan loan(id, name, amount, interestRate, tenure);
    loan.displayLoanDetails();
    }
    cout<<endl<<"Manush Desai 24CE025";
}
