#include <iostream>
using namespace std;

class Product {
    int id;
    string namel
    float price;

public;
    Product(int i, string n, float p) : id(i), name(n), price(p) {
        cout << "Constructor called\n";
    }
    ~Product() {
        cout<< "Destructor called\n";
    }

    void printDetail() {
        cout << "ID: " << id << ", Name: " << name << ", Price: $" << price << endl;
    }
};

int main() {
    Product p(101, "Notebook", 3.99);
    p.printDetails();
    return 0;
}