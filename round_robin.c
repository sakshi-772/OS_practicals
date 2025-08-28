#include<stdio.h>

int main() {
    int n, tq;
    printf("Enter how many processes : ");
    scanf("%d", &n);

    int bt[n], at[n], ft[n], tat[n], wt[n], pid[n], rem_bt[n];
    for (int i = 0; i < n; i++) {
        pid[i] = i+1;
        printf("Enter Burst time for process %d: ", i+1);
        scanf("%d", &bt[i]);
        printf("Enter Arrival time for process %d: ", i+1);
        scanf("%d", &at[i]);
        rem_bt[i] = bt[i];   // initially same
    }

    printf("Enter Time Quantum : ");
    scanf("%d", &tq);

    int time = 0, completed = 0;

    // Arrays to store Gantt chart info
    int gc_pid[1000], gc_start[1000], gc_end[1000], gc_count = 0;

    while (completed < n) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0 && at[i] <= time) {
                done = 0;  // still something left

                gc_pid[gc_count] = pid[i];
                gc_start[gc_count] = time;

                if (rem_bt[i] > tq) {
                    time += tq;
                    rem_bt[i] -= tq;
                } else {
                    time += rem_bt[i];
                    rem_bt[i] = 0;
                    ft[i] = time;   // finish time
                    completed++;
                }

                gc_end[gc_count] = time;
                gc_count++;
            }
        }

        if (done == 1) {  // if no process is ready
            time++;
        }
    }

    // calculate TAT and WT
    float avg_wt = 0, avg_tat = 0;
    for (int i = 0; i < n; i++) {
        tat[i] = ft[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    avg_tat /= n;
    avg_wt /= n;

    // Print table
    printf("\n\nProcess\tBT\tAT\tFT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], bt[i], at[i], ft[i], tat[i], wt[i]);
    }

    // Print Gantt chart
    printf("\n*** Gantt Chart ***\n|");
    for (int i = 0; i < gc_count; i++) {
        printf(" P%d |", gc_pid[i]);
    }
    printf("\n%d", gc_start[0]);
    for (int i = 0; i < gc_count; i++) {
        printf("    %d", gc_end[i]);
    }
    printf("\n");

    printf("\nAverage TAT: %.2f", avg_tat);
    printf("\nAverage WT : %.2f\n", avg_wt);

    return 0;
}