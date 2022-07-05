#include<stdio.h>

int fact(int num){
int f = 1;
for(int i=1; i<num+1; i++){
f = f*i;
}
return f;
}

int main(){
int n;
printf("Enter Number: ");
scanf("%d",&n);
printf("The Factorial of %d is: %d",n,fact(n));
}
