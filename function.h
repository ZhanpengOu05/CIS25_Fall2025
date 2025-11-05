#include <iostream>
#include <limits>
using namespace std;

void addNumbers() {
    double a, b;
    cout << "Enter two numbers to add: ";
    if (!(cin >> a >> b)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Try again.\n";
        return;
    }
    cout << "Sum = " << (a + b) << "\n";
}

void showGreeting() {
    cout << "Hello! Welcome to Week 5: Functions & Loops.\n";
}

void multiplyNumbers() {
    double x, y;
    cout << "Enter two numbers to multiply: ";
    if (!(cin >> x >> y)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Try again.\n";
        return;
    }
    cout << "Product = " << (x * y) << "\n";
}
