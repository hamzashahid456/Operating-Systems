#include<stdio.h>   
#include<stdlib.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

int main(){
    char inp[20];    // for taking input from user
    int pid; // for storing fork() return
    int pfd[2]; // for pipe file descriptors
    int pfd2[2];    // for secon pipe
    char aString[20]; // Temporary storage

    pipe(pfd); // create first pipe
    pipe(pfd2); // creating second pipe
    pid = fork(); // create child process

    

    while(1){
        if (pid == 0){ // For child

            close(pfd[0]);  // closing reading pipe1
            close(pfd2[1]); // closing writting pipe2

            read(pfd2[0], aString, sizeof(aString));
            printf("p1 says: %s\n", aString);

            printf("p2: ");
            scanf("%s", aString);

            write(pfd[1], aString, sizeof(aString) ); // Write onto pipe
            
        }
        else{ // For parent

            close(pfd[1]);  //closing writting pipe1
            close(pfd2[0]); //closing reading pipe2

            printf("p1: ");
            scanf("%s", aString);

            write(pfd2[1], aString, sizeof(aString)); // Write onto pipe

            read(pfd[0], aString, sizeof(aString)); // Read from pipe
            printf("\np2 says: %s\n", aString);          
            
        }
    }

    return 0;
}
