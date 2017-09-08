#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define T 1234
#define A 1000000

int a[A];

void* f(void* p) {
    int k = (int)p;
    int i;
    for(i=k; i<A; i+=T) {
        a[i] = 1;
    }
    return NULL;
}

int main() {
    int i, sum;
    pthread_t t[T];
    for(i=0; i<A; i++) {
        a[i] = 0;
    }
    for(i=0; i<T; i++) {
        pthread_create(&t[i], NULL, f, (void*)i);
    }
    for(i=0; i<T; i++) {
        pthread_join(t[i], NULL);
    }
    sum = 0;
    for(i=0; i<A; i++) {
        sum += a[i];
    }
    printf("%d %d\n", sum, A);
    return 0;
}
