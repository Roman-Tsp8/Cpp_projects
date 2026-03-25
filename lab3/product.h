#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include "string"
using namespace std;


class Product {
    protected: 
        string name;
        double price;
        int quantity;

        static int ProductCount;
    public:
        Product();
        Product(string n = "Unknown", double p = 0, int q = 1);
        Product(const Product& other);
        Product(Product&& other) noexcept;
        Product& operator=(const Product& other) = default;
        virtual void display() const;
        static int  getProductCount();

        virtual ~Product();

        void display() const;
        void setPrice(double p);
        
        static int getProductCount();

        Product operator-() const;
        Product operator+(const Product& other) const;

        friend ostream& operator<<(ostream& out, const Product& p);
        friend istream& operator>>(istream& in, Product& p); 
};

class ElectronicsProduct : public Product {
    protected:
        int warrranty; 
    public:
        ElectronicsProduct(string n, double p, int q, int w);
        void display() const override;
};



#endif