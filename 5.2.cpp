/* THIS PROGRAM IS PREPARED BY 24CE025 Manush Desai
   Date of Modification- 20 April 2025
   5.2 OVERLOADING-COMPLEX NUMBER OPERATIONS  */
   #include <iostream>
   using namespace std;
   
   class Complex {
   private:
       double real;
       double imag;
   
   public:
       Complex() : real(0), imag(0) {}
       Complex(double r, double i) : real(r), imag(i) {}
   
       // Operator Overloading for +
       Complex operator+(const Complex& other) const {
           return Complex(real + other.real, imag + other.imag);
       }
   
       // Operator Overloading for -
       Complex operator-(const Complex& other) const {
           return Complex(real - other.real, imag - other.imag);
       }
   
       // Input operator >>
       friend istream& operator>>(istream& in, Complex& c) {
           cout << "Enter real part: ";
           in >> c.real;
           cout << "Enter imaginary part: ";
           in >> c.imag;
           return in;
       }
   
       // Output operator <<
       friend ostream& operator<<(ostream& out, const Complex& c) {
           out << c.real;
           if (c.imag >= 0)
               out << " + " << c.imag << "i";
           else
               out << " - " << -c.imag << "i";
           return out;
       }
   };
   
   int main() {
       const int MAX = 10;
       Complex numbers[MAX];
       int count;
   
       cout << "How many complex numbers do you want to enter (max " << MAX << ")? ";
       cin >> count;
   
       if (count < 1 || count > MAX) {
           cout << "Invalid number of inputs. Exiting.\n";
           return 1;
       }
   
       for (int i = 0; i < count; ++i) {
           cout << "\nComplex number " << (i + 1) << ":\n";
           cin >> numbers[i];
       }
   
       cout << "\n--- Entered Complex Numbers ---\n";
       for (int i = 0; i < count; ++i) {
           cout << "Number " << (i + 1) << ": " << numbers[i] << endl;
       }
   
       // Batch operations
       Complex sum, diff = numbers[0];
       for (int i = 0; i < count; ++i) {
           sum = sum + numbers[i];
           if (i > 0) {
               diff = diff - numbers[i];
           }
       }
   
       cout << "\nSum of all complex numbers: " << sum << endl;
       if (count > 1)
           cout << "Difference (first - rest): " << diff << endl;
   
       cout << endl << "Manush Desai 24CE025" << endl;
   }