#include <stdio.h>
void f(){
    printf("Executing f\n");
    return;
}
int main(){
    f();
    printf("Back from f\n");
}
