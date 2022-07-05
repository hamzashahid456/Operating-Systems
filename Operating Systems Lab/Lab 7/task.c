#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc, char *argv[])
{
    //A null terminated array of character pointers
    char *args[]={"./Summation",NULL};

    int sum = 0;    

    for(int i=0; i< argc ; i++){
        printf("Argument List %d ------> %s\n", i, argv[i]);
    }

    execv(args[0],argv);

    printf("Ending-----");
    return 0;
}
