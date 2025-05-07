/* THIS PROGRAM IS PREPARED BY Mnaush desai 24Ce025
   Date of Modification- 1 May 2025
   7.2 FILE- DOCUMENT STATASTICS*/
   #include <iostream>
   #include <fstream>
   #include <cstring>
   #include <cctype>
   using namespace std;
   
   const int INITIAL_CAPACITY = 10;
   const int MAX_LINE_LENGTH = 1000;
   
   // Checks if a character is a word delimiter
   bool isDelimiter(char ch) {
       return !isalpha(ch);
   }
   
   // Count words in a line manually
   int countWords(const char* line) {
       int count = 0;
       bool inWord = false;
   
       for (int i = 0; line[i]; ++i) {
           if (isDelimiter(line[i])) {
               inWord = false;
           } else if (!inWord) {
               inWord = true;
               count++;
           }
       }
   
       return count;
   }
   
   int main() {
       char filename[100];
       cout << "Enter the filename: ";
       cin.getline(filename, 100);
   
       ifstream inFile(filename);
   
       if (!inFile) {
           cerr << "Error: Cannot open file '" << filename << "'.\n";
           return 1;
       }
   
       // Dynamically allocate space for lines
       char** lines = new char*[INITIAL_CAPACITY];
       int capacity = INITIAL_CAPACITY;
       int lineCount = 0;
       int wordCount = 0;
       int charCount = 0;
   
       char buffer[MAX_LINE_LENGTH];
   
       while (inFile.getline(buffer, MAX_LINE_LENGTH)) {
           // Dynamically store the line
           if (lineCount == capacity) {
               int newCapacity = capacity * 2;
               char** newLines = new char*[newCapacity];
   
               for (int i = 0; i < lineCount; ++i) {
                   newLines[i] = lines[i];
               }
   
               delete[] lines;
               lines = newLines;
               capacity = newCapacity;
           }
   
           int len = strlen(buffer);
           char* lineCopy = new char[len + 1];
           strcpy(lineCopy, buffer);
           lines[lineCount++] = lineCopy;
   
           charCount += len;             // Exclude newline here
           wordCount += countWords(buffer);
       }
   
       inFile.clear();  // Clear EOF
       inFile.seekg(0, ios::end);
       charCount += lineCount;  // Add line breaks back to total character count
   
       inFile.close();
   
       // Output statistics
       cout << "\nStatistics:\n";
       cout << "Lines     : " << lineCount << endl;
       cout << "Words     : " << wordCount << endl;
       cout << "Characters: " << charCount << endl;
   
       // Free allocated memory
       for (int i = 0; i < lineCount; ++i) {
           delete[] lines[i];
       }
       delete[] lines;
   
       cout << endl << "Manush Desai 24CE025" << endl;
   }