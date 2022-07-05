#include <unistd.h>
#include <sys/types.h> /* Primitive System Data Types */
#include <errno.h>
/* Errors */
#include <stdio.h>
#include <stdlib.h>
/* Input/Output */
/* General Utilities */
#include <pthread.h> /* POSIX Threads */
#include <string.h>
/* String handling */
// prototype for thread routine
void print_message_function ( void *ptr );
/*struct to hold data to be passed to a thread this shows
how multiple data items can be passed to
a thread */
struct thread_data
{
    int x;
    int y;
    int z;
};
int main()
{
    pthread_t thread1; /* thread variables */
    struct thread_data Omar;
    /* initialize data to pass to thread 1 */
    Omar.x=1;
    Omar.y=2;
    Omar.z=3;
    pthread_create(&thread1, NULL, (void *) &print_message_function,
    (void *) &Omar);
    pthread_join(thread1, NULL);
    exit(0);
}
void print_message_function ( void *ptr )
{
    struct thread_data *my_data;
    /* type cast to a pointer to thread_data */
    my_data = (struct thread_data *) ptr;
    printf("X:%d,Y:%d,Z: %d\n", my_data->x, my_data->y,my_data->z);
    pthread_exit(0); /* exit */
}

