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
    if( p == 0){
        printf("child process id is: %d and parent pid is: %d\n",getpid(),getppid() );
        p = fork();    
        if(p==0){
            printf("child process id is: %d and parent pid is: %d\n",getpid(),getppid() );
            p = fork();    
            if(p==0){
                printf("child process id is: %d and parent pid is: %d\n",getpid(),getppid() );
                p = fork();    
                if(p==0){
                  printf("child process id is: %d and parent pid is: %d\n",getpid(),getppid() );
                    p = fork();    
                    if(p==0){
                        printf("child process id is: %d and parent pid is: %d\n",getpid(),getppid() );
                        p = fork();    
                        if(p==0){
                            printf("child process id is: %d and parent pid is: %d\n",getpid(),getppid() );
                        }
                    } 
                 }
            }
        }
    }
    else{ 
        wait(NULL);        
    }
        

    

    return 0;
}
