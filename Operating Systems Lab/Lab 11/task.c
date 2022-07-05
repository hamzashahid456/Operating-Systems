#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include<sys/types.h>

void handle_sigint(){
    printf("I am not gonna sleep 😏️ \n");
}

int main(){
    int pid = fork(); 
   
    if(pid == 0){
        signal(SIGINT, handle_sigint );
        while(1){
            sleep(1);
        }
    }
    else{
        sleep(5);
        for(int i=0; i<5; i++){
            kill(pid,SIGINT);
            sleep(1);
        }
    }    
    
    return 0;
}
