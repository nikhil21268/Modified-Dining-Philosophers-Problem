#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t forks[5];
sem_t room;
sem_t sauce;
//sem_t sauce[2];
int numMeals[5];
int status[5];

void * philosopherFunc(void * philNo){
    int philosopherNum = *(int *)philNo;
    while(1){
        if(numMeals[philosopherNum]==1)
        {
            break;
        }
        sleep(1);
        sem_wait(&room);
        sem_wait(&sauce);
        printf("\nPhilosopher %d has the bowl !!", philosopherNum);
        sem_wait(&forks[(philosopherNum+1)%5]);
        sem_wait(&forks[philosopherNum]);

        numMeals[philosopherNum]++;
        printf("\nPhilosopher %d has eaten %d meals", philosopherNum, numMeals[philosopherNum]);
        status[philosopherNum] = 0;

        sleep(1);
        sem_post(&forks[(philosopherNum+1)%5]);
        sem_post(&forks[philosopherNum]);
        sem_post(&sauce);
        sem_post(&room);
        printf("\nPhilosopher %d has exited the room --", philosopherNum);
    }
    return 0;
    
}

int main(){

    int philNo[5];
    printf("\nStarting..\n");
    pthread_t thread_ids[5];
    sem_init(&room, 0, 2);
    sem_init(&sauce, 0, 2);

    for(int i = 0; i < 5; i++){
        sem_init(&forks[i], 0, 1);
        numMeals[i] = 0;
        status[i] = 1;
    }

    int i = 0;

    for(int i = 0; i < 5; i++){
        philNo[i] = i;
        pthread_create(&thread_ids[i], NULL, philosopherFunc, (void *)&philNo[i]);
    }

    for (int i = 0; i < 5; i++){
        pthread_join(thread_ids[i], NULL);
    }

}

