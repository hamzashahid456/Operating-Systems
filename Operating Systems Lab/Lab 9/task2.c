#include<stdio.h>
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
    int fd = open(path, O_RDONLY);

    //for output file
    char *filename = argv[2];
    int fd2 = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0666);

    if(argc == -1){
        printf("File doesn't exist");
    }
    
    int v = 1;  //for using it in while loop

    char buffer[10];    //buffer and it's size

    while(v > 0){
        //for reading
        v = read(fd, buffer, sizeof(buffer)-1 );

        //for  writting
        size_t length = strlen(buffer);
        write(fd2, buffer, length);
    }
    //for closing both opened files
    close(fd);
    close(fd2);
    return 0;
}
