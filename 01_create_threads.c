////////////////////////////////////////////////////////////
//
//  Create Threads
//
////////////////////////////////////////////////////////////

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


void delay_in_msec(int max)
{
  unsigned delay = (int) (rand() / (double) RAND_MAX + 1) * max;
  usleep(delay);
}

void* work(void* v) {
    for (int i = 0; i < 25; i++) {
        const char* message = (const char*) v;
        printf("%s", message);
        fflush(stdout);
        delay_in_msec(100000);
    }
    return 0;
}

int main(void) {

    pthread_t t1, t2, t3, t4;

    pthread_create(&t1, 0, work, (void*) "1");
    pthread_create(&t2, 0, work, (void*) "2");
    pthread_create(&t3, 0, work, (void*) "3");
    pthread_create(&t4, 0, work, (void*) "4");

    pthread_join(t1, 0);
    pthread_join(t2, 0);
    pthread_join(t3, 0);
    pthread_join(t4, 0);
}
