#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int i=0;
    char inp[50], ch;

    while(i==0){

        int i;

        printf("Enter a Command:\n");

        i = 0;

        ch = getchar ();

        while(ch!='\n'){
            inp[i] = ch;
            i++;
            ch = getchar();
        }
        inp[i] ='\0';


        if(strcmp(inp,"list")==0){
            system("ls");
        }
        else if(strcmp(inp,"showprocess")==0){
            system("ps");
        }
        else if(strcmp(inp,"showprocess indetail")==0){
            system("ps -au");
        }
        else if(strcmp(inp,"clearscreen")==0){
            system("clear");
        }
        else if(strcmp(inp,"exit")==0){
            system("exit");
            i = 1;
        }

    
    }

}
