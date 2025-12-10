#ifndef SLEEPRECORD_H
#define SLEEPRECORD_H

#include <string>
#include <iostream>
using namespace std;

class SleepRecord {
private:
    string bodyWeight;
    string brainWeight;
    string maxLifeSpan;
    string gestationTime;
    string totalSleep;

public:
    // Constructors
    SleepRecord();
    SleepRecord(const string& bw,
                const string& brw,
                const string& mls,
                const string& gt,
                const string& ts);

    // Print method
    void print() const;
};

#endif
