#include "product.h"
#include <utility>

int Product::ProductCount = 0;


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

Product::~Product() {
    cout << "Product destructor is called " << endl;
}

Product& Product::operator=(const Product& other) {
    if (this != &other) {
        name = other.name;
        price = other.price;
        quantity = other.quantity;
    }
    return *this;
}



void Product::nonVirtualDisplay() const {
    cout << "[Static] Product Name: " << name << ", Price: " << price << ", Quantity: " << quantity << endl;
}

void Product::display() const {
    cout << "[Dynamic] Product Name: " << name << ", Price: " << price << ", Quantity: " << quantity << endl;
}


void Product::setPrice(double p) {
    price = p;
}


double Product::getPrice() const { return price; }

Product Product::operator+(const Product& other) const {
    return Product(name, price, quantity + other.quantity);
}

void Product::sell() {
    if (quantity > 0) quantity--;
}

int Product::getProductCount() {
    return ProductCount;
}


// electronics product implementation

ElectronicsProduct::ElectronicsProduct(string n, double p, int q, int w) : Product(n, p, q), warranty(w) {}
void ElectronicsProduct::display() const {
    Product::display();
    cout << "Warranty: " << warranty << " months" << endl;
}

// smartphone implementation

Smartphone::Smartphone(string n, double p, int q, int w, string b) : ElectronicsProduct(n, p, q, w), brand(b) {}



void Smartphone::display() const {
    ElectronicsProduct::display();
    cout << "Brand: " << brand << endl;
}

