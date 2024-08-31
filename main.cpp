#include <bits/stdc++.h>
#include "algos.h"

using namespace std;

int main() {
    int a;
    cout << "1. FCFS" << endl;
    cout << "2. SJF" << endl;
    cout << "3. RR" << endl;
    cout << "Choose the process: ";
    cin >> a;

    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    vector<ProcData> proc(n);

    for(int i=0; i<n; i++){
        proc[i].pid = "P"+to_string(i);
        cout << "Enter Arrival Time: ";
        cin >> proc[i].arrival;
        cout << "Enter Burst Time: ";
        cin >> proc[i].burst;
        cout << endl;
    }

    myfunction();
    switch(a){
        case 1:
            fcfsAlgo(proc);
            break;
        case 2:
            sjfAlgo(proc);
            break;
        case 3:
            rrAlgo(proc);
            break;
        default:
            break;
    }
    return 0;
}
