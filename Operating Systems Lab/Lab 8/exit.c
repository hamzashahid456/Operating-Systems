#include <stdio.h>
#include <stdlib.h>
void f(){
printf("Executing f\n");
exit(0);
}

int main(){
f();
printf("Back from f\n");
}
