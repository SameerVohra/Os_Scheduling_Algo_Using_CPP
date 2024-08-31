#include <bits/stdc++.h>
#include "algos.h"

using namespace std;

void sjfAlgo(vector<ProcData>& proc) {
    int n = proc.size();

    for (int i = 0; i < n; ++i) {
        proc[i].remainingBurst = proc[i].burst;
    }

    int currentTime = 0;
    int completedCount = 0;
    vector<bool> completed(n, false);
    double totalTAT = 0, totalWT = 0;

    while (completedCount < n) {
        int shortest = -1;

        for (int i = 0; i < n; ++i) {
            if (!completed[i] && proc[i].arrival <= currentTime) {
                if (shortest == -1 || proc[i].burst < proc[shortest].burst) {
                    shortest = i;
                }
            }
        }

        if (shortest == -1) {
            currentTime++;
        } else {
            proc[shortest].completion = currentTime + proc[shortest].burst;
            proc[shortest].tat = proc[shortest].completion - proc[shortest].arrival;
            proc[shortest].wt = proc[shortest].tat - proc[shortest].burst;

            totalTAT += proc[shortest].tat;
            totalWT += proc[shortest].wt;
            completed[shortest] = true;
            completedCount++;
            currentTime = proc[shortest].completion;
        }
    }

    cout << "Process ID | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    for (const auto& p : proc) {
        cout << setw(10) << p.pid << " | "
             << setw(12) << p.arrival << " | "
             << setw(10) << p.burst << " | "
             << setw(16) << p.completion << " | "
             << setw(15) << p.tat << " | "
             << setw(13) << p.wt << endl;
    }

    cout << "Average Turnaround Time: " << fixed << setprecision(2) << totalTAT / n << endl;
    cout << "Average Waiting Time: " << fixed << setprecision(2) << totalWT / n << endl;
}
