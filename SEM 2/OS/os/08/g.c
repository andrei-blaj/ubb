#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

char turn = 'a';
pthread_mutex_t mtx;

void* a(void* p) {
    int i = 0;
    while(i < 10) {
        pthread_mutex_lock(&mtx);
        if(turn == 'a') {
            printf("A\n"); 
            i++;
            turn = 'b';
        }
        pthread_mutex_unlock(&mtx);
    }
    return NULL;
}

void* b(void* p) {
    int i = 0;
    while(i < 10) {
        pthread_mutex_lock(&mtx);
        if(turn == 'b') {
            printf("B\n"); 
            i++;
            turn = 'a';
        }
        pthread_mutex_unlock(&mtx);
    }
    return NULL;
}

int main() {
    pthread_t ta, tb;

    pthread_mutex_init(&mtx, NULL);

    pthread_create(&ta, NULL, a, NULL);
    pthread_create(&tb, NULL, b, NULL);

    pthread_join(ta, NULL);
    pthread_join(tb, NULL);

    pthread_mutex_destroy(&mtx);
    return 0;
}
