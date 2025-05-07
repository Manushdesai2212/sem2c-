/* THIS PROGRAM IS PREPARED BY 24CE025 Manush desai
   Date of Modification- 1 May 2025
   6.1 ELEMENET OPERATAION*/

   #include <iostream>
   using namespace std;
   
   class DynamicArray {
   private:
       int* data;
       int size;
       int capacity;
   
       void resize() {
           capacity *= 2;  // Double the capacity
           int* newData = new int[capacity];  // Allocate new memory block
   
           // Copy old elements to the new array
           for (int i = 0; i < size; ++i) {
               newData[i] = data[i];
           }
   
           delete[] data;  // Free old memory block
           data = newData;  // Update data to point to new memory block
       }
   
   public:
       DynamicArray(int initialCapacity = 4) {
           size = 0;
           capacity = initialCapacity;
           data = new int[capacity];  // Initial memory allocation
       }
   
       ~DynamicArray() {
           delete[] data;  // Deallocate memory when object is destroyed
       }
   
       // Insert element at the end of the array
       void insert(int value) {
           if (size == capacity) {
               resize();  // Resize if the array is full
           }
           data[size++] = value;  // Add element and increase size
       }
   
       // Remove element at a specific index
       void remove(int index) {
           if (index < 0 || index >= size) {
               cout << "Index out of range.\n";
               return;
           }
   
           // Shift elements to the left to fill the gap
           for (int i = index; i < size - 1; ++i) {
               data[i] = data[i + 1];
           }
           size--;  // Decrease size
       }
   
       // Display the current elements in the array
       void display() const {
           if (size == 0) {
               cout << "Array is empty.\n";
               return;
           }
   
           cout << "Elements: ";
           for (int i = 0; i < size; ++i) {
               cout << data[i] << " ";
           }
           cout << endl;
       }
   
       // Get the size of the array
       int getSize() const {
           return size;
       }
   
       // Get the capacity of the array
       int getCapacity() const {
           return capacity;
       }
   };
   
   int main() {
       DynamicArray arr;
   
       int choice;
       do {
           cout << "1. Insert Element\n";
           cout << "2. Remove Element\n";
           cout << "3. Display Array\n";
           cout << "4. Exit\n";
           cout << "Enter your choice: ";
           cin >> choice;
   
           switch (choice) {
           case 1: {
               int value;
               cout << "Enter value to insert: ";
               cin >> value;
               arr.insert(value);
               break;
           }
           case 2: {
               int index;
               cout << "Enter index to remove: ";
               cin >> index;
               arr.remove(index);
               break;
           }
           case 3:
               arr.display();
               break;
           case 4:
               cout << "Exiting program.......\n";
               break;
           default:
               cout << "Invalid choice. Please try again.\n";
           }
       } while (choice != 4);
   
       cout << endl << "Manush desai 24CE025" << endl;
   }
   