#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <signal.h>


void sigHandler(){
    printf("[Child] Let me finish my work first\n");
}

int main(){
    int arr[10];
    for(int i=0; i<10; i++){    // for saving random numbers in array
        while(1){
            int r = rand()%70;
            if(r >= 20 && r <= 70){
                arr[i] = r;
                break;
            }
            else{continue;}
        }
        
    }


    int p = fork();
    if(p == 0){
        int avg=0;
        for(int i=0; i<10;i++ ){
            avg = avg + arr[i];
            sleep(1);
        }
        int a = avg/10;
        printf("Mean is: %d\n",a);
        

        // converting intger into string
        char ar[20];
        sprintf(ar,"%d",a);


        // ftok to generate unique key
        key_t key = ftok("shmfile",65);
        // shmget returns an identifier in shmid
        int shmid = shmget(key,1024,0666|IPC_CREAT);
        // shmat to attach to shared memory
        char *str = (char*) shmat(shmid,(void*)0,0);
        str = ar;


    }
    else{
        wait(5);
        signal(SIGINT, sigHandler);

    }
    
    return 0;
}
