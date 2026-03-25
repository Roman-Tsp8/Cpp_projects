#include "order.h"

Order::Order() : Order("Unknown", 0) {}

Order::Order(string n, int i) : name(n), id(i) {
    cout << "Order constructor is called " << endl;
} 

Order::~Order() {
    cout << "Order destructor is called " << endl;
}

void Order::display() const {
    cout << "Order Name: " << name << endl;
    cout << "Order ID: " << id << endl;
}