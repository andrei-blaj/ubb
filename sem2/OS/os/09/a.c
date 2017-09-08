#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define H 20000
#define W 20000
#define T 100

char** a;
unsigned long long int sum = 0;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void* f(void* p) {
    int k = *(int*)p;
    int i, j;
    unsigned long long int t = 0;

    free(p);
    for(i=k; i<H; i+=T) {
        for(j=0; j<W; j++) {
            t += a[i][j];
        }
    }

    pthread_mutex_lock(&mtx);
    sum += t;
    pthread_mutex_unlock(&mtx);
    return NULL;
}

int main() {
    int i, j;
    pthread_t t[T];
    int* arg;

    a = (char**)malloc(H*sizeof(char*));
    for(i=0; i<H; i++) {
        a[i] = (char*)malloc(W*sizeof(char));
        for(j=0; j<W; j++) {
            a[i][j] = 1;
        }
    }
    printf("allocated\n");

    for(i=0; i<T; i++) {
        arg = (int*)malloc(sizeof(int));
        *arg = i;
        pthread_create(&t[i], NULL, f, arg);
    }

    for(i=0; i<T; i++) {
        pthread_join(t[i], NULL);
    }

    for(i=0; i<W; i++) {
        free(a[i]);
    }
    free(a);

    printf("%lld\n", sum);

    return 0;
}

