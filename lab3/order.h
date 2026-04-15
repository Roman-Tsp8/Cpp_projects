#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include "string"
#include "customer.h"
#include "product.h"
#include <vector>
#include <memory>
using namespace std;


class Order {
    private: 
        string name;
        int id;
        shared_ptr<Customer> customer;
        vector<shared_ptr<Product>> products;

    public: 
    Order() ;
    Order(shared_ptr<Customer> c, string n, int i);
    void addProduct(shared_ptr<Product> p);
    void display() const;
    ~Order();
};

#endif