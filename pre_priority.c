#include<stdio.h>
#include<string.h>

struct process {
    char pname[10];
    int AT, BT, ST, FT, TT, WT, BT1, PR; // Added Priority
} p[15];

struct process t;
int i, n, j;

void get_data() {
    printf("Enter number of processes : ");
    scanf("%d",&n);

    printf("Enter process details for %d processes :",n);
    for(i=0;i<n;i++) {
        printf("\nEnter Process name, Arrival time, CPU burst time, Priority (lower = higher priority): ");
        scanf("%s %d %d %d", p[i].pname, &p[i].AT, &p[i].BT, &p[i].PR);
        p[i].BT1=p[i].BT;
    }
}

void put_data() {
    printf("\n\nProcesses are as below:\n");
    printf("\nProcess\tAT\tBT\tPriority");
    for(i=0;i<n;i++) {
        printf("\n%s\t%d\t%d\t%d",p[i].pname,p[i].AT,p[i].BT,p[i].PR);
    }
}

void avgTTWT() {
    float sumtt=0,sumwt=0;
    for(i=0;i<n;i++) {
        p[i].TT=p[i].FT-p[i].AT;
        p[i].WT=p[i].TT-p[i].BT1;
        sumtt+=p[i].TT;
        sumwt+=p[i].WT;
    }

    printf("\n\nProcess\tAT\tBT\tPR\tTT\tWT\tFT\n");
    for(i=0;i<n;i++) {
        printf("\n%s\t%d\t%d\t%d\t%d\t%d\t%d",
               p[i].pname,p[i].AT,p[i].BT1,p[i].PR,p[i].TT,p[i].WT,p[i].FT);
    }

    printf("\n\nAverage Turn Around Time = %.2f", sumtt/n);
    printf("\nAverage Waiting Time = %.2f\n", sumwt/n);
}

void pre_priority() {
    char GC[250]="";
    char str[10];
    int time=0, completed=0;
    int prev=-1;  // to track previously running process

    sprintf(str,"%d|",time);
    strcat(GC,str);

    while(completed<n) {
        int idx=-1;
        int highestPR=9999;

        // Select highest priority (lowest PR value) among arrived processes
        for(i=0;i<n;i++) {
            if(p[i].AT<=time && p[i].BT>0) {
                if(p[i].PR < highestPR) {
                    highestPR=p[i].PR;

                    idx=i;
                }
                else if(p[i].PR==highestPR) { 
                    // tie-break: earlier arrival
                    if(p[i].AT < p[idx].AT) idx=i;
                }
            }
        }

        if(idx==-1) {
            time++;
            continue;
        }

        // If new process is different from previous, context switch in Gantt chart
        if(prev!=idx) {
            strcat(GC,p[idx].pname);
            strcat(GC," ");
            sprintf(str,"%d|",time);
            strcat(GC,str);
            prev=idx;
        }

        // Run process for 1 unit
        p[idx].BT--;
        time++;

        if(p[idx].BT==0) {
            p[idx].FT=time;
            completed++;
            // When process finishes, mark end time
            sprintf(str,"%d|",time);
            strcat(GC,str);
            prev=-1; // force next process name to print
        }
    }

    printf("\n\n\t\tGantt Chart\n\n");
    puts(GC);
    avgTTWT();
}

int main() {
    get_data();
    put_data();
    pre_priority();
    return 0;
}
