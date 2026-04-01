#include "customer.h"

Customer::Customer() : Customer("Unknown", "No Email") {}

Customer::Customer(string n, string e) : name(n), email(e) {
    cout << "Customer constructor is called " << endl;
}

Customer::~Customer() {
    cout << "Customer destructor is called " << endl;
}

void Customer::display() const {
    cout << "Customer Name: " << name << ", Email: " << email << endl;

}

//  VIPCustomer implementation

VIPCustomer::VIPCustomer(string n, string e, double d) : Customer(n, e), discount(d) {

}
void VIPCustomer::display() const {
    Customer::display();
    cout << "Discount: " << discount << "%" << endl;
}