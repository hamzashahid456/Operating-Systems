// CPP program to illustrate default Signal Handler
#include<stdio.h>
#include<signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
int main()
{
    signal(SIGINT, SIG_DFL);
    while (1)
    {
        printf("hello world\n");
        sleep(1);
    }
    return 0;
}
