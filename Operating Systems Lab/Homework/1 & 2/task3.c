#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>

void *factors(void *n){

    char *nu;
    nu = (char *) n;
    
    int num = atoi(nu);

    printf("\nFactors of %d are: ", num);
    for( int i=1; i < num+1; i++ ){
        if( num % i == 0 ){ printf(" %d ",i); }
    }
    
}

int main(int argc, char* argv[]){

    pthread_t thread[argc-1];   

    for( int i=1; i < argc ; i++ ){

        int l = pthread_create( &thread[i] , NULL, factors, (void*)argv[i]);

        
    }  

    for(int i=1; i<argc; i++){
        pthread_join(thread[i],NULL);
    }   



    return 0;
}
