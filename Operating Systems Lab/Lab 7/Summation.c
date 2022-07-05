#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc, char *argv[])
{
    int sum = 0;

    for(int i=1; i<argc; i++){
        sum = sum + atoi(argv[i]);    // atoi(string) to convert string into int
    }
    
    printf("Summation is: %d", sum);

    return 0;
}
