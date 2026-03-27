#include "core/scheduler_types.h"
#include <bits/stdc++.h>

using namespace std;

ScheduleResult sjfAlgo(vector<ProcData> proc) {
    int n = proc.size();

    int currentTime = 0;
    int completedCount = 0;

    vector<bool> completed(n, false);
    vector<GanttEntry> gantt;

    while (completedCount < n) {
        int shortest = -1;

        // Find shortest job among arrived processes
        for (int i = 0; i < n; ++i) {
            if (!completed[i] && proc[i].arrival <= currentTime) {
                if (shortest == -1 || proc[i].burst < proc[shortest].burst) {
                    shortest = i;
                }
            }
        }

        // No process available → idle
        if (shortest == -1) {
            int nextArrival = INT_MAX;

            for (int i = 0; i < n; ++i) {
                if (!completed[i]) {
                    nextArrival = min(nextArrival, proc[i].arrival);
                }
            }

            gantt.push_back({"idle", currentTime, nextArrival});
            currentTime = nextArrival;
            continue;
        }

        int start = currentTime;

        proc[shortest].completion = currentTime + proc[shortest].burst;
        proc[shortest].tat = proc[shortest].completion - proc[shortest].arrival;
        proc[shortest].wt = proc[shortest].tat - proc[shortest].burst;

        currentTime = proc[shortest].completion;

        gantt.push_back({proc[shortest].pid, start, currentTime});

        completed[shortest] = true;
        completedCount++;
    }

    return {proc, gantt};
}