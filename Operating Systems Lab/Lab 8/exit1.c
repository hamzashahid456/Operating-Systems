#include <stdio.h>
#include <stdlib.h>
int main ()
{
    FILE * pFile;
    // pointer of type file
    pFile = fopen ("myfile.txt", "r");
    // opening the file in read-only mode
    if (pFile == NULL)
    {
    printf ("Error opening file");
    exit (1);
    }
    else
    {
    /* file operations here */
    printf("File is Opening here...");
    //exit(0);
}
return 0;
}
