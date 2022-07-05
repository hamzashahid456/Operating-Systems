#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){

int f = fork();
if(f == 0){
    sleep(3);
}
else{
    int f2 = fork();
    if(f2 == 0){
        // child workspace
        sleep(3);
        printf("PID is: %d and parent PID is: %d",getpid(),getppid());
    }
    else{
        // parent workspace
        int f3 = fork();
        if(f3 == 0){ // child workspace
            sleep(3);
            printf("PID is: %d and parent PID is: %d",getpid(),getppid());
        }   
        else{  // parent workspace
            int f4 = fork();
        }
    }
}

}
