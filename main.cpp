#include <iostream>
#include <string>
#include "BankAccount.h"
using namespace std;

int main() {
    BankAccount myAccount;
    int choice = 0;
    string item;
    double amount;

    cout << "Welcome to the Bank Account App!\n";

    do {
        cout << "\n1) Deposit\n2) Make Purchase\n3) Show Balance\n4) Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            myAccount.deposit(amount);
            break;
        case 2:
            cout << "Enter item name: ";
            cin >> item;
            cout << "Enter cost: ";
            cin >> amount;
            myAccount.makePurchase(item, amount);
            break;
        case 3:
            myAccount.displayBalance();
            break;
        case 4:
            cout << "Saving transactions...\n";
            myAccount.saveTransaction("End Session", 0);
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    cout << "Goodbye!\n";
    return 0;
}
