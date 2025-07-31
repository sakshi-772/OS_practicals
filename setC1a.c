#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
void asort(int a[],int n);
void dsort(int a[],int n);
void main()
{
int n,i,j,key;
pid_t pid;
printf("enter size of the array:");
scanf("%d",&n);
int a[n];
printf("enter the elements to the array\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
pid=fork();
if(pid<0)
{
printf("fork failed\n");
}
else if (pid==0)
{
int status;
wait(NULL);
WIFEXITED(status);
printf("\nchild process id=%d\n",getpid());
printf("child process sorts array into descending order..\n");
dsort(a,n);
printf("descending array:");

for(i=0;i<n;i++)
{
printf("%d ",a[i]);
}
}
else
{
printf("parent process id=%d\n",getpid());
printf("parent process sorts array into descending order..\n");
asort(a,n);
printf("ascending array:");

for(i=0;i<n;i++)
{
printf("%d ",a[i]);
}
}

}
void asort(int a[],int n)
{
int i,j;
for(i=0;i<n;i++)
{
for(j=0;j<n-i-1;j++)
{
if(a[j]>a[j+1])
{
int max=a[j];
a[j]=a[j+1];
a[j+1]=max;
}
}
}
}
void dsort(int a[],int n)
{
int i,j;
for(i=0;i<n;i++)
{
for(j=0;j<n-i-1;j++)
{
if(a[j]<a[j+1])
{
int max=a[j];
a[j]=a[j+1];
a[j+1]=max;
}
}
}
}

