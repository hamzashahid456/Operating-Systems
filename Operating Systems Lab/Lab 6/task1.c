#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
    if(argc > 1 ){
        if(strcmp(argv[1],"list")==0){
            system("ls");
        }
        else if(strcmp(argv[1],"showprocess")==0){
            system("ps");
        }
        else if(strcmp(argv[1],"clearscreen")==0){
            system("clear");
        }

    }

}
