/* THIS PROGRAM IS PREPARED BY Manush Desai 24CE025
   Date of Modification- 1 May 2025
   7.1 FILE- WORD FREQUENCIES*/
   #include <iostream>
   #include <cctype>
   #include <cstring>
   using namespace std;
   
   const int INITIAL_CAPACITY = 10;
   const int WORD_MAX_LENGTH = 100;
   
   // Convert a string to lowercase
   void toLowercase(char* str) {
       for (int i = 0; str[i]; ++i)
           str[i] = tolower(str[i]);
   }
   
   // Check if a character is a delimiter
   bool isDelimiter(char ch) {
       return !isalpha(ch);  // Consider only alphabetic characters as part of words
   }
   
   // Function to tokenize and count word frequencies
   void analyzeText(const char* paragraph) {
       // Dynamic arrays for storing words and their frequencies
       char** words = new char*[INITIAL_CAPACITY];
       int* freq = new int[INITIAL_CAPACITY];
       int capacity = INITIAL_CAPACITY;
       int count = 0;
   
       char word[WORD_MAX_LENGTH];
       int idx = 0;
   
       for (int i = 0; ; ++i) {
           char ch = paragraph[i];
   
           if (ch == '\0' || isDelimiter(ch)) {
               if (idx > 0) {
                   word[idx] = '\0';
                   toLowercase(word);
   
                   // Search for the word in the existing array
                   bool found = false;
                   for (int j = 0; j < count; ++j) {
                       if (strcmp(words[j], word) == 0) {
                           freq[j]++;
                           found = true;
                           break;
                       }
                   }
   
                   // If not found, add new word
                   if (!found) {
                       if (count == capacity) {
                           // Expand capacity
                           int newCapacity = capacity * 2;
                           char** newWords = new char*[newCapacity];
                           int* newFreq = new int[newCapacity];
   
                           for (int k = 0; k < count; ++k) {
                               newWords[k] = words[k];
                               newFreq[k] = freq[k];
                           }
   
                           delete[] words;
                           delete[] freq;
   
                           words = newWords;
                           freq = newFreq;
                           capacity = newCapacity;
                       }
   
                       words[count] = new char[strlen(word) + 1];
                       strcpy(words[count], word);
                       freq[count] = 1;
                       count++;
                   }
   
                   idx = 0; // Reset for next word
               }
           } else {
               if (idx < WORD_MAX_LENGTH - 1) {
                   word[idx++] = ch;
               }
           }
   
           if (ch == '\0') break;
       }
   
       // Display word frequencies
       cout << "\nWord Frequencies:\n";
       for (int i = 0; i < count; ++i) {
           cout << words[i] << ": " << freq[i] << endl;
       }
   
       // Free memory
       for (int i = 0; i < count; ++i) {
           delete[] words[i];
       }
       delete[] words;
       delete[] freq;
   }
   
   int main() {
       const int MAX_PARAGRAPH_LENGTH = 1000;
       char paragraph[MAX_PARAGRAPH_LENGTH];
   
       cout << "Enter a paragraph:\n";
       cin.getline(paragraph, MAX_PARAGRAPH_LENGTH);
   
       analyzeText(paragraph);
   
       cout << endl << "Manush Desai 24CE025" << endl;
   }