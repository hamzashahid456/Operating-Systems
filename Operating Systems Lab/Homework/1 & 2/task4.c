#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>

int main(){

    int p = fork();
    for(int i=0;i<7;i++){
        if( p == 0){
            printf("child process id is: %d and parent pid is: %d\n",getpid(),getppid() );
            
            return 0;
        }
        p = fork();
    }
    for(int i=0;i<5;i++){ wait(NULL); }
    

    return 0;
}
