#include <unistd.h>
#include <stdio.h>
#include<signal.h>
#include <sys/types.h>
int main()
{
    int pid;
    pid = fork();
    if(pid == 0)
    {
        printf("I am the Child with PID = %d\n", getpid());
        kill(getppid(),SIGTERM);
        sleep(120);
    }
    else
    {
        printf("Parent of = %d\n", pid);
        printf("I am the Parent with PID = %d\n",getpid());        
    }
}
