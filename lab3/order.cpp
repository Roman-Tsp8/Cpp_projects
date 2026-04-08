#include "order.h"

Order::Order(Customer* c, string n, int i) : customer(c), name(n), id(i) {
    cout << "Order constructor is called " << endl;
} 


void Order::addProduct(Product* p) {
    products.push_back(p);
}

void Order::display() const {
    customer->display();
    cout << "Products:\n";
    for (auto p : products) {
        p->display();
        cout << "-------------" << endl;
    }

    cout << "Order Name: " << name << endl;
    cout << "Order ID: " << id << endl;
}

Order::~Order() {
    cout << "Order destructor is called " << endl;
}