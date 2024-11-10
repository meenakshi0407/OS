#include <iostream>
#include <algorithm>
using namespace std;

void findWaitingTime(int processes[], int n, int bt[], int wt[], int at[], int timeQuantum) {
    int rem_bt[n];
    for (int i = 0; i < n; i++) {
        rem_bt[i] = bt[i];  // Initialize remaining burst times
    }

    int t = 0;  // Current time
    bool done;

    while (true) {
        done = true;
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0 && at[i] <= t) {  // Process has arrived and has remaining burst time
                done = false;  // There is a pending process

                if (rem_bt[i] > timeQuantum) {
                    t += timeQuantum;
                    rem_bt[i] -= timeQuantum;
                } else {
                    t += rem_bt[i];
                    wt[i] = t - bt[i] - at[i];
                    rem_bt[i] = 0;
                }
            }
        }

        // If no process was processed in this cycle, increment time
        if (done) {
            for (int i = 0; i < n; i++) {
                if (rem_bt[i] > 0 && at[i] > t) {
                    t = at[i];  // Move to next process arrival time
                    done = false;
                    break;
                }
            }
        }

        if (done) break;  // All processes are complete
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

int main() {
    int n = 3;
    int processes[] = {1, 2, 3};
    int burst_time[] = {10, 5, 8};
    int arrival_time[] = {0, 1, 2};
    int timeQuantum = 2;

    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, burst_time, wt, arrival_time, timeQuantum);
    findTurnAroundTime(processes, n, burst_time, wt, tat);

    cout << "Processes  Arrival Time  Burst Time  Waiting Time  Turn Around Time\n";
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        cout << " " << processes[i] << "\t\t" << arrival_time[i] << "\t\t" << burst_time[i] 
             << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }

    cout << "\nAverage waiting time = " << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = " << (float)total_tat / (float)n;
    return 0;
}
