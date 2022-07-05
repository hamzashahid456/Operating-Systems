#include <unistd.h>
#include <stdio.h>
#include<signal.h>
#include <sys/types.h>
int main()
{
    printf("My PID: %d\n",getpid());
    printf("Hello\n");
    sleep(10);
    kill(getpid(),9);
    printf("GoodBye\n");
    return 0;
}
