#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
printf("enter DEL to stop the process\n");

pid_t pid;
int retnice;
pid=fork();
if (pid==0)
{
retnice=nice(-5);
printf("child gets higher priority %d\n",retnice);
sleep(1);
}
else
{
retnice=nice(6);
printf("parent gets lower CPU priority %d\n",retnice);
sleep(1);
}
}

