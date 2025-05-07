/* THIS PROGRAM IS PREPARED BY 24CE025 Manush desai 
   Date of Modification- 1 May 2025
   6.4 VIRTUAL BASE CLASS*/
   #include <iostream>
   using namespace std;
   
   class Base {
   public:
       Base() {
           cout << "Base constructor called." << endl;
       }
   
       // Virtual destructor ensures derived class destructor is called
       virtual ~Base() {
           cout << "Base destructor called." << endl;
       }
   };
   
   class Derived : public Base {
   private:
       int* data;
   
   public:
       Derived(int size) {
           cout << "Derived constructor called." << endl;
           data = new int[size]; // Dynamic allocation
           for (int i = 0; i < size; ++i) {
               data[i] = i;
           }
       }
   
       ~Derived() {
           cout << "Derived destructor called." << endl;
           delete[] data; // Proper cleanup
       }
   };
   
   int main() {
       int size;
       cout << "Enter size for dynamic array in Derived object: ";
       cin >> size;
   
       // Create Derived object but assign to Base class pointer
       Base* obj = new Derived(size);
   
       // Proper cleanup through virtual destructor
       delete obj;
   
       cout << endl << "Manush Desai 24CE025" << endl;
   }