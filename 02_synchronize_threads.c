////////////////////////////////////////////////////////////
//
//  Synchronize Threads
//
////////////////////////////////////////////////////////////

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t lock;


void delay_in_msec(int max)
{
  unsigned delay = (int) (rand() / (double) RAND_MAX + 1) * max;
  usleep(delay);
}

typedef struct {
    const char* id;
    pthread_mutex_t* pLock;
} PARAMS;

void* work(void* v) {
    PARAMS* params = (PARAMS*) v;
    pthread_mutex_lock(params->pLock);

    for (int i = 0; i < 25; i++) {
        printf("%s", params->id);
        fflush(stdout);
        delay_in_msec(1000);
    }
    pthread_mutex_unlock(params->pLock);

    return 0;
}


int main(void) {

    pthread_t t1, t2, t3, t4;
    pthread_mutex_t lock1, lock2, lock3, lock4;

    pthread_mutex_init(&lock1, 0);
    pthread_mutex_init(&lock2, 0);
    pthread_mutex_init(&lock3, 0);
    pthread_mutex_init(&lock4, 0);

    pthread_create(&t1, 0, work, (void*) &(PARAMS){"1", &lock1});
    pthread_create(&t2, 0, work, (void*) &(PARAMS){"2", &lock1});
    pthread_create(&t3, 0, work, (void*) &(PARAMS){"3", &lock2});
    pthread_create(&t4, 0, work, (void*) &(PARAMS){"4", &lock2});

    pthread_join(t1, 0);
    pthread_join(t2, 0);
    pthread_join(t3, 0);
    pthread_join(t4, 0);
}
