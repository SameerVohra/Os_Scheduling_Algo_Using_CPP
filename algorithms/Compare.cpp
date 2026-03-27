#include "core/scheduler_types.h"
#include <iostream>
#include <iomanip>

using namespace std;

struct Metrics {
    double avgWT, avgTAT, cpuUtil, throughput;
};

Metrics calculateMetrics(const vector<ProcData>& proc) {
    int n = proc.size();

    double totalWT = 0, totalTAT = 0;
    int totalBurst = 0;

    for (auto &p : proc) {
        totalWT += p.wt;
        totalTAT += p.tat;
        totalBurst += p.burst;
    }

    int totalTime = proc.back().completion - proc[0].arrival;

    Metrics m;
    m.avgWT = totalWT / n;
    m.avgTAT = totalTAT / n;
    m.cpuUtil = (double) totalBurst / totalTime * 100;
    m.throughput = (double) n / totalTime;

    return m;
}

void compareAll(const vector<ProcData>& proc, int qTime,
                ScheduleResult fcfsRes,
                ScheduleResult sjfRes,
                ScheduleResult rrRes) {

    auto m1 = calculateMetrics(fcfsRes.processes);
    auto m2 = calculateMetrics(sjfRes.processes);
    auto m3 = calculateMetrics(rrRes.processes);

    cout << "\n=========== COMPARISON ===========\n";

    cout << setw(10) << "Algo"
         << setw(15) << "Avg WT"
         << setw(15) << "Avg TAT"
         << setw(15) << "CPU %"
         << setw(15) << "Throughput\n";

    cout << "-------------------------------------------------------------\n";

    cout << setw(10) << "FCFS"
         << setw(15) << m1.avgWT
         << setw(15) << m1.avgTAT
         << setw(15) << m1.cpuUtil
         << setw(15) << m1.throughput << "\n";

    cout << setw(10) << "SJF"
         << setw(15) << m2.avgWT
         << setw(15) << m2.avgTAT
         << setw(15) << m2.cpuUtil
         << setw(15) << m2.throughput << "\n";

    cout << setw(10) << "RR"
         << setw(15) << m3.avgWT
         << setw(15) << m3.avgTAT
         << setw(15) << m3.cpuUtil
         << setw(15) << m3.throughput << "\n";
}