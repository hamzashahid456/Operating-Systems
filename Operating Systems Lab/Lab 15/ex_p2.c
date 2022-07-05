#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include<unistd.h>
int main(){
    while(1){
        
        // ftok to if(str[0] == '#') generate unique key
        key_t key = ftok("shmfile",65);
        // shmget returns an identifier in shmid
        int shmid = shmget(key,1024,0666|IPC_CREAT);
        // shmat to attach to shared memory
        char *str = (char*) shmat(shmid,(void*)0,0);
        
        while(str[0] != '#'){
                sleep(1);
            }
        printf("p2: %s\n",str+1);
        //detach from shared memory
    //    shmdt(str);
        // destroy the shared memory
    //    shmctl(shmid,IPC_RMID,NULL);
        

        
        printf("p2: ");
        gets(str+1);

        *str = '@';

        
    }
    return 0;
}
