#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<time.h>

#define score
#define no_of_delieveries 36

struct player{
    int p_score;
    int p_out;
}

int main(){
    player p1,p2;
    p1.p_score = 0;
    p1.p_out = 0;

    p2.p_score = 0;
    p2.p_out = 0;

    return 0;
}
