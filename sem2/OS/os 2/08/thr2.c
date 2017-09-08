#include <stdio.h>
#include <pthread.h>
#include <math.h>

int counter = 0;

pthread_mutex_t mtx;

void* f(void* p) {
    int i;
    for(i=0; i<10000000; i++) {
        pthread_mutex_lock(&mtx);
        counter++;
        pthread_mutex_unlock(&mtx);
    }
    return NULL;
}

int main() {
    pthread_t t[100];
    int i;

    pthread_mutex_init(&mtx, NULL);

    for(i=0; i<100; i++) {
        pthread_create(&t[i], NULL, f, NULL);
    }

    for(i=0; i<100; i++) {
        pthread_join(t[i], NULL);
    }

    pthread_mutex_destroy(&mtx);

    printf("%d\n", counter);

    return 0;
}
