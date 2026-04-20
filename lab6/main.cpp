#include <iostream>
#include "string"
#include "product.h"
#include "customer.h"
#include "order.h"
#include <vector>
#include <memory>
#include "storage.h"

using namespace std;
vector<shared_ptr<Product>> products;

void adminMenu() {
    int choice;
    do {
        cout << "\n --- Admin Menu ---\n";
        cout << "1. Add product\n";
        cout << "2. Save products\n";
        cout << "0. Exit\n";
        cin >> choice;

        if (choice == 1) {
            string name;
            double price;
            int quantity;

            cout << "Name: "; cin >>name;
            cout << "Price: "; cin >> price;
            cout << "Quantity: "; cin >> quantity;

            auto p = make_shared<Product>(name, price, quantity);
            products.push_back(p);

            logAction("Added product: " + name);
        }
        if (choice == 2) {
            SaveProducts(products);
            logAction("Admin saved products to file.");
        }
    } while (choice != 0);
}

void userMenu() {
    int choice;
    do {
        cout << "\n --- User Menu ---\n";
        cout << "1. Show products\n";
        cout << "2. Buy product\n";
        cout << "0. Exit\n";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input"<< endl;
            continue;
        }

        if (choice == 1) {
            for (int i = 0; i<products.size(); ++i) {
                cout << i << ": ";
                products[i]->display();
            }
            logAction("User viewed products.");
        }

        if (choice == 2) {
            int index;
            cout << "Enter product index to buy: ";
            cin >> index;
            if (index >= 0 && index < products.size()) {
                products[index]->sell();
                logAction("User bought product");
            } else {
                cout << "Invalid index." << endl;
            }
        }
    } while (choice != 0);
}

int main() {
    // static binding

    loadProducts(products);

    if (products.empty()) {
        products.push_back(make_shared<Product>("Laptop", 1000, 5));
        products.push_back(make_shared<Product>("Phone", 500, 10));
    };

    int role;
    cout << "1. Admin\n2. User\nChoose role: ";
    if(!(cin >> role)) {
        cout << "Invalid input" << endl;

    };

    if (role == 1) {
        string pass;
        cout << "Enter admin password: ";
        cin >> pass;

        if (pass == "admin123") {
            adminMenu();
        } else {
            cout  << "Incorrect password. Exiting." << endl;
        }
    } else {
        userMenu();
    }
    //Product s1("Laptop", 799.99, 10);
  //  s1.display();
//Product s2 = s1;
 //   s1.nonVirtualDisplay();
  //  s2.setPrice(899.99);
  //  Product s4("Smartphone", 499.99, 5);
   // s4.display();

//Product s5 = s2 + s1;
  //  s5.display();
    //cout << s5 << endl;

   // Smartphone p1("IPhone 13", 999.99, 3, 24, "Apple");
    //Smartphone p2("Samsung Galaxy S21", 899.99, 4, 24, "Samsung");
  //  p1.nonVirtualDisplay();

    // dynamic polymorphism via pointers

    //Product* bp = &s1;
  //  bp->display();

    // dynamic polymorphism via references
//    Product& br = s1;
  //  br.display();

    // usage of final class
  //  Sellable* sell1 = &p1;
//    sell1->sell();
    //cout<< "Price: " << sell1->getPrice() << endl;

// basic VIP customer pointer class

    //VIPCustomer cv1("Johny K","cooljohny@gmail.com", 20);

  //  Customer c1("Johny K", "johnyk@gmail.com");
//    c1.display();

  //  cout << "Total number of products created: " << Product::getProductCount() << endl;
//    return 0;
}
