#include "core/scheduler_types.h"
#include <iostream>
#include <iomanip>

using namespace std;

void printMetrics(const vector<ProcData>& proc) {
    int n = proc.size();

    int totalBurst = 0;
    double totalWT = 0, totalTAT = 0;

    for (auto &p : proc) {
        totalBurst += p.burst;
        totalWT += p.wt;
        totalTAT += p.tat;
    }

    int firstArrival = proc[0].arrival;
    int lastCompletion = proc.back().completion;
    int totalTime = lastCompletion - firstArrival;

    double cpuUtil = (double) totalBurst / totalTime * 100;
    double throughput = (double) n / totalTime;

    cout << fixed << setprecision(2);
    cout << "\nCPU Utilization: " << cpuUtil << " %\n";

    if (throughput < 0.001)
        cout << scientific << setprecision(2);
    else
        cout << fixed << setprecision(5);

    cout << "Throughput: " << throughput << "\n";

    cout << fixed << setprecision(2);
    cout << "Average WT: " << totalWT / n << "\n";
    cout << "Average TAT: " << totalTAT / n << "\n";
}