#include "order.h"
#include <iostream>
#include <memory>
using namespace std;


Order::Order() : customer(nullptr), name("Unnamed Order"), id(0) {}

void Order::addProduct(shared_ptr<Product> p) {
    products.push_back(p);
}

void Order::addProduct(shared_ptr<Product> p) {
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