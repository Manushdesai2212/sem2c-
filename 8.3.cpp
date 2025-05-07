/* THIS PROGRAM IS PREPARED BY Manush
   Date of Modification - 1 May 2025
   8.3 TEMPLATES - TRANSACTION HISTORY */

   #include <iostream>
   #include <set>
   #include <iterator> // For iterators
   
   using namespace std;
   
   class TransactionProcessor {
   private:
       set<int> uniqueTransactions; // Set to store unique transaction IDs
   
   public:
       // Method to input transaction IDs and remove duplicates
       void inputTransactions() {
           int numTransactions;
           cout << "Enter the number of transactions: ";
           cin >> numTransactions;
   
           cout << "Enter the transaction IDs:\n";
           for (int i = 0; i < numTransactions; ++i) {
               int transactionID;
               cin >> transactionID;
               uniqueTransactions.insert(transactionID); // Insert into the set
           }
       }
   
       // Method to display unique transaction IDs
       void displayUniqueTransactions() const {
           cout << "\nUnique Transaction IDs:\n";
   
           // Iterate through the set and display each transaction ID
           for (const auto& transactionID : uniqueTransactions) {
               cout << transactionID << " ";
           }
           cout << endl;
       }
   };
   
   int main() {
       TransactionProcessor processor;
   
       // Input transaction IDs
       processor.inputTransactions();
   
       // Display unique transaction IDs
       processor.displayUniqueTransactions();
   
       cout << endl << "Manush Desai 24CE025" << endl;
       return 0;
   }