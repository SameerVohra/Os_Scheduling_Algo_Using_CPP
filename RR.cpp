#include<bits/stdc++.h>
#include "algos.h"
using namespace std;

void rrAlgo(vector<ProcData>& proc) {
    int n = proc.size();
    int qTime;
    cout << "Enter the quant time: ";
    cin >> qTime;

    vector<int> remainingBurst(n);
    for (int i = 0; i < n; ++i) {
        remainingBurst[i] = proc[i].burst;
    }

    int currentTime = 0;
    queue<int> readyQueue;
    vector<bool> inQueue(n, false); // Initialize with false for later processes
    inQueue[0] = true; // Mark the first process in the queue
    int completedCount = 0;

    readyQueue.push(0);

    while (completedCount < n) {
        int i = readyQueue.front();
        readyQueue.pop();

        if (remainingBurst[i] > qTime) {
            currentTime += qTime;
            remainingBurst[i] -= qTime;
            readyQueue.push(i); // Push back the process if not completed
        } else {
            currentTime += remainingBurst[i];
            proc[i].completion = currentTime;
            proc[i].tat = proc[i].completion - proc[i].arrival;
            proc[i].wt = proc[i].tat - proc[i].burst;
            remainingBurst[i] = 0;
            completedCount++;
        }

        for (int j = 0; j < n; ++j) {
            if (!inQueue[j] && remainingBurst[j] > 0 && proc[j].arrival <= currentTime) {
                readyQueue.push(j);
                inQueue[j] = true; // Mark the process as in the queue
            }
        }

        if (readyQueue.empty()) {
            for (int j = 0; j < n; ++j) {
                if (remainingBurst[j] > 0) {
                    currentTime = max(currentTime, proc[j].arrival);
                    readyQueue.push(j);
                    inQueue[j] = true;
                    break;
                }
            }
        }
    }

        cout << "Process ID | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    double totalTAT = 0, totalWT = 0;
    for (const auto& p : proc) {
        cout << p.pid << "        | " << p.arrival << "          | " << p.burst 
             << "         | " << p.completion << "             | " << p.tat 
             << "             | " << p.wt << endl;
        totalTAT += p.tat;
        totalWT += p.wt;
    }

    cout << "Average Turnaround Time: " << totalTAT / n << endl;
    cout << "Average Waiting Time: " << totalWT / n << endl;
}
