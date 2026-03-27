#include "core/scheduler_types.h"
#include <iostream>
#include <iomanip>

using namespace std;

void printGantt(const vector<GanttEntry>& gantt) {
    cout << "\nGantt Chart:\n";

    // Top bar
    for (auto &g : gantt) cout << "-----------";
    cout << "\n|";

    // Process labels
    for (auto &g : gantt) {
        cout << setw(9) << g.label << " |";
    }
    cout << "\n";

    // Bottom bar
    for (auto &g : gantt) cout << "-----------";
    cout << "\n";

    // 🔥 FIXED TIMELINE ALIGNMENT
    int currentPos = 0;

    for (int i = 0; i < gantt.size(); i++) {
        string timeStr = to_string(gantt[i].start);
        cout << timeStr;

        int space = 11 - timeStr.length();
        for (int j = 0; j < space; j++) cout << " ";
    }

    // last end time
    cout << gantt.back().end << endl;
}