#include "BankAccount.h"
#include <iostream>
#include <fstream>
using namespace std;

BankAccount::BankAccount() {
    balance = 0.0;
}

void BankAccount::deposit(double amount) {
    balance += amount;
    cout << "Deposited: $" << amount << endl;
    saveTransaction("Deposit", amount);
}

void BankAccount::makePurchase(string item, double cost) {
    if (cost > balance) {
        cout << "Insufficient funds for " << item << "!" << endl;
    } else {
        balance -= cost;
        cout << "Purchased: " << item << " for $" << cost << endl;
        saveTransaction("Purchase - " + item, cost);
    }
}

void BankAccount::displayBalance() const {
    cout << "Current Balance: $" << balance << endl;
}

void BankAccount::saveTransaction(string type, double amount) {
    ofstream file("transactions.txt", ios::app);
    if (file.is_open()) {
        file << type << ": $" << amount << endl;
        file.close();
    } else {
        cout << "Error opening transaction log file." << endl;
    }
}
