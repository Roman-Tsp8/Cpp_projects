#include "storage.h"
#include <fstream>

using namespace std;

void SaveProducts(const vector<shared_ptr<Product>>& products) {
    ofstream file("products.txt");
    for (auto& p : products) {
        file << p->getPrice() << " " << endl;
    }
}

void loadProducts(vector<shared_ptr<Product>>& products) {
    ifstream file("products.txt");
    double price;
    while (file >> price) {
        products.push_back(make_shared<Product>("Loaded Product", price, 1));
    }
}

void logAction(const string& text) {
    ofstream file("log.txt", ios::app);
    file<< text << endl;
}