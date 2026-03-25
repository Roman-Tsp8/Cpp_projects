#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include "string"
using namespace std;

class Order {
    private: 
    string name;
    int id;
    public: 

    Order() ;
    Order(string n, int i);
    ~Order() ;

    void display() const;
};

#endif