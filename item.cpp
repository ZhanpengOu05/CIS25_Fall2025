#include "item.h"
#include <iostream>
#include <fstream>
#include <sstream>

using std::cout;
using std::endl;

void Item::saveToFile(const std::string& path) const {
    // Use append mode so previous data isn't overwritten
    std::ofstream out(path, std::ios::app);
    if (!out) {
        cout << "Unable to open file for writing: " << path << endl;
        return;
    }
    // Basic CSV: name,quantity  (avoid commas in names for this simple format)
    out << name << "," << quantity << "\n";
    cout << "Saved: " << name << " (" << quantity << ")\n";
}

void Item::loadFromFile(const std::string& path) {
    std::ifstream in(path);
    if (!in) {
        cout << "Unable to open file for reading: " << path << endl;
        return;
    }

    cout << "\n-- File contents (" << path << ") --\n";
    std::string line;
    while (std::getline(in, line)) {
        // Optional: parse the CSV back into fields
        std::istringstream ss(line);
        std::string n, qstr;
        if (std::getline(ss, n, ',') && std::getline(ss, qstr)) {
            cout << "Item: " << n << ", Qty: " << qstr << "\n";
        } else {
            // If a line is malformed, just show the raw line
            cout << "Raw: " << line << "\n";
        }
    }
    cout << "-- End of file --\n";
}

void Item::print() const {
    cout << "Item{name=\"" << name << "\", quantity=" << quantity << "}\n";
}
