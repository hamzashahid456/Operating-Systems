#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>


void* threadz(){
    printf("Hello\n");
    pid_t tid = gettid();

    printf("The thread id: %d \n",  tid );
    pthread_exit(NULL);
}

int main(int argc, char *argv[]){

    int n = atoi(argv[1]);

    pthread_t thread[n];

    for(int i=0; i<n; i++){
        
        pthread_create(&thread[i],NULL,threadz,NULL);
        pthread_join(thread[i], NULL);
        
    }
    
    return 0;
}
