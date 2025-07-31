#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
void main()
{
pid_t pid;
pid=fork();
char *args[]={"./intsort.c",NULL};
if(pid==0)
{
 execv(args[0],args);
}
else
{
printf("i am parent process\n");
}
}

