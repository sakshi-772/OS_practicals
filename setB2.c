#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
int pid=fork();
if(pid>0)
{
printf("parent process");
printf("ID=%d\n",getpid());
}
else if(pid==0)
{
printf("child process");
printf("ID=%d\n",getpid());
printf("Parent ID=%d\n",getppid());
sleep(5);
printf("child process");
printf("ID=%d\n",getpid());
printf("Parent ID=%d\n",getppid());
}
else{
printf("failed to create child process\n");
}
return 0;
}
