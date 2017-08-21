#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t ma;
pthread_mutex_t mb;

void* a(void* p) {
    int i = 0;
    while(i < 10) {
        pthread_mutex_lock(&ma);
        printf("A\n"); 
        i++;
        pthread_mutex_unlock(&mb);
    }
    return NULL;
}

void* b(void* p) {
    int i = 0;
    while(i < 10) {
        pthread_mutex_lock(&mb);
        printf("B\n"); 
        i++;
        pthread_mutex_unlock(&ma);
    }
    return NULL;
}

int main() {
    pthread_t ta, tb;

    pthread_mutex_init(&ma, NULL);
    pthread_mutex_init(&mb, NULL);
    pthread_mutex_lock(&mb);

    pthread_create(&ta, NULL, a, NULL);
    pthread_create(&tb, NULL, b, NULL);

    pthread_join(ta, NULL);
    pthread_join(tb, NULL);

    pthread_mutex_destroy(&ma);
    pthread_mutex_destroy(&mb);
    return 0;
}
