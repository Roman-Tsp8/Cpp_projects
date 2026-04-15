#include "order.h"
#include <iostream>
#include <memory>
using namespace std;


Order::Order() : customer(nullptr), name("Unnamed Order"), id(0) {}

Order::Order(shared_ptr<Customer> c, string n, int i)
    : customer(c), name(n), id(i) {}

void Order::addProduct(shared_ptr<Product> p) {
    products.push_back(p);
}

void Order::display() const {
    if (customer) 
        customer->display();

    cout << "Products:\n";
    for(auto& p : products) {
        p->display();
    }
}

Order::~Order() {
    cout << "Order destructor is called " << endl;
}