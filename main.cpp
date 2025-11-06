#include <iostream>
#include "BankAccount.h"
using namespace std;

int main() {
    BankAccount myAccount;

    myAccount.deposit(500.00);
    myAccount.makePurchase("Coffee", 5.00);
    myAccount.makePurchase("Notebook", 10.00);
    myAccount.makePurchase("Headphones", 100.00);

    myAccount.displayBalance();

    cout << "Transactions have been saved to transactions.txt\n";
    return 0;
}
