/* THIS PROGRAM IS PREPARED BY Manush
   Date of Modification- 1 May 2025
   8.1 TEMPLATES- REVERSING*/
   #include <iostream>
   #include <vector>
   #include <algorithm>  // for std::reverse
   #include <iterator>   // for iterators
   using namespace std;
   
   class SequenceReversal {
   private:
       vector<int> numbers; // A dynamically managed sequence (vector)
   
   public:
       // Method to input the sequence of numbers
       void inputSequence() {
           int size;
           cout << "Enter the number of elements: ";
           cin >> size;
           numbers.resize(size);
   
           cout << "Enter the elements: ";
           for (int i = 0; i < size; ++i) {
               cin >> numbers[i];
           }
       }
   
       // Method to display the sequence
       void displaySequence() const {
           cout << "Sequence: ";
           for (const int& num : numbers) {
               cout << num << " ";
           }
           cout << endl;
       }
   
       // Approach 1: Using std::reverse to reverse the sequence
       void reverseUsingStd() {
           std::reverse(numbers.begin(), numbers.end()); // Built-in reverse function
       }
   
       // Approach 2: Manually reversing using iterators
       void reverseManually() {
           auto start = numbers.begin();
           auto end = numbers.end() - 1; // end() returns one past the last element
   
           // Swap elements using iterators
           while (start < end) {
               swap(*start, *end);
               ++start;
               --end;
           }
       }
   };
   
   int main() {
       SequenceReversal sr;
   
       sr.inputSequence();
       sr.displaySequence();
   
       // Reversing using std::reverse()
       sr.reverseUsingStd();
       cout << "Reversed sequence using std::reverse(): ";
       sr.displaySequence();
   
       // Reversing manually using iterators
       sr.reverseManually();
       cout << "Reversed sequence manually using iterators: ";
       sr.displaySequence();
   
       cout << endl << "Manush Desai 24CE025" << endl;
   }