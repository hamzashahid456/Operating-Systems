#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    //functions prototypes
    void f1(void);
    void f2(void);
    void f3(void);
    atexit(f1);
    atexit(f2);
    atexit(f3);
    printf("Getting ready to exit\n");
    exit(0);
}
// function definitions
void f1(void)
{
    printf("In f1\n");
}
void f2(void)
{
    printf("In f2\n");
}
void f3(void)
{
    printf("In f3\n");
// abort();
}
