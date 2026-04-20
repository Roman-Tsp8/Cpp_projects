#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
using namespace std;


class Sellable {
    public:
        virtual double getPrice() const = 0;
        virtual void sell() = 0;
        virtual ~Sellable() {}
};

class Product : public Sellable {
    protected:
        string name;
        double price;
        int quantity;
        static int ProductCount;

    public:
        Product(string n = "Unknown", double p = 0, int q = 1);
        Product(const Product& other);
        Product(Product&& other) noexcept;
        virtual ~Product();

        Product& operator=(const Product& other);

        virtual void display() const;
        void nonVirtualDisplay() const;


        void setPrice(double p);
        double getPrice() const override;

        Product operator+(const Product& other) const;

        friend ostream& operator<<(ostream& out, const Product& p);
        friend istream& operator>>(istream& in, Product& p);

        void sell() override; //{
            //if (quantity > 0)  {
           //     quantity--; cout << name << " sold." << endl;
           // } else {
            //    cout << name << " is out of stock." << endl;
           //}
        //}

        static int getProductCount(); //{
          //  return ProductCount;
        //}
};

class ElectronicsProduct : public Product {
    protected:
        int warranty;
    public:
        ElectronicsProduct(string n, double p, int q, int w);
        void display() const override;
};

class Smartphone final : public ElectronicsProduct {
    private:
        string brand;
    public:
    Smartphone(string n, double p, int q, int w, string b);
    //Smartphone(const Smartphone& other);
    //Smartphone& operator=(const Smartphone& other);

    void display() const override;
};

#endif
