#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char* argv[]){
    char s[5];
    char t[5];

    int p = fork();
    if(p == 0){
        printf("Enter Number: ");
        scanf("%c",s);

        size_t length = strlen(s);

        char *filename = argv[1];
        int fd = open(filename, O_WRONLY | O_CREAT, 0666);
        write(fd, s, length);

        close(fd);
    }
    else{
        wait(NULL);
        int fd = open("./intVal.txt",O_RDONLY);
        if(argc == -1){
            printf("File doesn't exist");
        }
        read(fd, t, sizeof(t)-1 );

        int val = atoi(t);
        printf("Number is: %d\n", val);

        // finding factorial
        int f = 1;
        for(int i=1; i<val+1; i++){
            f = f * i;
        }
        printf("Factorial is: %d\n", val);
        
        
        
    }
    return 0;
}
