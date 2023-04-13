/*Implement wake and sleep system using c.*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition = PTHREAD_COND_INITIALIZER;
int is_sleeping = 0;

void* thread_func(void* arg) {
    int id = *(int*)arg;
    printf("Thread %d: starting\n", id);
    sleep(2);
    printf("Thread %d: waking up the system\n", id);
    pthread_mutex_lock(&mutex);
    is_sleeping = 0;
    pthread_cond_signal(&condition);
    pthread_mutex_unlock(&mutex);
    printf("Thread %d: done\n", id);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    int id1 = 1, id2 = 2;
    printf("Starting thread %d\n", id1);
    pthread_create(&thread1, NULL, thread_func, &id1);
    sleep(1);
    printf("Starting thread %d\n", id2);
    pthread_create(&thread2, NULL, thread_func, &id2);
    pthread_mutex_lock(&mutex);
    while (is_sleeping) {
        pthread_cond_wait(&condition, &mutex);
    }
    pthread_mutex_unlock(&mutex);
    printf("System has been woken up\n");
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
