/* THIS PROGRAM IS PREPARED BYManush
   Date of Modification- 3 May 2025
   9.1 ERROR HANDALING- LOAN MANAGEMENT*/
   #include <iostream>
   #include <string>
   #include <limits> // For numeric_limits
   
   using namespace std;
   
   // Function to validate if input is a valid number
   bool isValidNumber(const string& input) {
       for (char c : input) {
           if (!isdigit(c) && c != '.') { // Allow digits and decimal point
               return false;
           }
       }
       return true;
   }
   
   // Function to calculate and display the loan-to-income ratio
   void calculateLoanToIncomeRatio(double loanAmount, double annualIncome) {
       if (annualIncome == 0) {
           cout << "Error: Annual income cannot be zero. Division by zero is not allowed.\n";
       } else {
           double ratio = loanAmount / annualIncome;
           cout << "Loan-to-Income Ratio: " << ratio << endl;
       }
   }
   
   int main() {
       double loanAmount = 0;
       double annualIncome = 0;
   
       string input;
   
       // Prompt for the loan amount
       while (true) {
           cout << "Enter the loan amount: ";
           getline(cin, input);
   
           // Check if input is a valid number
           try {
               loanAmount = stod(input); // Convert string to double
               if (loanAmount <= 0) {
                   cout << "Please enter a positive loan amount.\n";
                   continue;
               }
               break; // Valid input, break the loop
           } catch (const invalid_argument& e) {
               cout << "Invalid input. Please enter a valid numeric loan amount.\n";
           }
       }
   
       // Prompt for the annual income
       while (true) {
           cout << "Enter your annual income: ";
           getline(cin, input);
   
           // Check if input is a valid number
           try {
               annualIncome = stod(input); // Convert string to double
               if (annualIncome <= 0) {
                   cout << "Please enter a positive annual income.\n";
                   continue;
               }
               break; // Valid input, break the loop
           } catch (const invalid_argument& e) {
               cout << "Invalid input. Please enter a valid numeric income value.\n";
           }
       }
   
       // Calculate and display the loan-to-income ratio
       calculateLoanToIncomeRatio(loanAmount, annualIncome);
   
           cout << endl << "Manush Desai 24CE025" << endl;
   }