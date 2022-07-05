#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
//A null terminated array of character pointers
char *args[]={"./exec2",NULL};
execv(args[0],args);
/*All statements are ignored after execv() call as this whole
process(execDemo1.c) is replaced by another process (EXEC2.c)
*/
printf("Ending-----");
return 0;
}
