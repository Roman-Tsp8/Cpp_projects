#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include "string"

using namespace std;

class Customer {
    private: 
    string name;
    string email;

    public:
    Customer();

    Customer(string n, string e);

    ~Customer();

    void display() const;
};

#endif