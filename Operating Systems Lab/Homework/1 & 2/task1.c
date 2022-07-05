#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char* argv[]){
    char t[10];
    

    char *filename = argv[1];
    int fd = open(filename, O_RDONLY);
    while( read(fd, t, sizeof(t)-1 ) ){
            char b[5];
            int count = 0;

            while( read(fd, b, sizeof(b)-1 ) ){
                if( t == b ){ count++; }
            }
            printf("\n%d\n", count);
    }


    return 0;
}
