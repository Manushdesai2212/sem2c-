/* THIS PROGRAM IS PREPARED BY Manuhs desai
   Date of Modification- 20 April 2025
   5.4 OVERLOADING-TEMPRETURE CONVERSION */
   #include <iostream>
   using namespace std;
   
   class Fahrenheit; // Forward declaration
   
   class Celsius {
   public:
           float temp;
   
       Celsius(float t = 0) : temp(t) {}
   
       // Getter for temp value
       float getTemp() const { return temp; }
   
       // Type conversion: Celsius to Fahrenheit
       operator Fahrenheit(); // Forward declaration of conversion
   
       // Equality operator
       bool operator==(const Fahrenheit& f) const;
   };
   
   class Fahrenheit {
   private:
       float temp;
   public:
       Fahrenheit(float t = 32) : temp(t) {}
   
       // Getter for temp value
       float getTemp() const { return temp; }
   
       // Type conversion: Fahrenheit to Celsius
       operator Celsius() {
           return Celsius((temp - 32) * 5.0 / 9.0);
       }
   
       // Equality operator
       bool operator==(const Celsius& c) const {
           return (int)((temp - 32) * 5.0 / 9.0 + 0.5) == (int)(c.getTemp() + 0.5);
       }
   
       friend ostream& operator<<(ostream& out, const Fahrenheit& f) {
           out << f.temp << " F";
           return out;
       }
   
       friend istream& operator>>(istream& in, Fahrenheit& f) {
           cout << "Enter temperature in Fahrenheit: ";
           in >> f.temp;
           return in;
       }
   };
   
   // Implement Celsius to Fahrenheit conversion using getTemp() for access
   Celsius::operator Fahrenheit() {
       return Fahrenheit((temp * 9.0 / 5.0) + 32);  // Using `temp` directly in the Celsius class
   }
   
   // Equality implementation
   bool Celsius::operator==(const Fahrenheit& f) const {
       return (int)(temp + 0.5) == (int)(((f.getTemp() - 32) * 5.0 / 9.0) + 0.5);
   }
   
   ostream& operator<<(ostream& out, const Celsius& c) {
       out << c.getTemp() << " C";
       return out;
   }
   
   istream& operator>>(istream& in, Celsius& c) {
       cout << "Enter temperature in Celsius: ";
       in >> c.temp;
       return in;
   }
   
   // Simple dynamically allocated queue for storing converted Fahrenheit objects
   class TempQueue {
   private:
       Fahrenheit* data;
       int front, rear, capacity;
   
   public:
       TempQueue(int size = 10) : front(0), rear(0), capacity(size) {
           data = new Fahrenheit[capacity]; // Dynamic allocation
       }
   
       ~TempQueue() {
           delete[] data; // Properly release memory
       }
   
       bool isEmpty() const {
           return front == rear;
       }
   
       bool isFull() const {
           return (rear + 1) % capacity == front;
       }
   
       void enqueue(const Fahrenheit& f) {
           if (!isFull()) {
               data[rear] = f;
               rear = (rear + 1) % capacity;
           } else {
               cout << "Queue is full. Cannot enqueue.\n";
           }
       }
   
       Fahrenheit dequeue() {
           if (!isEmpty()) {
               Fahrenheit temp = data[front];
               front = (front + 1) % capacity;
               return temp;
           } else {
               cout << "Queue is empty. Cannot dequeue.\n";
               return Fahrenheit();
           }
       }
   
       void display() const {
           if (isEmpty()) {
               cout << "Queue is empty.\n";
               return;
           }
           cout << "Temperatures in queue (FIFO order):\n";
           int i = front;
           while (i != rear) {
               cout << data[i] << endl;
               i = (i + 1) % capacity;
           }
       }
   };
   
   int main() {
       TempQueue* q = new TempQueue(10); // Dynamically allocate the queue
       int choice;
   
       do {
           cout << "--- Temperature Conversion Menu ---\n";
           cout << "1. Convert Celsius to Fahrenheit\n";
           cout << "2. Convert Fahrenheit to Celsius\n";
           cout << "3. Compare Celsius and Fahrenheit temperatures\n";
           cout << "4. Display next Fahrenheit value\n";
           cout << "5. Display all Fahrenheit temperatures in queue\n";
           cout << "6. Exit\n";
           cout << "Enter your choice: ";
           cin >> choice;
   
           Celsius* c = nullptr; // Dynamically allocate Celsius object
           Fahrenheit* f = nullptr; // Dynamically allocate Fahrenheit object
   
           switch (choice) {
           case 1:
               c = new Celsius(); // Allocate memory dynamically
               cin >> *c;
               f = new Fahrenheit(*c); // Convert to Fahrenheit
               q->enqueue(*f);
               cout << "Enqueued Fahrenheit value: " << *f << endl;
               delete c; // Release memory after use
               delete f; // Release memory after use
               break;
   
           case 2:
               f = new Fahrenheit(); // Allocate memory dynamically
               cin >> *f;
               c = new Celsius(*f); // Convert to Celsius
               cout << "Converted Celsius value: " << *c << endl;
               delete c; // Release memory after use
               delete f; // Release memory after use
               break;
   
           case 3:
               c = new Celsius(); // Allocate memory dynamically
               f = new Fahrenheit(); // Allocate memory dynamically
               cin >> *c;
               cin >> *f;
               if (*c == *f)
                   cout << "Temperatures are equal.\n";
               else
                   cout << "Temperatures are NOT equal.\n";
               delete c; // Release memory after use
               delete f; // Release memory after use
               break;
   
           case 4:
               if (!q->isEmpty()) {
                   f = new Fahrenheit(q->dequeue()); // Dequeue and allocate a new object
                   cout << "Dequeued Fahrenheit value: " << *f << endl;
                   delete f; // Release memory after use
               } else {
                   cout << "Queue is empty.\n";
               }
               break;
   
           case 5:
               q->display();
               break;
   
           case 6:
               cout << "Exiting...\n";
               break;
   
           default:
               cout << "Invalid choice.\n";
           }
   
       } while (choice != 6);
   
       delete q; // Clean up the dynamically allocated queue
       cout << endl << "Manush Desai 24ce025" << endl;
   }
   