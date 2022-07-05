#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>

void *fact(void *n){

    char *nu;
    nu = (char *) n;
    
    int num = atoi(nu);

    int f = 1;
    for( int i=1; i < num+1; i++ ){
        f = f * i;    
    }
    printf("\nFactorial of %d is: %d\n", num, f);
}

int main(int argc, char* argv[]){

    pthread_t thread[argc-1];   

    for( int i=1; i < argc ; i++ ){

        int l = pthread_create( &thread[i] , NULL, fact, (void*)argv[i]);

        
    }  



    return 0;
}
