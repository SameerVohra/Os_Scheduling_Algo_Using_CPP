#include <bits/stdc++.h>
#include "algos.h"

using namespace std;
void fcfsAlgo(vector<ProcData>& proc) {
    int n = proc.size();
    int currentTime = 0;
    for (int i = 0; i < n; ++i) {
        if (currentTime < proc[i].arrival) {
            currentTime = proc[i].arrival;
        }
        proc[i].completion = currentTime + proc[i].burst;
        proc[i].tat = proc[i].completion - proc[i].arrival;
        proc[i].wt = proc[i].tat - proc[i].burst;
        currentTime = proc[i].completion;
    }

    // Display the results
    cout << "Process ID | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    for (const auto& p : proc) {
        cout << p.pid << "        | " << p.arrival << "          | " << p.burst 
             << "         | " << p.completion << "             | " << p.tat 
             << "             | " << p.wt << endl;
    }
}
