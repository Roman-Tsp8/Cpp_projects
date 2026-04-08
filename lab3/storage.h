#pragma once;
#include "product.h"
#include <vector>
#include <memory>

using namespace std;

void SaveProducts(const vector<shared_ptr<Product>>& products);
void loadProducts(vector<shared_ptr<Product>>& products);
void logAction(const string& text);