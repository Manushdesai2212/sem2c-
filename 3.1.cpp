#include <iostream>
#include <vector>
#include <string>
using namespace std;

inline double calculateTotalSalary(double basic, double bonus) {
    return basic + bonus;
}

class Employee {
private:
    string name;
    double basicSalary;
    double bonus;

public:
    Employee(string empName, double basic, double empBonus = 5000.0) {
        name = empName;
        basicSalary = basic;
        bonus = empBonus;
    }
    void display() {
        double totalSalary = calculateTotalSalary(basicSalary, bonus);
        cout << "Name: " << name << endl;
        cout << "Basic Salary: Rs." << basicSalary << endl;
        cout << "Bonus: Rs." << bonus << endl;
        cout << "Total Salary: Rs." << totalSalary << endl;
        cout << "-----------------------------" << endl;
    }
};

int main() {
    vector<Employee> employees;
    int n;

    cout << "Enter number of employees: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string name;
        double basic, bonus;
        char hasCustomBonus;

        cout << "\nEnter name of employee " << i + 1 << ": ";
        getline(cin, name);

        cout << "Enter basic salary: ";
        cin >> basic;

        cout << "Custom bonus? (y/n): ";
        cin >> hasCustomBonus;

        if (hasCustomBonus == 'y' || hasCustomBonus == 'Y') {
            cout << "Enter custom bonus: ";
            cin >> bonus;
            employees.push_back(Employee(name, basic, bonus));
        } else {
            employees.push_back(Employee(name, basic));
        }

        cin.ignore();
    }

    cout << "\n--- Employee Salary Details ---\n";
    for (int i = 0; i < employees.size(); i++) {
        employees[i].display();
    }

    return 0;
}

