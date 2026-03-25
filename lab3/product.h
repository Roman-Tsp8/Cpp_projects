#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include "string"
using namespace std;


class Product {
    private: 
        string name;
        double price;
        int quantity;

        static int ProductCount;
    public:
        Product();
        Product(string n, double p, int q = 1);
        Product(const Product& other);
        Product(Product&& other) noexcept;
        ~Product();

        void display() const;
        void setPrice(double p);
        
        static int getProductCount();

        Product operator-() const;
        Product operator+(const Product& other) const;

        friend ostream& operator<<(ostream& out, const Product& p);
        friend istream& operator>>(istream& in, Product& p); 
};

#endif