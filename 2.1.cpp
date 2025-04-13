/*A local construction company frequently deals with rectangular plots and structures of varying
dimensions. To streamline their planning and estimation processes, the company requires a simple
system to manage and analyze rectangular shapes efficiently.
The system must be able to handle multiple rectangles, each with distinct dimensions. For each
rectangle, the length and width need to be defined and stored securely. Additionally, the company
needs the ability to calculate two key metrics for any given rectangle:
The area, to estimate usable space or material coverage. The perimeter, to estimate boundary lengths
or material requirements for edges. To make this system functional, there should be a way to define
or update the dimensions of any rectangle as required. The system should be capable of creating and
managing multiple rectangle records, performing calculations for each, and displaying the results
clearly for analysis and planning purposes#include <iostream>*/
#include <vector>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) //default constructor
    {
        length = l;
        width = w;
    }

    void Dimensions(double l, double w) {
        length = l;
        width = w;
    }

    double getLength() {
        return length;
    }

    double getWidth() {
        return width;
    }

    double getArea() {
        return length * width;
    }

    double getPerimeter() {
        return 2 * (length + width);
    }
};

int main() {
    vector<Rectangle> rectangles;
    int choice;

    do {
        cout << "\nRectangle Management System\n";
        cout << "1. Add a new rectangle\n";
        cout << "2. Update a rectangle\n";
        cout << "3. View all rectangles\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            double l, w;
            cout << "Enter length: ";
            cin >> l;
            cout << "Enter width: ";
            cin >> w;
            rectangles.push_back(Rectangle(l, w));//adds new element in vector by calling constructor
            cout << "Rectangle added successfully.\n";
        }
        else if (choice == 2) {
            int index;
            cout << "Enter rectangle index to update (starting from 0): ";
            cin >> index;
            if (index >= 0 && index < rectangles.size()) {
                double l, w;
                cout << "Enter new length: ";
                cin >> l;
                cout << "Enter new width: ";
                cin >> w;
                rectangles[index].setDimensions(l, w);
                cout << "Rectangle updated.\n";
            } else {
                cout << "Invalid index.\n";
            }
        }
        else if (choice == 3) {
            for (int i = 0; i < rectangles.size(); i++) {
                cout << "\nRectangle " << i << ":\n";
                cout << "Length: " << rectangles[i].getLength() << endl;
                cout << "Width: " << rectangles[i].getWidth() << endl;
                cout << "Area: " << rectangles[i].getArea() << endl;
                cout << "Perimeter: " << rectangles[i].getPerimeter() << endl;
            }
            if (rectangles.empty()) {
                cout << "No rectangles to display.\n";
            }
        }
        else if (choice == 4) {
            cout << "Exiting the system.\n";
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
