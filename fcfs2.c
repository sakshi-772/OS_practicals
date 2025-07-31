#include <stdio.h>

struct Process {
    int pid;     // Process ID
    int at;      // Arrival Time
    int bt;      // Burst Time
    int ct;      // Completion Time
    int tat;     // Turnaround Time
    int wt;      // Waiting Time
};

void sortByArrival(struct Process p[], int n) {
    struct Process temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (p[j].at > p[j+1].at) {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    // Input
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Arrival Time and Burst Time for Process P%d: ", p[i].pid);
        scanf("%d%d", &p[i].at, &p[i].bt);
    }

    sortByArrival(p, n);

    // Calculate Completion Time, Turnaround Time, Waiting Time
    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < p[i].at) {
            currentTime = p[i].at;  // CPU is idle
        }
        p[i].ct = currentTime + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        currentTime = p[i].ct;
    }

    // Display Process Table
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    // Gantt Chart
    printf("\nGantt Chart:\n");

    // Top bar
    printf(" ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p[i].bt; j++) printf("--");
        printf(" ");
    }
    printf("\n|");

    // Process IDs
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p[i].bt - 1; j++) printf(" ");
        printf("P%d", p[i].pid);
        for (int j = 0; j < p[i].bt - 1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");

    // Bottom bar
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p[i].bt; j++) printf("--");
        printf(" ");
    }

    // Time line
    printf("\n0");
    currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < p[i].at) currentTime = p[i].at;
        currentTime += p[i].bt;
        printf("%*d", p[i].bt * 2, currentTime);
    }

    printf("\n");
    return 0;
}

