#include "core/scheduler_types.h"
#include <algorithm>

ScheduleResult fcfsAlgo(vector<ProcData> proc) {
    stable_sort(proc.begin(), proc.end(), [](auto &a, auto &b) {
        return a.arrival < b.arrival;
    });

    int currentTime = 0;
    vector<GanttEntry> gantt;

    for (auto &p : proc) {
        if (currentTime < p.arrival) {
            gantt.push_back({"idle", currentTime, p.arrival});
            currentTime = p.arrival;
        }

        int start = currentTime;

        p.completion = currentTime + p.burst;
        p.tat = p.completion - p.arrival;
        p.wt = p.tat - p.burst;

        currentTime = p.completion;

        gantt.push_back({p.pid, start, currentTime});
    }

    return {proc, gantt};
}