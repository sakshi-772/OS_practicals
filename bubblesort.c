#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
void bubblesort(int arr[],int n);
void bubblesort(int arr[],int n)
{
int temp,i,j;
for(int i=0;i<n-1;i++)
{
for(int j=0;j<n-i-1;j++)
{
if(arr[j]>arr[j+1])
{
temp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
}
}
}
}
int main()
{
pid_t pid;
int i;
int n,arr[30];
printf("enter how many no to be sort:\n");
scanf("%d",&n);
printf("enter the no for sorting\n");
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}

pid=fork();
if (pid<0)
{
printf("fork failed");
exit(1);
}
else if (pid==0)
{
printf("child process id=%d\n",getpid());
sleep(2); 
printf("child process is done\n");
exit(1);
}
else
{
wait(NULL);
printf("parent process id=%d\n",getpid());
printf("parent process sorting array:\n");
bubblesort(arr,n);
for(i=0;i<n;i++)
{
printf("%d  ",arr[i]);
}
}
return 0;
}

