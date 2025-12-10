#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "SleepRecord.h"

using namespace std;

vector<string> splitCSVLine(const string& line) {
    vector<string> tokens;
    string token;
    stringstream ss(line);

    while (getline(ss, token, ',')) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    const string filename = "dataset_2191_sleep.csv";
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error: Could not open file: " << filename << endl;
        return 1;
    }

    string line;

    // Discard header
    if (!getline(file, line)) {
        cout << "Error: File is empty or missing header.\n";
        return 1;
    }

    vector<SleepRecord> records;
    const int MAX_RECORDS = 30;
    int rowCount = 0;

    while (getline(file, line) && rowCount < MAX_RECORDS) {
        if (line.empty()) continue;

        vector<string> cols = splitCSVLine(line);

        if (cols.size() < 8) continue;

        string bodyWeight    = cols[0];
        string brainWeight   = cols[1];
        string maxLifeSpan   = cols[2];
        string gestationTime = cols[3];
        string totalSleep    = cols[7];

        if (gestationTime == "?") {
            gestationTime = "Unknown";
        }

        SleepRecord rec(bodyWeight, brainWeight, maxLifeSpan, gestationTime, totalSleep);
        records.push_back(rec);
        rowCount++;
    }

    file.close();

    cout << "Loaded " << records.size() << " records.\n";
    cout << "Displaying them now:\n";
    cout << "========================================\n";

    for (size_t i = 0; i < records.size(); ++i) {
        cout << "Record #" << (i + 1) << ":\n";
        records[i].print();
    }

    return 0;
}
