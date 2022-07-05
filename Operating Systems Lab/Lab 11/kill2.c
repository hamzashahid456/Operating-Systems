#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
int main(int argc, char *argv[])
{
    printf("My PID: %d\n",getpid());
    printf("Hello\n");
    sleep(5);
    kill(getpid(),SIGSEGV); // An invalid access to storage.
    return 0;
}
