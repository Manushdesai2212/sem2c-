/* THIS PROGRAM IS PREPARED BY Mnaush
   Date of Modification- 1 May 2025
   8.4 TEMPLATES- RANKING STUDENTS*/
   #include <iostream>
   #include <vector>
   #include <string>
   #include <algorithm> // For sorting
   
   using namespace std;
   
   // Comparator function to sort by score in descending order
   bool compareScores(const pair<string, int>& a, const pair<string, int>& b) {
       return a.second > b.second; // Sort in descending order of score
   }
   
   class StudentRankingSystem {
   private:
       vector<pair<string, int> > students; // Vector to store student name and score pairs
   
   public:
       // Method to input student names and their scores
       void inputStudents() {
           int numStudents;
           cout << "Enter the number of students: ";
           cin >> numStudents;
   
           // Input student names and scores
           for (int i = 0; i < numStudents; ++i) {
               string name;
               int score;
   
               cout << "Enter name of student " << i + 1 << ": ";
               cin >> name;
               cout << "Enter score of " << name << ": ";
               cin >> score;
   
               students.push_back(make_pair(name, score)); // Add student record to vector
           }
       }
   
       // Method to sort students by score in descending order
       void sortStudents() {
           sort(students.begin(), students.end(), compareScores); // Sort using custom comparator
       }
   
       // Method to display the ranked list of students
       void displayRankedStudents() const {
           cout << "\nRanked Student List (Highest to Lowest Score):\n";
           cout << "-----------------------------------------------\n";
   
           // Iterate through the sorted vector and display names and scores
           for (const auto& student : students) {
               cout << "Rank " << &student - &students[0] + 1 << ": " << student.first << " - " << student.second << endl;
           }
       }
   };
   
   int main() {
       StudentRankingSystem rankingSystem;
   
       // Input student data
       rankingSystem.inputStudents();
   
       // Sort students by score
       rankingSystem.sortStudents();
   
       // Display ranked students
       rankingSystem.displayRankedStudents();
   
           cout << endl << "Manush Desai 24CE025" << endl;
   }
   