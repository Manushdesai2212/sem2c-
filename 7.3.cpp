/* THIS PROGRAM IS PREPARED BY 24CE025 Manush desai
   Date of Modification- 1 May 2025
   7.3 FILE- INVENTORY USING CLASS */

   #include <iostream>
   #include <fstream>
   #include <cstring>
   using namespace std;
   
   class Product {
   public:
       char name[50];
       int quantity;
       float price;
   
       void input() {
           cout << "Enter product name: ";
           cin.ignore();
           cin.getline(name, 50);
   
           cout << "Enter quantity: ";
           cin >> quantity;
   
           cout << "Enter price: ";
           cin >> price;
       }
   
       void display() const {
           cout << "Name    : " << name << endl;
           cout << "Quantity: " << quantity << endl;
           cout << "Price   : $" << price << "\n\n";
       }
   };
   
   class Inventory {
   private:
       const char* filename;
   
   public:
       Inventory(const char* file) : filename(file) {}
   
       void addProduct() {
           Product p;
           p.input();
   
           ofstream file(filename, ios::app | ios::binary);
           if (!file) {
               cerr << "Error: Cannot open file for writing.\n";
               return;
           }
   
           file.write(reinterpret_cast<char*>(&p), sizeof(Product));
           file.close();
           cout << "Product added successfully.\n";
       }
   
       void viewInventory() const {
           ifstream file(filename, ios::binary);
           if (!file) {
               cerr << "Error: Cannot open file.\n";
               return;
           }
   
           Product p;
           cout << "\n--- Inventory ---\n";
           while (file.read(reinterpret_cast<char*>(&p), sizeof(Product))) {
               p.display();
           }
   
           file.close();
       }
   
       void searchProduct() const {
           char searchName[50];
           cout << "Enter product name to search: ";
           cin.ignore();
           cin.getline(searchName, 50);
   
           ifstream file(filename, ios::binary);
           if (!file) {
               cerr << "Error: Cannot open file.\n";
               return;
           }
   
           Product p;
           bool found = false;
   
           while (file.read(reinterpret_cast<char*>(&p), sizeof(Product))) {
               if (strcmp(p.name, searchName) == 0) {
                   cout << "\nProduct Found:\n";
                   p.display();
                   found = true;
                   break;
               }
           }
   
           if (!found) {
               cout << "Product not found.\n";
           }
   
           file.close();
       }
   };
   
   int main() {
       Inventory inv("inventory.txt");
   
       int choice;
       do {
           cout << "\n=== Inventory Management ===\n";
           cout << "1. Add Product\n";
           cout << "2. View Inventory\n";
           cout << "3. Search Product\n";
           cout << "4. Exit\n";
           cout << "Enter your choice: ";
           cin >> choice;
   
           switch (choice) {
               case 1:
                   inv.addProduct();
                   break;
               case 2:
                   inv.viewInventory();
                   break;
               case 3:
                   inv.searchProduct();
                   break;
               case 4:
                   cout << "Exiting...\n";
                   break;
               default:
                   cout << "Invalid choice. Try again.\n";
           }
       } while (choice != 4);
   
       cout << "\nManush Desai 24CE025" << endl;
       return 0;
   }