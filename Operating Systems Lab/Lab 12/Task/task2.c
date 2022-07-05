#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

#define M 3
#define K 2
#define N 3
#define MAX_THREAD 4

int A[M][K] = {{1, 4},{2, 5},{3, 6}};
int B[K][N] = {{8, 7, 6},{5, 4, 3}};
int C[M][N];


void* prod(int i, int j, int k){
    // Multiplying first and second matrices and storing it in third matrice
//   for (int i = 0; i < 3; ++i) {
//      for (int j = 0; j < 3; ++j) {
//         for (int k = 0; k < 2; ++k) {
//            C[i][j] += A[i][k] * B[k][j];
//         }
//      }
//   }

    C[i][j] += A[i][k] * B[k][j];
    

}

void show(){
    // function to display the matrix
   printf("\nOutput Matrix:\n");
   for (int a = 0; a < 2; ++a) {
      for (int b = 0; b < 2; ++b) {
         printf("%d  ", C[a][b]);
         if (b == 2 - 1)
            printf("\n");
      }
   }
}

int main(){

    int i=0, j=0, k=0;   

    // declaring four threads
    pthread_t threads[MAX_THREAD];
 
    // Creating four threads, each evaluating its own part
    for (int a = 0; a < MAX_THREAD; a++) {
//        int* p;
        pthread_create(&threads[a], NULL, prod,(i,j,k) );
        pthread_join(threads[a], NULL);
        i++;
        j++;
        k++;
    }
 


    show();
    return 0;
}
