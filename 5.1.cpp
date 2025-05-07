/* THIS PROGRAM IS PREPARED BY 24CE025 Manush desai
   Date of Modification- 20 April 2025
   5.1 OVERLOADING-MAKING A SIMPLE ADDITION CALCULATOR  */

#include <iostream>
using namespace std;

class Calculator {
private:
    double results[100];
    int resultCount = 0;

    void storeResult(double value) {
        if (resultCount < 100) {
            results[resultCount] = value;
            resultCount++;
        }
    }

public:
    int add(int a, int b) {
        int result = a + b;
        storeResult(result);
        return result;
    }

    double add(double a, double b) {
        double result = a + b;
        storeResult(result);
        return result;
    }

    double add(int a, double b) {
        double result = a + b;
        storeResult(result);
        return result;
    }

    double add(double a, int b) {
        double result = a + b;
        storeResult(result);
        return result;
    }

    void displayResults() const {
        cout << "\n--- Results ---\n";
        for (int i = 0; i < resultCount; ++i) {
            cout << "Result " << (i + 1) << ": " << results[i] << endl;
        }
    }
};

int main() {
    Calculator calc;
    int choice;

    do {
        cout << "Select input types for addition:\n";
        cout << "1. int + int\n";
        cout << "2. double + double\n";
        cout << "3. int + double\n";
        cout << "4. double + int\n";
        cout << "5. Display all results\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int a, b;
                cout << "Enter two integers: ";
                cin >> a >> b;
                int result = calc.add(a, b);
                cout << "Result: " << result << endl;
                break;
            }
            case 2: {
                double a, b;
                cout << "Enter two doubles: ";
                cin >> a >> b;
                double result = calc.add(a, b);
                cout << "Result: " << result << endl;
                break;
            }
            case 3: {
                int a;
                double b;
                cout << "Enter an integer and a double: ";
                cin >> a >> b;
                double result = calc.add(a, b);
                cout << "Result: " << result << endl;
                break;
            }
            case 4: {
                double a;
                int b;
                cout << "Enter a double and an integer: ";
                cin >> a >> b;
                double result = calc.add(a, b);
                cout << "Result: " << result << endl;
                break;
            }
            case 5: {
                calc.displayResults();
                break;
            }
            case 6: {
                cout << "Exiting...\n";
                break;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 6);

    cout << endl << "Manush desai 24CE025" << endl;
}