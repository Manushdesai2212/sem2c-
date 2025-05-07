/* THIS PROGRAM IS PREPARED BY 24CE025 Manush desai
   Date of Modification- 20 April 2025
   5.3 OVERLOADING-POINT ON AXIS */
   #include <iostream>
   using namespace std;
   
   class Point {
   private:
       int x, y;
   
   public:
       Point() : x(0), y(0) {}
       Point(int xVal, int yVal) : x(xVal), y(yVal) {}
   
       // Overload + operator
       Point operator+(const Point& other) const {
           return Point(x + other.x, y + other.y);
       }
   
       // Overload unary - operator
       Point operator-() const {
           return Point(-x, -y);
       }
   
       // Overload == operator
       bool operator==(const Point& other) const {
           return x == other.x && y == other.y;
       }
   
       // Friend function for input
       friend istream& operator>>(istream& in, Point& p) {
           cout << "Enter x: ";
           in >> p.x;
           cout << "Enter y: ";
           in >> p.y;
           return in;
       }
   
       // Friend function for output
       friend ostream& operator<<(ostream& out, const Point& p) {
           out << "(" << p.x << ", " << p.y << ")";
           return out;
       }
   };
   
   class PointStack {
   private:
       static const int MAX = 100;
       Point stack[MAX];
       int top;
   
   public:
       PointStack() : top(-1) {}
   
       bool isEmpty() const {
           return top == -1;
       }
   
       bool isFull() const {
           return top == MAX - 1;
       }
   
       void push(const Point& p) {
           if (!isFull()) {
               stack[++top] = p;
           } else {
               cout << "Stack overflow! Cannot push.\n";
           }
       }
   
       Point pop() {
           if (!isEmpty()) {
               return stack[top--];
           } else {
               cout << "Stack underflow! Cannot pop.\n";
               return Point();
           }
       }
   
       void display() const {
           if (isEmpty()) {
               cout << "Stack is empty.\n";
               return;
           }
   
           cout << "Stack contents (top to bottom):\n";
           for (int i = top; i >= 0; --i) {
               cout << stack[i] << endl;
           }
       }
   };
   
   int main() {
       PointStack history;
       int choice;
       Point p1, p2, result;
   
       do {
           cout << "--- Point Operation Menu ---\n";
           cout << "1. Input and push a point\n";
           cout << "2. Add two points\n";
           cout << "3. Negate a point\n";
           cout << "4. Compare two points\n";
           cout << "5. Undo last operation\n";
           cout << "6. Display point history (stack)\n";
           cout << "7. Exit\n";
           cout << "Enter your choice: ";
           cin >> choice;
   
           switch (choice) {
           case 1:
               cout << "Input point:\n";
               cin >> p1;
               history.push(p1);
               break;
   
           case 2:
               cout << "Input first point:\n";
               cin >> p1;
               cout << "Input second point:\n";
               cin >> p2;
               result = p1 + p2;
               cout << "Result: " << result << endl;
               history.push(result);
               break;
   
           case 3:
               cout << "Input point to negate:\n";
               cin >> p1;
               result = -p1;
               cout << "Negated point: " << result << endl;
               history.push(result);
               break;
   
           case 4:
               cout << "Input first point:\n";
               cin >> p1;
               cout << "Input second point:\n";
               cin >> p2;
               if (p1 == p2)
                   cout << "Points are equal.\n";
               else
                   cout << "Points are not equal.\n";
               break;
   
           case 5:
               cout << "Undoing last operation...\n";
               history.pop();
               break;
   
           case 6:
               history.display();
               break;
   
           case 7:
               cout << "Exiting...\n";
               break;
   
           default:
               cout << "Invalid choice. Try again.\n";
           }
   
       } while (choice != 7);
   
       cout << endl << "Manush 24CE025" << endl;
   }