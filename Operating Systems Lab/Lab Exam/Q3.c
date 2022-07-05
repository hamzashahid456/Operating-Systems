#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]){
    printf("Arguments are: %s\n",argv[1] );
    char* var1 = argv[1];
    system("mkdir backup");
    system("cp backup");
    
    
    return 0;
}
