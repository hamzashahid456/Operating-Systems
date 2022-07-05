#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(void)
{
int i, pid;
printf("I am Parent with PID: %d\n", getpid());
pid= fork();
if(pid> 0)
//Parent
{
sleep(60);
}
else if(pid ==0) //child
{
exit(0);
}
