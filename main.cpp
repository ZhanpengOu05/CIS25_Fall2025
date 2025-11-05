#include <iostream>
#include <limits>
#include "functions.h"
using namespace std;

static void showMenu() {
    cout << "\n=== Main Menu ===\n"
         << "1) Add Numbers\n"
         << "2) View Greeting\n"
         << "3) Multiply Numbers\n"
         << "4) Exit\n"
         << "Choose an option: ";
}

int main() {
    int option = 0;

    do {
        showMenu();
        if (!(cin >> option)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter 1-4.\n";
            continue;
        }

        switch (option) {
            case 1: addNumbers(); break;
            case 2: showGreeting(); break;
            case 3: multiplyNumbers(); break;
            case 4: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice. Please enter number "1-4".\n";
        }
    } while (option != 4);

    return 0;
}
