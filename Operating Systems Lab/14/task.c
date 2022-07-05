#include<stdio.h>
#include <stdlib.h>

int main(){
    int x = 5, n;
    
    printf("Enter size of array: ");
    scanf("%d",&n);

    int *arr = (int*) malloc( n * sizeof(int) );

    printf("Enter values of array: \n");
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i] );
    }

    int y = 0;

    for(int i=0; i<n; i++){
        y = y + ( arr[i]*x );
    }
    
    printf("\nValue of y is: %d\n", y);

    return 0;
}
