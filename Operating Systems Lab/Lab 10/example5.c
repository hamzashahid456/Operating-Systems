#include<unistd.h>
#include<string.h>
#include<stdio.h>
/* This program constructs "ls | wc ", through a pipe:
* stdin ---> ls ---> [pipe] ---> wc ---> stdout
* No arguments -- just run it.
*/
int main()
{
    int pid;
    int pfd[2]; //Pipe descriptor
    pipe(pfd);
    pid=fork();
    if(pid==0)
    {
        /* Don't need the write end of the pipe in this process */
        close(pfd[1]);
        /* Copy the read end of the pipe (pfds[0]) into stdin's file descriptor (file descriptor 0). The old
        stdin is closed automatically first. */
        dup2(pfd[0], 0);
        close(pfd[0]);
        execlp("wc","wc", NULL);
    }
    else
    {
        /* Don't need the read end of the pipe in this process */
        close(pfd[0]);
        /* Copy the write end of the pipe (pfds[1]) into stdout's file descriptor (file descriptor 1). The old
        stdout is closed automatically first. */
        dup2(pfd[1], 1);
        close(pfd[1]);
        execlp("ls", "ls", NULL);
    }
}
