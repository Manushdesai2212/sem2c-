/* THIS PROGRAM IS PREPARED BY 24ce025 Manush desai
   Date of Modification- 15 March 2025
   4.5 INHERITANCE-GRADE DEFINGING SYSTEM  */

   #include<iostream>
   #include<string>
   using namespace std;
   
   class GradingSystem
   {
   protected:
       string studentname;
       float marks;
   public:
       GradingSystem(string name, float m) : studentname(name), marks(m) {}
   
       virtual void computeGrade() = 0;
   
       void displayStudentInfo()
       {
           cout << "Student Name: " << studentname << endl;
           cout << "Marks: " << marks << endl;
       }
   };
   
   class UnderGraduate : public GradingSystem
   {
   public:
       UnderGraduate(string name, float m) : GradingSystem(name, m) {}
   
       void computeGrade() override
       {
           string grade;
           if (marks >= 90)
           {
               grade = "A+";
           }
           else if (marks >= 80)
           {
               grade = "A";
           }
           else if (marks >= 70)
           {
               grade = "B+";
           }
           else if (marks >= 60)
           {
               grade = "B";
           }
           else if (marks >= 50)
           {
               grade = "C";
           }
           else
           {
               grade = "F";
           }
           cout << "GRADE: " << grade << endl;
       }
   };
   
   class PostGraduate : public GradingSystem
   {
   public:
       PostGraduate(string name, float m) : GradingSystem(name, m) {}
   
       void computeGrade() override
       {
           string grade;
           if (marks >= 85)
           {
               grade = "A+";
           }
           else if (marks >= 75)
           {
               grade = "A";
           }
           else if (marks >= 65)
           {
               grade = "B+";
           }
           else if (marks >= 55)
           {
               grade = "B";
           }
           else if (marks >= 45)
           {
               grade = "C";
           }
           else
           {
               grade = "F";
           }
           cout << "GRADE: " << grade << endl;
       }
   };
   
   int main()
   {
       int choice;
       string name;
       float marks;
       int student_type;
       GradingSystem* students[100];
       int student_count = 0;
   
       do
       {
           cout << "1. Add UnderGraduate Student\n"
                << "2. Add PostGraduate Student\n"
                << "3. Display Student Grades\n"
                << "4. Exit\n";
           cout << "Enter your choice: ";
           cin >> choice;
   
           GradingSystem* student = nullptr;
   
           switch (choice)
           {
           case 1:
               cout << "Enter UnderGraduate student name: ";
               cin >> name;
               cout << "Enter marks for " << name << ": ";
               cin >> marks;
               student = new UnderGraduate(name, marks);
               students[student_count++] = student;
               student->displayStudentInfo();
               student->computeGrade();
               break;
   
           case 2:
               cout << "Enter PostGraduate student name: ";
               cin >> name;
               cout << "Enter marks for " << name << ": ";
               cin >> marks;
               student = new PostGraduate(name, marks);
               students[student_count++] = student;
               student->displayStudentInfo();
               student->computeGrade();
               break;
   
           case 3:
               if (student_count == 0)
               {
                   cout << "No student records available." << endl;
               }
               else
               {
                   cout<<endl<<"DISPLAYING STUDENT RECORDS"<<endl;
                   for (int i = 0; i < student_count; i++)
                   {
                       cout<<"STUDENT "<<i+1<<":"<<endl;
                       students[i]->displayStudentInfo();
                       students[i]->computeGrade();
                   }
               }
               break;
   
           case 4:
               cout << "Exiting program." << endl;
               for (int i = 0; i < student_count; i++)
               {
                   delete students[i];
               }
               break;
   
           default:
               cout << "Invalid choice, please try again." << endl;
               break;
           }
       }
       while (choice != 4);
   
       cout<<endl<<"Mnaush desai 24CE025"<<endl;
   }