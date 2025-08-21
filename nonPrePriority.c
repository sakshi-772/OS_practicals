// Program for non pre emptive SJF scheduling
#include<stdio.h>
#include<stdlib.h>

void main()
{
int p;
float sum,avg,s;
printf("Enter how many processes : ");
scanf("%d",&p);

int bt[p],at[p],st[p],wt[p],ft[p],tat[p],pid[p],pr[p];

for(int i=0;i<p;i++)
{
pid[i]=i+1;
printf("Enter Burst time for process : %d\n",i+1);
scanf("%d",&bt[i]);
printf("Enter Arrival time for process : %d\n",i+1);
scanf("%d",&at[i]);
printf("Enter Priority for process : %d\n",i+1);
scanf("%d",&pr[i]);
}

for(int i=0;i<p-1;i++)
{
for(int j=i+1;j<p;j++)
{
if (at[j]<at[i]) 
{
// swap for at
int temp=at[i];
at[i]=at[j];
at[j]=temp;

// swap for bt
temp=bt[i];
bt[i]=bt[j];
bt[j]=temp;

// swap for pid
temp=pid[i];
pid[i]=pid[j];
pid[j]=temp;

// swap for pr
temp=pr[i];
pr[i]=pr[j];
pr[j]=temp;
}
}
}
//  swap for priority
for(int i=1;i<p;i++)
{
for(int j=i+1;j<p;j++)
{
if (pr[j]>pr[i])
{
// swap for pr
int temp=pr[i];
pr[i]=pr[j];
pr[j]=temp;

// swap for bt
 temp=bt[i];
bt[i]=bt[j];
bt[j]=temp;
// swap for at
 temp=at[i];
at[i]=at[j];
at[j]=temp;

// swap for pid
temp=pid[i];
pid[i]=pid[j];
pid[j]=temp;
}
}
}

// calculate start time
int time = 0;
for (int i = 0; i < p; i++) {
     if (time < at[i]) {
            time = at[i]; // cpu is idle
}
st[i] = time;
time += bt[i];
ft[i] = time;
}

// calculate finish time
for(int i=0;i<p;i++){
ft[i]=st[i]+bt[i];
}

//calculate tat and wt
for (int i = 0; i < p; i++) {
        wt[i] = st[i] - at[i];
        tat[i] = ft[i]-at[i];
}

printf("\nProcess\tBT\tAT\tPriority\n");
for(int i=0;i<p;i++)
	printf("P%d\t%d\t%d\t%d\n",pid[i],bt[i],at[i],pr[i]);
	
//output
printf("\nProcess\tBT\tAT\tST\tWT\tFT\tTAT\n");
for(int i=0;i<p;i++)
	printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",pid[i],bt[i],at[i],st[i],wt[i],ft[i],tat[i]);
	
// gantt chart

printf("\n*** Gantt Chart ***\n|");
for (int i = 0; i < p; i++) {
     printf("  P%d  |", pid[i]);
}
//printf("\n");
printf("\n%d", st[0]);
for (int i = 0; i < p; i++) {
        printf("    %d", ft[i]);
}
printf("\n");
for(int i=0;i<p;i++)
{
sum+=wt[i];
 avg=sum/p;
}
printf("AVG WT:%.2f\n",avg);

for(int i=0;i<p;i++)
{
s+=tat[i];
avg=s/p;
}
printf("AVG TAT:%.2f\n",avg);
}
