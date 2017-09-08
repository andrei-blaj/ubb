#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int n = 0;

void* f(void* p) {
    int k = 0;
    int* r = (int*)p;
    while(n < 1000) {
        n++;
        k++;
    }
    printf("%d cycled %d times\n", *r, k);
    free(p);
    return NULL;
}

int main() {
    int i;
    pthread_t t[10];
    int *a;

    for(i=0; i<10; i++) {
        a = (int*)malloc(sizeof(int)); 
        *a = i;
        pthread_create(&t[i], NULL, f, a);
    }

    for(i=0; i<10; i++) {
        pthread_join(t[i], NULL);
    }
    return 0;
}
