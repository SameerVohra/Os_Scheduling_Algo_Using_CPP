#include <bits/stdc++.h>
#include "core/scheduler_types.h"

using namespace std;

// Algorithm functions
ScheduleResult fcfsAlgo(vector<ProcData>);
ScheduleResult sjfAlgo(vector<ProcData>);
ScheduleResult rrAlgo(vector<ProcData>, int qTime);

// Compare function
void compareAll(
    const vector<ProcData>& proc,
    int qTime,
    ScheduleResult fcfsRes,
    ScheduleResult sjfRes,
    ScheduleResult rrRes
);

// Visualization functions
void printTable(const vector<ProcData>&);
void printGantt(const vector<GanttEntry>&);
void printMetrics(const vector<ProcData>&);

int main() {
    int a;
    cout << "1. FCFS\n";
    cout << "2. SJF\n";
    cout << "3. RR\n";
    cout << "4. Compare All (FCFS vs SJF vs RR)\n";
    cout << "Choose the process: ";
    cin >> a;

    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<ProcData> proc(n);

    for (int i = 0; i < n; i++) {
        proc[i].pid = "P" + to_string(i);

        cout << "Enter Arrival Time: ";
        cin >> proc[i].arrival;

        cout << "Enter Burst Time: ";
        cin >> proc[i].burst;
        cout << endl;
    }

    ScheduleResult result;

    switch (a) {
        case 1:
            result = fcfsAlgo(proc);
            break;

        case 2:
            result = sjfAlgo(proc);
            break;

        case 3: {
            int qTime;
            cout << "Enter the time quantum: ";
            cin >> qTime;

            result = rrAlgo(proc, qTime);
            break;
        }

        case 4: {
            int qTime;
            cout << "Enter time quantum for RR: ";
            cin >> qTime;

            auto fcfsRes = fcfsAlgo(proc);
            auto sjfRes  = sjfAlgo(proc);
            auto rrRes   = rrAlgo(proc, qTime);

            compareAll(proc, qTime, fcfsRes, sjfRes, rrRes);

            return 0; // 🔥 IMPORTANT: stop here
        }

        default:
            cout << "Invalid choice\n";
            return 0;
    }

    // ✅ Only runs for cases 1–3
    printTable(result.processes);
    printGantt(result.gantt);
    printMetrics(result.processes);

    return 0;
}