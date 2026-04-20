#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>
#include <memory>
#include "customer.h"
#include "product.h"

class Order {
    std::string name;
    int id;
    std::shared_ptr<Customer> customer;
    std::vector<std::shared_ptr<Product>> products;

    public:
        Order();
        Order(std::shared_ptr<Customer> c, std::string n, int i);

        void addProduct(std::shared_ptr<Product> p);
        void display() const;
    };

#endif
