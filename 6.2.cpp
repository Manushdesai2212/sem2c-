/* THIS PROGRAM IS PREPARED BY 24CE025 Manush desai
   Date of Modification- 1 May 2025
   6.2 POINT COORDINATES*/

   #include <iostream>
   using namespace std;
   
   class Point {
   private:
       double x, y;
   
   public:
       // Constructor
       Point(double x = 0, double y = 0) : x(x), y(y) {}
   
       // Shift method with method chaining
       Point* shift(double dx, double dy) {
           x += dx;
           y += dy;
           return this; // Enables chaining
       }
   
       // Display current coordinates
       void print() const {
           cout << "Current Position: (" << x << ", " << y << ")" << endl;
       }
   };
   
   int main() {
       double x, y;
       cout << "Enter initial coordinates (x y): ";
       cin >> x >> y;
   
       // Dynamically create a Point object
       Point* p = new Point(x, y);
   
       int n;
       cout << "Enter number of shifts: ";
       cin >> n;
   
       for (int i = 0; i < n; ++i) {
           double dx, dy;
           cout << "Enter shift " << (i + 1) << " (dx dy): ";
           cin >> dx >> dy;
           p->shift(dx, dy); // Method chaining happens here if done inline
       }
   
       // Display final coordinates
       p->print();
   
       // Clean up
       delete p;
       cout << endl << "Manush desai 24CE025" << endl;
   }
   