#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include "string"

using namespace std;

class Customer {
    protected: 
    string name;
    string email;

    public:
    Customer();
    Customer(string n = "Unknown", string e = "No Email");
    virtual void display() const;
    virtual ~Customer();

};

class VIPCustomer : public Customer{
    double discount;

    public : 
    VIPCustomer(string n, string e, double d);
    void display() const override;
};

#endif