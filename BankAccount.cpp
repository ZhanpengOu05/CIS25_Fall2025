#include "BankAccount.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

/*
 * Constructor
 * -----------
 * Starts account at $0 and resets session stats.
 */
BankAccount::BankAccount()
    : balance(0.0),
      totalPurchaseAmount(0.0) {}

/*
 * deposit
 * -------
 * Adds money to the account and records the transaction.
 */
void BankAccount::deposit(double amount) {
    if (amount <= 0) {
        cout << "Deposit amount must be positive.\n";
        return;
    }

    balance += amount;
    cout << "Deposited: $" << amount << endl;

    // Save in session history
    Transaction t;
    t.description = "Deposit";
    t.amount = amount;
    t.resultingBalance = balance;
    t.category = "";
    t.isPurchase = false;
    history.push_back(t);

    // Save to long-term file
    saveTransaction("Deposit", amount);
}

/*
 * makePurchase
 * ------------
 * Spends money on an item, updates category totals,
 * session history, and long-term file.
 */
void BankAccount::makePurchase(const string& item,
                               double cost,
                               const string& category) {
    if (cost <= 0) {
        cout << "Purchase amount must be positive.\n";
        return;
    }

    if (cost > balance) {
        cout << "Insufficient funds for " << item << "!\n";
        return;
    }

    balance -= cost;

    cout << "Purchased: " << item << " for $" << cost
         << " [Category: " << category << "]" << endl;

    // Record in session history
    Transaction t;
    t.description = "Purchase - " + item;
    t.amount = cost;
    t.resultingBalance = balance;
    t.category = category;
    t.isPurchase = true;
    history.push_back(t);

    // Update session stats
    totalPurchaseAmount += cost;
    purchaseByCategory[category] += cost;

    // Save formatted line to file
    string formattedType = "Purchase - " + item + " (Category: " + category + ")";
    saveTransaction(formattedType, cost);
}

/*
 * displayBalance
 * --------------
 * Shows current balance.
 */
void BankAccount::displayBalance() const {
    cout << "\nCurrent Balance: $" << balance << "\n";
}

/*
 * displayTransactions
 * -------------------
 * Shows all transactions during THIS program run.
 */
void BankAccount::displayTransactions() const {
    if (history.empty()) {
        cout << "No transactions in this session.\n";
        return;
    }

    cout << "\n=== Transaction History (This Session) ===\n";

    for (size_t i = 0; i < history.size(); ++i) {
        const Transaction& t = history[i];

        cout << i + 1 << ") " << t.description
             << " | Amount: $" << t.amount
             << " | Balance After: $" << t.resultingBalance;

        if (t.isPurchase)
            cout << " | Category: " << t.category;

        cout << endl;
    }

    cout << "-----------------------------------------\n";
}

/*
 * displaySpendingSummary
 * ----------------------
 * Summarizes purchases by category for THIS session.
 */
void BankAccount::displaySpendingSummary() const {
    if (purchaseByCategory.empty() || totalPurchaseAmount <= 0.0) {
        cout << "No category spending data yet.\n";
        return;
    }

    cout << "\n=== Spending Summary (This Session) ===\n";
    cout << "Total spent: $" << totalPurchaseAmount << "\n\n";

    for (const auto& entry : purchaseByCategory) {
        const string& category = entry.first;
        double amount = entry.second;
        double percent = (amount / totalPurchaseAmount) * 100.0;

        cout << "Category: " << setw(12) << left << category
             << " Amount: $" << setw(8) << amount
             << " (" << percent << "%)\n";
    }

    cout << "-----------------------------------------\n";
}

/*
 * saveTransaction
 * ----------------
 * Appends text to transactions.txt for long-term tracking.
 */
void BankAccount::saveTransaction(const string& type, double amount) {
    ofstream file("transactions.txt", ios::app);
    if (file.is_open()) {
        file << type << ": $" << amount << endl;
    } else {
        cout << "Could not open transactions.txt\n";
    }
}

/*
 * saveAccountSummary
 * ------------------
 * Reads ALL transactions from transactions.txt and
 * builds an all-time summary written to account_summary.txt.
 */
void BankAccount::saveAccountSummary() const {
    ifstream in("transactions.txt");
    if (!in.is_open()) {
        cout << "No transactions.txt found — cannot build summary.\n";
        return;
    }

    double totalDeposits = 0.0;
    double totalPurchases = 0.0;
    int depositCount = 0;
    int purchaseCount = 0;

    map<string, double> categoryTotals;

    string line;
    while (getline(in, line)) {
        // Extract amount
        size_t posDollar = line.find('$');
        if (posDollar == string::npos) continue;

        string amountStr = line.substr(posDollar + 1);
        double amt = 0.0;
        try { amt = stod(amountStr); }
        catch (...) { continue; }

        bool isDeposit = line.rfind("Deposit", 0) == 0;
        bool isPurchase = line.rfind("Purchase", 0) == 0;

        if (isDeposit) {
            totalDeposits += amt;
            depositCount++;
        }
        else if (isPurchase) {
            totalPurchases += amt;
            purchaseCount++;

            // Extract category
            size_t catStart = line.find("(Category:");
            if (catStart != string::npos) {
                size_t colon = line.find(':', catStart);
                size_t close = line.find(')', colon);
                if (colon != string::npos && close != string::npos) {
                    string cat = line.substr(colon + 1, close - colon - 1);

                    // Trim whitespace
                    size_t first = cat.find_first_not_of(" \t");
                    size_t last = cat.find_last_not_of(" \t");
                    if (first != string::npos)
                        cat = cat.substr(first, last - first + 1);

                    categoryTotals[cat] += amt;
                }
            }
        }
    }
    in.close();

    ofstream out("account_summary.txt");
    if (!out.is_open()) {
        cout << "Error writing account_summary.txt\n";
        return;
    }

    out << "===== ACCOUNT SUMMARY (ALL TIME) =====\n";
    out << "Total Deposited: $" << totalDeposits 
        << " (Count: " << depositCount << ")\n";
    out << "Total Spent:     $" << totalPurchases 
        << " (Count: " << purchaseCount << ")\n";
    out << "Net Change:      $" << (totalDeposits - totalPurchases) << "\n\n";

    if (!categoryTotals.empty()) {
        out << "Spending by Category:\n";
        for (const auto& entry : categoryTotals) {
            double percent = (totalPurchases == 0) ? 0.0 :
                (entry.second / totalPurchases * 100.0);

            out << " - " << entry.first
                << ": $" << entry.second
                << " (" << percent << "%)\n";
        }
    } else {
        out << "No categorized purchases found.\n";
    }

    out << "-----------------------------------------\n";

    out.close();
    cout << "account_summary.txt updated.\n";
}
