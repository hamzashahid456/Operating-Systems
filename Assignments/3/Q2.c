#include <stdlib.h> /* needed to define exit() */
#include <unistd.h> /* needed for fork() */
#include <sys/wait.h> /* needed for wait() */
#include <stdio.h> /* needed for printf() */
int main(int argc, char **argv) {
int pid; /* process ID */
pid = fork();
if (pid == -1) {
    perror("Error");
}
else if(pid == 0){
    // from child
    printf("In child \n child's process id is: %d\n",getpid());
}
else{
    // from parent
    pid_t cpid;
    cpid = wait(NULL);
    printf("In parent\n parent's process id is: %d and child's process id is: %d\n", getpid(),cpid);
}
sleep(1);
exit(0);
}
