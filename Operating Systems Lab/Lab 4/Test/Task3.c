#include<stdio.h>
#include<stdlib.h>

int main(){
system("mkdir Test");
system("touch test1.txt test2.txt");
system("tree Test");
system("rm -r Test");
return 0;
}
