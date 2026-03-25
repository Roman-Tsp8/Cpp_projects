#include "product.h"
#include <utility>

int Product::ProductCount = 0;

Product::Product() : Product("Unknown", 0.0, 1) {}

Product::Product(string n, double p, int q) : name(n) , price(p), quantity(q) {
    ProductCount++;
    cout << "Product constructor is called " << endl;
}

Product::Product(const Product& other) : name(other.name), price(other.price), quantity(other.quantity) {
    ProductCount++;
    cout << "Product copy constructor is called " << endl;
}

Product::Product(Product&& other) noexcept : name(move(other.name)), price(other.price), quantity(other.quantity) {
    ProductCount++;
    cout << "Product move constructor is called " << endl;
}

Product& Product::operator=(const Product& other) {
    if (this != &other) {
        name = other.name;
        price = other.price;
        quantity = other.quantity;
    }
    return *this;
}

Product::~Product() {
    cout << "Product destructor is called " << endl;
}

void Product::display() const {
    cout << "Product Name: " << name << endl;
    cout << "Price: $" << price << endl;
    cout << "Quantity: " << quantity << endl;
}


void Product::setPrice(double p) {
    this->price = p;
}

int Product::getProductCount() {
    return ProductCount;
}

Product Product::operator-() const {
    return Product(name, price, -quantity);
}

Product Product::operator+(const Product& other) const {
    return Product(name, price, quantity + other.quantity);
}

ostream& operator<<(ostream& out, const Product& p) {
    out << "Product Name: " << p.name << endl;
    out << "Price: $" << p.price << endl;
    out << "Quantity: " << p.quantity << endl;
    return out;
}

istream& operator>>(istream& in, Product& p) {
    cout << "Enter product name: ";
    in >> p.name;
    cout << "Enter product price: ";
    in >> p.price;
    cout << "Enter product quantity: ";
    in >> p.quantity;
    return in;
}

// electronics product implementation

ElectronicsProduct::ElectronicsProduct(string n, double p, int q, int w) : Product(n, p, q), warrranty(w) {}
void ElectronicsProduct::display() const {
    Product::display();
    cout << "Warranty: " << warrranty << " months" << endl;
}


