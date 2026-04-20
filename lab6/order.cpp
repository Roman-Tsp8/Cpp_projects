#include "order.h"
#include <memory>
#include <iostream>

Order::Order()
    : customer(nullptr), name("Unnamed Order"), id(0) {}

Order::Order(std::shared_ptr<Customer> c, std::string n, int i)
    : customer(c), name(n), id(i) {}

void Order::addProduct(std::shared_ptr<Product> p) {
    products.push_back(p);
}

void Order::display() const {
    if (customer)
        customer->display();

    std::cout << "Products:\n";

    for (const auto& p : products) {
        p->display();
    }

    std::cout << "Order: " << name << " ID: " << id << std::endl;
}
