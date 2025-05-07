/* THIS PROGRAM IS PREPARED BY 24CE025
   Date of Modification- 1 May 2025
   7.5 FILE- STUDENT ACADEMIC AND FINANCIAL RECORDS*/
   #include <iostream>
   #include <iomanip>
   #include <vector>
   #include <string>
   using namespace std;
   
   // Custom currency manipulator class
   class Currency {
   private:
       string Symbol;
   
   public:
       Currency(const string& symbol) {
           Symbol = symbol;
       }
   
       friend ostream& operator<<(ostream& output, const Currency& currency) {
           output << currency.Symbol;
           return output;
       }
   };
   
   // Student record class
   class Student {
   public:
       string Name;
       double Marks;
       double TuitionFee;
   
       Student(const string& name, double marks, double tuitionFee) {
           Name = name;
           Marks = marks;
           TuitionFee = tuitionFee;
       }
   };
   
   class UniversitySystem {
   private:
       vector<Student> Students;
       string CurrencySymbol;
   
   public:
       UniversitySystem(const string& currencySymbol = "$") {
           CurrencySymbol = currencySymbol;
       }
   
       void AddStudent(const string& name, double marks, double tuitionFee) {
           Students.push_back(Student(name, marks, tuitionFee));
       }
   
       // Display all student records in a formatted table
       void DisplayStudentRecords() {
           // Print header
           cout << setfill('-') << setw(60) << "" << endl;
           cout << setfill(' ');
           cout << "| " << left << setw(25) << "Student Name"
                     << "| " << setw(10) << "Marks"
                     << "| " << setw(15) << "Tuition Fee" << "|" << endl;
           cout << setfill('-') << setw(60) << "" << endl;
           cout << setfill(' ');
   
           // Print each student record
           for (const auto& student : Students) {
               cout << "| " << left << setw(25) << student.Name
                         << "| " << right << setw(8) << fixed << setprecision(2) << student.Marks
                         << "  | " << right << setw(3) << CurrencySymbol
                         << fixed << setprecision(2) << setw(10) << student.TuitionFee
                         << " |" << endl;
           }
   
           // Print footer
           cout << setfill('-') << setw(60) << "" << endl;
           cout << setfill(' ');
       }
   
       // Calculate and display class statistics
       void DisplayClassStatistics() {
           if (Students.empty()) {
               cout << "No students in the system." << endl;
               return;
           }
   
           double TotalMarks = 0.0;
           double HighestMarks = Students[0].Marks;
           double LowestMarks = Students[0].Marks;
           double TotalFees = 0.0;
   
           for (const auto& student : Students) {
               TotalMarks += student.Marks;
               TotalFees += student.TuitionFee;
   
               if (student.Marks > HighestMarks) {
                   HighestMarks = student.Marks;
               }
               if (student.Marks < LowestMarks) {
                   LowestMarks = student.Marks;
               }
           }
   
           double AverageMarks = TotalMarks / Students.size();
   
           cout << endl << "Class Statistics:" << endl;
           cout << setfill('-') << setw(40) << "" << endl;
           cout << setfill(' ');
           cout << "| Number of Students: " << setw(17) << Students.size() << " |" << endl;
           cout << "| Average Marks: " << setw(22) << fixed << setprecision(2) << AverageMarks << " |" << endl;
           cout << "| Highest Marks: " << setw(22) << fixed << setprecision(2) << HighestMarks << " |" << endl;
           cout << "| Lowest Marks: " << setw(23) << fixed << setprecision(2) << LowestMarks << " |" << endl;
           cout << "| Total Tuition: " << setw(14) << CurrencySymbol
                     << fixed << setprecision(2) << setw(8) << TotalFees << " |" << endl;
           cout << setfill('-') << setw(40) << "" << endl;
           cout << setfill(' ');
       }
   };
   
   int main() {
       string currencySymbol="$";
   
   
       UniversitySystem University(currencySymbol);
   
       int numStudents;
       cout << "Enter the number of students: ";
       cin >> numStudents;
       cin.ignore();
   
       // Add students (Name, Marks, TuitionFee)
       for (int i = 0; i < numStudents; ++i) {
           string name;
           double marks, tuitionFee;
   
           cout << "\nEnter details for student " << i + 1 << ":" << endl;
   
           cout << "Student Name: ";
           getline(cin, name);
   
           cout << "Marks: ";
           cin >> marks;
   
           cout << "Tuition Fee: ";
           cin >> tuitionFee;
           cin.ignore();
   
           University.AddStudent(name, marks, tuitionFee);
       }
   
       cout << endl << "UNIVERSITY STUDENT RECORDS" << endl;
       University.DisplayStudentRecords();
       University.DisplayClassStatistics();
   
       cout << endl << "Manush desai 24CE025" << endl;
   }