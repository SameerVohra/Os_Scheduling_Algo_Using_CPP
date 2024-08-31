#ifndef FUNCTION_H
#define FUNCTION_H
#include <bits/stdc++.h>
using namespace std;

struct ProcData {
    string pid;
    int arrival;
    int burst;
    int remainingBurst;
    int completion;
    int tat;
    int wt;
};

void myfunction();
void fcfsAlgo(vector<ProcData>& proc);
void sjfAlgo(vector<ProcData>& proc);
void rrAlgo(vector<ProcData>& proc);

#endif
