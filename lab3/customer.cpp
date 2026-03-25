#include "customer.h"

Customer::Customer() : Customer("Unknown", "No Email") {}

Customer::Customer(string n, string e) : name(n), email(e) {
    cout << "Customer constructor is called " << endl;
}

Customer::~Customer() {
    cout << "Customer destructor is called " << endl;
}

void Customer::display() const {
    cout << "Customer Name: " << name << endl;
    cout << "Email of a customer: " << email << endl;
}