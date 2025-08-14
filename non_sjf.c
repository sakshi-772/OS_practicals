
#include<stdio.h>
#include<string.h>
struct process
{
char pname[10];
int AT,BT,ST,FT,TT,WT;
}p[15];
struct process t;
int i,n,j,k,bt;
char GC[50];
void get_data()
{
printf("Enter number of processes");
scanf("%d",&n);
printf("Enter process details for %d processes",n);
for(i=0;i<n;i++)
{
printf("\nEnter Process name,arival time,cpu burst time");
scanf("%s %d %d",&p[i].pname,&p[i].AT,&p[i].BT);
}
}
void put_data()
{
printf("\nProcesses are as below");
printf("\nProcess name\t arival time\t cpu burst time");
for(i=0;i<n;i++)
{
printf("\n%s\t\t%d\t\t%d",p[i].pname,p[i].AT,p[i].BT);
}
}
void arrivalsort()
{
//struct process t;
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(p[i].AT > p[j].AT)
{
t=p[i];
p[i]=p[j];
p[j]=t;
}//if
}//for
}//for
}//arrivalsort
void burstsort()
{
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{if(p[i].BT > p[j].BT)
{
t=p[i];
p[i]=p[j];
p[j]=t;
}//if
}//for
}//for
}//burstsort
void avgTTWT()
{
int sumtt=0,sumwt=0;
for(i=0;i<n;i++)
{
p[i].TT=p[i].FT-p[i].AT;
p[i].WT=p[i].ST-p[i].AT;
sumtt=sumtt+p[i].TT;
sumwt=sumwt+p[i].WT;
}//for
printf("\n Process\tAT\tBT\tTT\tWT\tST\tFT\n");
for(i=0;i<n;i++)
{
printf("\n%s\t\t%d\t%d\t%d\t%d\t%d\t%d",p[i].pname,p[i].AT,p[i].BT,p[i].TT,p[i].WT,p[i].ST,p[i].FT);
}
printf("\nAverage turn around time=%d/%d",sumtt,n);
printf("\nAverage wait time=%d/%d",sumwt,n);
}//avgTTWT


void sjf()
{
char str[5];
int t,time=0;
strcat(GC,"0|");
if(p[0].AT>time)
{
strcat(GC,"CPUIDLE");
time=p[0].AT;
t=p[0].AT;
sprintf(str,"%d",time);
strcat(GC,str);
strcat(GC,"|");
}
p[0].ST=time;
strcat(GC,p[0].pname);
bt=p[0].BT;
k=0;
while(bt!=0)
{
strcat(GC," ");
bt--;
k++;
}//while
time=time+k;
p[0].FT=time;
sprintf(str,"%d",time);
strcat(GC,str);
burstsort();
for(i=0;i<n;i++)
{
if(p[i].FT>0)
continue;
strcat(GC,"|");
if(p[i].AT > time)
{
strcat(GC,"CPUIDLE");
time=p[i].BT;
sprintf(str,"%d",time);
strcat(GC,str);
strcat(GC,"|");
}//if
p[i].ST=time;
strcat(GC,p[i].pname);
bt=p[i].BT;
k=0;
while(bt!=0)
{
strcat(GC," ");
bt--;
k++;
}//while
time=time+k;
p[i].FT=time;
sprintf(str,"%d",time);
strcat(GC,str);
}//for
printf("\nGantt Chart\n");
puts(GC);
avgTTWT();
}//sjf
int main()
{
get_data();
put_data();
arrivalsort();
printf("\nProcesses after sorting on arrival time\n");
put_data();

sjf();
}
