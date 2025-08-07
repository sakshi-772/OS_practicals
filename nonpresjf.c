#include<stdio.h>
#include<stdlib.h>
void main()
{
int p;
float avg,sum,s;
printf("enter how many processes\n");
scanf("%d",&p);
int *bt=(int *)malloc(p * sizeof(int));
int *at=(int *)malloc(p * sizeof(int));
int *st=(int *)malloc(p * sizeof(int));
int *tat=(int *)malloc(p * sizeof(int));
int *wt=(int *)malloc(p * sizeof(int));
int *ft=(int *)malloc(p * sizeof(int));
int *pid=(int *)malloc(p * sizeof(int));

for(int i=0;i<p;i++)
{
pid[i]=i+1;
printf("enter bt for process %d\n",i+1);
scanf("%d",&bt[i]);
printf("enter at for process %d\n",i+1);
scanf("%d",&at[i]);
}
for(int i=0;i<p;i++)
{
for(int j=i+1;j<p;j++)
{
if(at[j]<at[i]||at[i]==at[j] && bt[j]<bt[i])
{
int temp=at[i];
at[i]=at[j];
at[j]=temp;

temp=bt[i];
bt[i]=bt[j];
bt[j]=temp;

temp=pid[i];
pid[i]=pid[j];
pid[j]=temp;

}
}
}

for(int i=1;i<p;i++)
{
for(int j=i+1;j<p;j++)
{
if(bt[j]<bt[i])
{
int temp=at[i];
at[i]=at[j];
at[j]=temp;

temp=bt[i];
bt[i]=bt[j];
bt[j]=temp;

temp=pid[i];
pid[i]=pid[j];
pid[j]=temp;

}
}
}
//calculate start time
int time=0;
for(int i=0;i<p;i++)
{
if(time<at[i])
{
time=at[i];  //cpu at idle state
}
st[i]=time;
time+=bt[i];
ft[i]=time;
}
//calculate finish time
for(int i=0;i<p;i++)
{
ft[i]=st[i]+bt[i];
}
//calculate TAT & WT
for(int i=0;i<p;i++)
{
wt[i]=st[i]-at[i];
tat[i]=ft[i]-at[i];
}

//output

printf("\nProcess\tBt\tAt\tSt\tWt\tFt\tTAT\n");
for(int i=0;i<p;i++)
{
printf("\nP%d\t%d\t%d\t%d\t%d\t%d\t%d\n",pid[i],bt[i],at[i],st[i],wt[i],ft[i],tat[i]);
}
//gant chart
printf("\n***Gantt Chart***\n");
for(int i=0;i<p;i++)
{
printf("P%d |",pid[i]);
}

printf("\n%d",st[0]);
for(int i=0;i<p;i++)
{
printf("  %d",ft[i]);
}
printf("\n");
//avg WT
for(int i=0;i<p;i++)
{
sum+=wt[i];
}
avg=sum/p;
printf("Avg Wt:%.2f\n",avg);
//avg tat
for(int i=0;i<p;i++)
{
s+=tat[i];
}
avg=s/p;
printf("Avg Wt:%.2f\n",avg);
}
