#include <iostream>
using namespace std;

int main() {
    // Print welcome message
    cout << "Hello Inventory System!\n";

    // Demonstrate escape characters
    cout << "\tThis line is indented with a tab.\n";
    cout << "First line.\nSecond line after newline.\n";

    // Output sizes of data types
    cout << "\nData Type Sizes:\n";
    cout << "Size of int:   " << sizeof(int) << " bytes\n";
    cout << "Size of float: " << sizeof(float) << " bytes\n";
    cout << "Size of char:  " << sizeof(char) << " byte\n";

    return 0;
}