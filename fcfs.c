#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
struct Process {
    int pid;     // Process ID
    int at;      // Arrival Time
    int bt;      // Burst Time
    int ft;      // Finish Time
    int tat;     // Turnaround Time
    int wt;      // Waiting Time
};
void sort(struct Process P[],int n)
{
for (int i=0;i<n-1;i++)
{
for (int j=0;j<n-i-1;j++)
{
struct Process temp;
if(P[j].at>P[j+1].at)
{
temp=P[j];
P[j]=P[j+1];
P[j+1]=temp;
}
}
}
}

int main()
{
int n;
printf("enter how many processes\n");
scanf("%d",&n);
struct Process p[n];
//enter the burst time
printf("enter the burst time for the processes\n");
for(int i=0;i<n;i++)
{
p[i].pid = i + 1;
//printf("P%d",i+1);
scanf("%d",&p[i].bt);
}
//enter the arrival time
printf("enter the arrival time for the given processes\n");
for(int i=0;i<n;i++)
{
//p[i].pid = i + 1;

scanf("%d",&p[i].at);
}
sort(p,n);
int currentTime = 0;
for (int i = 0; i < n; i++) {
 if (currentTime < p[i].at) {
      currentTime = p[i].at;  // CPU is idle
   }
 p[i].ft = currentTime + p[i].bt;
 p[i].tat = p[i].ft - p[i].at;
 p[i].wt = p[i].tat - p[i].bt;
 currentTime = p[i].ft;
    }

printf("\nProcess\tAT\tBT\tFT\tTAT\tWT\n");
for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ft, p[i].tat, p[i].wt);
    }

//print("gantt chart")
printf("gantt chart\n");
 printf(" ");
   /* for (int i = 0; i < n; i++) {
        for (int j = 0; j < p[i].bt; j++)
        printf("--");
        printf(" ");
    }
    printf("\n|");
*/

 for (int i = 0; i < n; i++) {
        for (int j = 0; j < p[i].bt - 1; j++)
        printf(" ");
        printf("P%d", p[i].pid);
        for (int j = 0; j < p[i].bt - 1; j++) 
        printf(" ");
        printf("|");
    }
    printf("\n ");


 printf("\n0");
    currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < p[i].at) 
        currentTime = p[i].at;
        currentTime += p[i].bt;
        printf("%*d", p[i].bt * 2, currentTime);
    }

    printf("\n");
    return 0;
}
