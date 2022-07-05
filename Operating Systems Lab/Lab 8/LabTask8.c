#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>      // for fork() function
#include<sys/wait.h>    // for using wait function

void proc(){
    printf("\nJob Done\n");
}

int main(){
    atexit(proc);   // for printing job done we use atexit function
    int arr[10];

    for(int i=0; i<10; i++){
        arr[i] = rand()%100+1;  // inserting random numbers in array
    }

    // unsorted array
    printf("Unsorted array : \n");
    for(int i=0; i<10; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");


    int p = fork();     // generating process
    
    if(p == 0){
        int max = arr[0];
        int min = arr[0];
        // for finding maximum
        for(int i=0; i<10; i++){
            if(arr[i] > max){
                max = arr[i];
            } 
            //  for finding minimum
            if(arr[i] < min){
                min = arr[i];
                sleep(1);
            }
        }
        printf("\nMaximum number is: %d\n",max);
        printf("\nMinimum number is: %d\n",min);
    }
    else{
        int a;
        // here we will sort in decending order
 
        for (int i = 0; i < 10; ++i) 
        {
            for (int j = i + 1; j < 10; ++j) 
            {
                if (arr[i] < arr[j]) {
                    a = arr[i];
                    arr[i] = arr[j];
                    arr[j] = a;
                }
            }
        }
        
        wait(NULL); // parent will wait for child to done its process

        // sorted array
        printf("\nSorted Array\n");
        for(int i=0; i<10; i++){
            printf("%d ",arr[i]);
        }
        printf("\n");


    }
}
