#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include <vector>
#include <map>

/*
 * BankAccount Class
 * -----------------
 * Manages:
 *   - Deposits & Purchases
 *   - Category-based tracking
 *   - Session transaction history
 *   - Long-term logging (transactions.txt)
 *   - Full account summary (account_summary.txt)
 */

class BankAccount {
private:

    struct Transaction {
        std::string description;      // e.g. "Deposit" or "Purchase - shoes"
        double amount;                // money involved
        double resultingBalance;      // balance AFTER this transaction
        std::string category;         // purchase category (empty for deposits)
        bool isPurchase;              // true if this is a purchase
    };

    double balance;                          
    std::vector<Transaction> history;        
    double totalPurchaseAmount;              
    std::map<std::string, double> purchaseByCategory;

public:

    BankAccount();

    // Add funds
    void deposit(double amount);

    // Purchase with category
    void makePurchase(const std::string& item,
                      double cost,
                      const std::string& category);

    // Show balance
    void displayBalance() const;

    // Show session transaction list
    void displayTransactions() const;

    // Show session spending summary
    void displaySpendingSummary() const;

    // Log transaction to file
    void saveTransaction(const std::string& type, double amount);

    // Generate full account summary from all-time data
    void saveAccountSummary() const;
};

#endif
