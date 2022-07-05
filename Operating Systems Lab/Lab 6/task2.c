#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int i=0;
    char inp[50];
    while(i==0){
        printf("Enter Command: \n");
        scanf("%s",inp);
        if(strcmp(inp,"list")==0){
            system("ls");
        }
        else if(strcmp(inp,"showprocess")==0){
            system("ps");           // ps -au for detail                    ls -l       fget method for multiple strings
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

























//int main(int argc, char* argv[]){
//    int i=0;
//    string inp;
//    while(i=1){
//        printf("Enter Command: \n");
//        scanf("%s",&inp);
//        if(argc > 1 ){
//            if(strcmp(argv[1],"list")==0){
//                system("ls");
//            }
//            else if(strcmp(argv[1],"showprocess")==0){
//                system("ps");
//            }
//            else if(strcmp(argv[1],"clearscreen")==0){
//                system("clear");
//            }
//            else if(strcmp(argv[1],"exit")==0){
//                system("exit");
//                  i = 1;
//            }
//
//        }
//    }
//
//}
