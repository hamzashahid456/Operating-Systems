#include<stdio.h>   //using pipes
#include<stdlib.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>


int main(int argc, char* argv[]){
    //for input file
    char *path = argv[1];

    int pid, pfd[2];

    pipe(pfd);  // create pipe
    pid = fork();   // creating processes

    int fd = open(path, O_RDONLY);

    //for output file
    char *filename = argv[2];
    int fd2 = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0666);

    if(argc == -1){
        printf("File doesn't exist");
    }

    char buffer[10];    //buffer and it's size

    while( read(fd, buffer, 1 ) ){
 
        if(pid == 0){
            close (pfd[0]);    // closing the reading process of pipe

            //for writting into pipe
            write(pfd[1], buffer, 1);
        }
        
        else{
            wait(NULL);
            close(pfd[1]); //closing the writing process of pipe for parent

            read(pfd[0], buffer, 1 );           


            size_t length = strlen(buffer);
            write(fd2, buffer, length-1 );
        }
    }
    //for closing both opened files
    close(fd);
    close(fd2);
    return 0;
}
