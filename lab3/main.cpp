#include <iostream>
#include "string"
#include "product.h"
#include "customer.h"
#include "order.h"    

using namespace std;

int main() {
    Product s1("Laptop", 799.99, 10);
    s1.display();
    Product s2 = s1;
    
    s2.setPrice(899.99);
    Product s4("Smartphone", 499.99, 5);
    s4.display();

    Product s5 = s2 + s1;
    cout << s5 << endl;

    Product s6;
    cin >> s6;
    cout << s6 << endl;

    Customer c1("Johny K", "johnyk@gmail.com");
    c1.display();


    Order o1("Laptop", 432);
    o1.display();

    cout << "Total number of products created: " << Product::getProductCount() << endl;
    return 0;
}