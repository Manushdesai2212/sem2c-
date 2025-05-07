/* THIS PROGRAM IS PREPARED BY Manush Desai
   Date of Modification- 1 May 2025
   8.5 TEMPLATES- DIRECTORY MANAGEMENT*/
   #include <iostream>
   #include <map>
   #include <vector>
   #include <string>
   #include <iterator>
   
   using namespace std;
   
   class DirectoryManager {
   private:
       // Map where the key is the folder name and the value is a vector of filenames
       map<string, vector<string> > directory;
   
   public:
       // Method to create a new folder
       void createFolder(const string& folderName) {
           // Check if the folder already exists
           if (directory.find(folderName) != directory.end()) {
               cout << "Folder '" << folderName << "' already exists.\n";
           } else {
               directory[folderName] = vector<string>(); // Initialize an empty vector for files
               cout << "Folder '" << folderName << "' created successfully.\n";
           }
       }
   
       // Method to add a file to a specific folder
       void addFileToFolder(const string& folderName, const string& fileName) {
           // Check if the folder exists
           if (directory.find(folderName) != directory.end()) {
               directory[folderName].push_back(fileName); // Add the file to the folder
               cout << "File '" << fileName << "' added to folder '" << folderName << "'.\n";
           } else {
               cout << "Folder '" << folderName << "' does not exist.\n";
           }
       }
   
       // Method to display the directory structure
       void displayDirectoryStructure() const {
           cout << "\nDirectory Structure:\n";
           cout << "--------------------\n";
   
           // Iterate through the map and display folders with their files
           for (const auto& folder : directory) {
               cout << folder.first << ":\n"; // Folder name
               // Iterate through the files in the folder and display them
               for (const auto& file : folder.second) {
                   cout << "  - " << file << "\n";
               }
           }
       }
   
       // Method to take user input for folder creation and file addition
       void userInput() {
           int choice;
           while (true) {
               cout << "Directory Management System\n";
               cout << "1. Create Folder\n";
               cout << "2. Add File to Folder\n";
               cout << "3. Display Directory Structure\n";
               cout << "4. Exit\n";
               cout << "Enter your choice: ";
               cin >> choice;
   
               switch (choice) {
                   case 1: {
                       string folderName;
                       cout << "Enter the folder name: ";
                       cin >> folderName;
                       createFolder(folderName);
                       break;
                   }
                   case 2: {
                       string folderName, fileName;
                       cout << "Enter the folder name: ";
                       cin >> folderName;
                       cout << "Enter the file name: ";
                       cin >> fileName;
                       addFileToFolder(folderName, fileName);
                       break;
                   }
                   case 3:
                       displayDirectoryStructure();
                       break;
                   case 4:
                       cout << "Exiting the system.\n";
                       return;
                   default:
                       cout << "Invalid choice. Please try again.\n";
               }
           }
       }
   };
   
   int main() {
       DirectoryManager manager;
   
       // Run the directory management system with user input
       manager.userInput();
   
           cout << endl << "Manush Desai 24CE025 " << endl;
   }
   