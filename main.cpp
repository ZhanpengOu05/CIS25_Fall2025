#include <iostream>
#include <limits>
#include <string>
#include "BankAccount.h"

using namespace std;

/*
 * getIntChoice
 * ------------
 * Safely gets an integer from the user for menu choices.
 */
int getIntChoice() {
    int choice;
    while (true) {
        cin >> choice;
        if (!cin.fail()) {
            return choice;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number: ";
    }
}

int main() {
    BankAccount myAccount;
    int choice = 0;
    string item;
    string category;
    double amount;

    // ===== Welcome screen for Bank ZP =====
    cout << "=========================================\n";
    cout << "         Welcome to Bank ZP\n";
    cout << "=========================================\n";
    cout << "Press Enter to continue...";
    // Clear any leftover input and wait for Enter
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get(); // waits for user to press Enter

    // ===== Main menu loop =====
    do {
        cout << "\n===== Main Menu =====\n";
        cout << "1) Deposit\n";
        cout << "2) Make Purchase\n";
        cout << "3) Show Balance\n";
        cout << "4) Show Transaction History (This Session)\n";
        cout << "5) Show Spending Summary (Percent by Category)\n";
        cout << "6) Exit\n";
        cout << "Choose an option (1-6): ";

        choice = getIntChoice();

        switch (choice) {
        case 1:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            myAccount.deposit(amount);
            break;

        case 2:
            cout << "Enter item name (no spaces): ";
            cin >> item;
            cout << "Enter cost: ";
            cin >> amount;
            cout << "Enter category (e.g., food, gas, fun): ";
            cin >> category;
            myAccount.makePurchase(item, amount, category);
            break;

        case 3:
            myAccount.displayBalance();
            break;

        case 4:
            myAccount.displayTransactions();
            break;

        case 5:
            myAccount.displaySpendingSummary();
            break;

        case 6:
            cout << "Saving end-of-session marker...\n";
            myAccount.saveTransaction("End Session", 0);
            // Also update the all-time account summary file
            myAccount.saveAccountSummary();
            break;

        default:
            cout << "Invalid choice. Please select 1-6.\n";
        }
    } while (choice != 6);

    cout << "Thank you for using Bank ZP. Goodbye!\n";
    return 0;
}
