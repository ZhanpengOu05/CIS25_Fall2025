#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

class BankAccount {
private:
    double balance;

public:
    BankAccount();
    void deposit(double amount);
    void makePurchase(std::string item, double cost);
    void displayBalance() const;
    void saveTransaction(std::string type, double amount);
};

#endif
