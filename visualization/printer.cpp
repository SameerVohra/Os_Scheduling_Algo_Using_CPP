#include "core/scheduler_types.h"
#include <iostream>
#include <iomanip>

using namespace std;

void printTable(const vector<ProcData>& proc) {
    cout << "Process ID | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time\n";
    cout << "-------------------------------------------------------------------------------------------\n";

    for (const auto& p : proc) {
        cout << setw(10) << p.pid
             << setw(15) << p.arrival
             << setw(12) << p.burst
             << setw(18) << p.completion
             << setw(18) << p.tat
             << setw(15) << p.wt << endl;
    }
}