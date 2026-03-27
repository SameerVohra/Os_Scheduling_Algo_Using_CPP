#pragma once
#include <vector>
#include <string>

using namespace std;

struct ProcData {
    string pid;
    int arrival, burst;
    int completion, tat, wt;
};

struct GanttEntry {
    string label;
    int start;
    int end;
};

struct ScheduleResult {
    vector<ProcData> processes;
    vector<GanttEntry> gantt;
};