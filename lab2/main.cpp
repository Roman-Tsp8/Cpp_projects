#include <iostream>
#include "string"

using namespace std;

class Product {
    private: 
        string name;
        double price;
        int quantity;
    public:
        Product() : Product("Unknown", 0.0, 0) {};

        Product(string n, double p, int q = 1) : name(n), price(p), quantity(q) {
            cout << "Product constructor is called " << endl;
        };

        ~Product() {
            cout << "Product destructor is called " << endl;
        }
        void display() {
            cout << "Product Name: " << name << endl;
            cout << "Price: " << price << endl;
            cout << "Quantity: " << quantity << endl; 
        }
};

class Customer {
    private: 
    string name;
    string email;

    public:
    Customer() : Customer("Unknown", "No Email") {};

    Customer(string n, string e) : name(n), email(e) {
        cout << "Customer constructor is called " << endl;
    }

    ~Customer() {
        cout << "Customer destructor is called " << endl;
    }

    void display() {
        cout << "Customer Name: " << name << endl;
        cout << "Email of a customer: " << email << endl;
    }
};


class Order {
    private: 
    string name;
    int id;
    public: 

    Order() : Order("Unknown", 0) {};
    Order(string n, int i) : name(n), id(i) {
        cout << "Order constructor is called " << endl;
    }

    ~Order() {
        cout << "Order destructor is called " << endl;
    }

    void display() {
        cout << "Order Name: " << name << endl;
        cout << "Order ID: " << id << endl;
    }
};

int main() {
    Product s1("Laptop", 799.99, 10);
    s1.display();
    Customer c1("Johny K", "johnyk@gmail.com");
    c1.display();
    Order o1("Laptop", 432);
    o1.display();
    return 0;
}