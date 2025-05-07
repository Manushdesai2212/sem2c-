/* THIS PROGRAM IS PREPARED BY 24CE025
   Date of Modification- 20 April 2025
   5.5 OVERLOADING-SHAPES*/

   #include <iostream>
   #include <cmath>
   using namespace std;
   
   // Base class Shape with a pure virtual function for Area
   class Shape {
   public:
       virtual double Area() const = 0;  // Pure virtual function
       virtual ~Shape() {} // Virtual destructor
   };
   
   
   class Rectangle : public Shape {
   private:
       double length;
       double width;
   public:
       Rectangle(double l, double w) : length(l), width(w) {}
   
       double Area() const override {
           return length * width;
       }
   };
   
   
   class Circle : public Shape {
   private:
       double radius;
   public:
       Circle(double r) : radius(r) {}
   
       double Area() const override {
           return M_PI * radius * radius;  // Area of circle = π * r^2
       }
   };
   
   // Class for dynamically managing a collection of shapes
   class ShapeCollection {
   private:
       Shape** shapes;
       int size;
       int capacity;
   
       void resize() {
           capacity *= 2;
           Shape** newShapes = new Shape*[capacity];
           for (int i = 0; i < size; ++i) {
               newShapes[i] = shapes[i];
           }
           delete[] shapes;
           shapes = newShapes;
       }
   
   public:
       ShapeCollection(int initialCapacity = 10) : size(0), capacity(initialCapacity) {
           shapes = new Shape*[capacity];
       }
   
       ~ShapeCollection() {
           for (int i = 0; i < size; ++i) {
               delete shapes[i];
           }
           delete[] shapes;
       }
   
       void addShape(Shape* shape) {
           if (size == capacity) {
               resize();
           }
           shapes[size++] = shape;
       }
   
       void displayAreas() const {
           for (int i = 0; i < size; ++i) {
               cout << "Area of shape " << i + 1 << ": " << shapes[i]->Area() << endl;
           }
       }
   };
   
   int main() {
       ShapeCollection collection;
       int choice;
   
       do {
           cout << "--- Shape Area Calculator ---\n";
           cout << "1. Add a Rectangle\n";
           cout << "2. Add a Circle\n";
           cout << "3. Display all areas\n";
           cout << "4. Exit\n";
           cout << "Enter your choice: ";
           cin >> choice;
   
           switch (choice) {
           case 1: {
               double length, width;
               cout << "Enter the length of the rectangle: ";
               cin >> length;
               cout << "Enter the width of the rectangle: ";
               cin >> width;
               collection.addShape(new Rectangle(length, width));
               break;
           }
           case 2: {
               double radius;
               cout << "Enter the radius of the circle: ";
               cin >> radius;
               collection.addShape(new Circle(radius));
               break;
           }
           case 3:
               collection.displayAreas();
               break;
           case 4:
               cout << "Exiting...\n";
               break;
           default:
               cout << "Invalid choice. Please try again.\n";
           }
   
       } while (choice != 4);
   
       cout << endl << "Manush 24ce025" << endl;
   }