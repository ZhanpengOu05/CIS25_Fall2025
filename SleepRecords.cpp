#include "SleepRecord.h"

// Default constructor
SleepRecord::SleepRecord() {}

// Full constructor
SleepRecord::SleepRecord(const string& bw,
                         const string& brw,
                         const string& mls,
                         const string& gt,
                         const string& ts)
    : bodyWeight(bw),
      brainWeight(brw),
      maxLifeSpan(mls),
      gestationTime(gt),
      totalSleep(ts) {}

// Print method
void SleepRecord::print() const {
    cout << "Body weight: "     << bodyWeight    << "\n"
         << "Brain weight: "    << brainWeight   << "\n"
         << "Max life span: "   << maxLifeSpan   << " years\n"
         << "Gestation time: "  << gestationTime << " days\n"
         << "Total sleep: "     << totalSleep    << " hours\n"
         << "----------------------------------------\n";
}
