#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include "string"
#include "customer.h"
#include "product.h"
#include <vector>
using namespace std;

class Order {

    Customer* customer;
    vector<Product*> products;
    private: 
    string name;
    int id;
    public: 


    Order() ;
    Order(Customer* c, string n, int i);
    
    void addProduct(Product* p);
    void display() const;
    ~Order();
};

#endif