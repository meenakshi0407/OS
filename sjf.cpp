#include <iostream>
#include <climits>
using namespace std;

void calculateTimes(int n, int at[], int bt[], int wt[], int tat[]) {
    int rem_bt[n], complete = 0, t = 0;

    
    for (int i = 0; i < n; i++) rem_bt[i] = bt[i];

    while (complete != n) {
        int shortest = -1, minm = INT_MAX;

        
        for (int i = 0; i < n; i++) {
            if (at[i] <= t && rem_bt[i] > 0 && rem_bt[i] < minm) {
                minm = rem_bt[i];
                shortest = i;
            }
        }

        // If no process found, increment time and continue
        if (shortest == -1) { t++; continue; }

        // Process the shortest job for one time unit
        rem_bt[shortest]--;
        t++;

        // If process is finished, calculate waiting time
        if (rem_bt[shortest] == 0) {
            complete++;
            wt[shortest] = t - bt[shortest] - at[shortest];
            if (wt[shortest] < 0) wt[shortest] = 0;  // Ensure no negative waiting time
        }
    }

    // Calculate turnaround times
    for (int i = 0; i < n; i++) tat[i] = bt[i] + wt[i];
}

int main() {
    int n = 4;
    int arrival_time[] = {0, 1, 2, 4};
    int burst_time[] = {5, 4, 2, 1};
    int wt[n] = {}, tat[n] = {};

    calculateTimes(n, arrival_time, burst_time, wt, tat);

    // Display results and calculate averages
    float total_wt = 0, total_tat = 0;
    cout << "Process  Arrival  Burst  Waiting  Turnaround\n";
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        cout << " " << i + 1 << "\t    " << arrival_time[i] << "\t    " << burst_time[i]
             << "\t    " << wt[i] << "\t    " << tat[i] << endl;
    }

    cout << "\nAvg waiting time = " << total_wt / n;
    cout << "\nAvg turnaround time = " << total_tat / n;
    return 0;
}
