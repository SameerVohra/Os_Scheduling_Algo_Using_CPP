#include "core/scheduler_types.h"
#include <bits/stdc++.h>

using namespace std;

ScheduleResult rrAlgo(vector<ProcData> proc, int qTime) {
    int n = proc.size();

    vector<int> remainingBurst(n);
    for (int i = 0; i < n; ++i) {
        remainingBurst[i] = proc[i].burst;
    }

    int currentTime = 0;
    int completedCount = 0;

    queue<int> readyQueue;
    vector<bool> inQueue(n, false);

    vector<GanttEntry> gantt;

    // Sort by arrival time (important)
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a, int b) {
        return proc[a].arrival < proc[b].arrival;
    });

    int idx = 0;

    // push first available process
    if (proc[order[0]].arrival > currentTime) {
        gantt.push_back({"idle", currentTime, proc[order[0]].arrival});
        currentTime = proc[order[0]].arrival;
    }

    readyQueue.push(order[0]);
    inQueue[order[0]] = true;
    idx = 1;

    while (completedCount < n) {
        if (readyQueue.empty()) {
            // jump to next arrival
            int next = order[idx];
            gantt.push_back({"idle", currentTime, proc[next].arrival});
            currentTime = proc[next].arrival;
            readyQueue.push(next);
            inQueue[next] = true;
            idx++;
            continue;
        }

        int i = readyQueue.front();
        readyQueue.pop();

        int execTime = min(qTime, remainingBurst[i]);
        int start = currentTime;

        currentTime += execTime;
        remainingBurst[i] -= execTime;

        gantt.push_back({proc[i].pid, start, currentTime});

        // Add newly arrived processes
        while (idx < n && proc[order[idx]].arrival <= currentTime) {
            readyQueue.push(order[idx]);
            inQueue[order[idx]] = true;
            idx++;
        }

        if (remainingBurst[i] > 0) {
            readyQueue.push(i);
        } else {
            proc[i].completion = currentTime;
            proc[i].tat = proc[i].completion - proc[i].arrival;
            proc[i].wt = proc[i].tat - proc[i].burst;
            completedCount++;
        }
    }

    return {proc, gantt};
}