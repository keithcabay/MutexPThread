#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int counter = 0;
pthread_mutex_t mutex;

void* thread1(){
    pthread_mutex_lock(&mutex);
    counter++;
    printf("Thread 1 wrote to counter: %d\n", counter);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void* thread2(){
    pthread_mutex_lock(&mutex);
    printf("Thread 2 reads counter: %d\n", counter);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main(){
    pthread_t t1, t2;

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&t1, NULL, thread1, NULL);
    pthread_create(&t2, NULL, thread2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}