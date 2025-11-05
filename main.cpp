#include <iostream>
#include "item.h"

int main() {
    // Create and save one item
    Item tool;
    tool.name = "Screwdriver";
    tool.quantity = 10;
    tool.saveToFile();           // writes to items.txt

    // Create and save another item (so you can see multiple lines)
    Item wrench;
    wrench.name = "Wrench";
    wrench.quantity = 5;
    wrench.saveToFile();

    // Read and display from file
    Item::loadFromFile();

    return 0;
}
