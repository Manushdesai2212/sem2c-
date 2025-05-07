/* THIS PROGRAM IS PREPARED BY Manush
   Date of Modification- 1 May 2025
   8.2 TEMPLATES- WORD FREQUENCIES*/
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>
#include <cctype>
using namespace std;

class WordFrequencyAnalyzer {
private:
    map<string, int> wordCount; // Map to store words and their frequencies

public:
    // Method to process the input text and count word frequencies
    void processText(const string& text) {
        stringstream ss(text);
        string word;

        while (ss >> word) {
            // Convert the word to lowercase and remove non-alphabetic characters
            cleanWord(word);
            if (!word.empty()) {
                wordCount[word]++; // Increment frequency count for this word
            }
        }
    }

    // Method to display the word frequencies
    void displayWordFrequencies() const {
        cout << "\nWord Frequency Distribution:\n";
        cout << "----------------------------\n";
        for (const auto& entry : wordCount) {
            cout << entry.first << ": " << entry.second << endl;
        }
    }

private:
    // Helper function to clean words (convert to lowercase and remove punctuation)
    void cleanWord(string& word) {
        // Convert to lowercase
        transform(word.begin(), word.end(), word.begin(), ::tolower);

        // Remove non-alphabetic characters
        word.erase(remove_if(word.begin(), word.end(), [](char c) {
            return !isalpha(c);
        }), word.end());
    }
};

int main() {
    WordFrequencyAnalyzer analyzer;
    string inputText;

    // Prompt user for text input
    cout << "Enter a sentence or paragraph: ";
    getline(cin, inputText);

    // Process the input text
    analyzer.processText(inputText);

    // Display the word frequency distribution
    analyzer.displayWordFrequencies();

    cout << endl << "Manush Desai 24CE025" << endl;
}