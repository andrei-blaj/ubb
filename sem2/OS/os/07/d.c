#include <stdio.h>
#include <pthread.h>

int n = 0;

void* f(void* p) {
    int k = 0;
    while(n < 1000) {
        n++;
        k++;
    }
    printf("%lu cycled %d times\n", (unsigned long int)pthread_self(), k);
    return NULL;
}

int main() {
    int i;
    pthread_t t[10];

    for(i=0; i<10; i++) {
        pthread_create(&t[i], NULL, f, NULL);
    }

    for(i=0; i<10; i++) {
        pthread_join(t[i], NULL);
    }
    return 0;
}
