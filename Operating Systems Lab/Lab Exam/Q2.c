#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){
    

//    for(int i=0; i<3; i++){
        int p = fork();
        if(p==0){
            printf("Process ID is: %d\n",getpid() );
            
            int p4 = fork(); 
            if(p4==0) { printf("Process ID is: %d\n",getpid() ); }
            int p5 = fork();
            if(p5==0) { printf("Process ID is: %d\n",getpid() ); }
            int p6 = fork();
            if(p6==0) { printf("Process ID is: %d\n",getpid() ); }
            
            

        }
        
        else{
            wait(NULL);
            printf("Parent process ID is: %d\n",getpid() );
            p = fork(); 
            if(p==0) { printf("Process ID is: %d\n",getpid() ); }
            p = fork();   
            if(p==0) { printf("Process ID is: %d\n",getpid() ); }
        }
//    }

    

    return 0;
}
