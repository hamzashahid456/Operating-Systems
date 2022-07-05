#include<stdio.h>

void main(){

int len, wid, height;

printf("Enter Length: ");
scanf("%d",&len);

printf("Enter Width: ");
scanf("%d",&wid);

printf("Enter Height: ");
scanf("%d",&height);

int vol = len*wid*height;

printf("The Volume of paralleepiped is: %d", vol);


}
