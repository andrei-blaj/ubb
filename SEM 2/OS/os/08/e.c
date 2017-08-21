#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int n = 0;

struct arg {
    int k;
    float f;
};

void* f(void* p) {
    int k = 0;
    struct arg* r = (struct arg*)p;
    while(n < 1000) {
        n++;
        k++;
    }
    printf("%d cycled %d times\n", r->k, k);
    free(p);
    return NULL;
}

int main() {
    int i;
    pthread_t t[10];
    struct arg *a;

    for(i=0; i<10; i++) {
        a = (struct arg*)malloc(sizeof(struct arg)); 
        a->k = i;
        a->f = 0.5f;
        pthread_create(&t[i], NULL, f, a);
    }

    for(i=0; i<10; i++) {
        pthread_join(t[i], NULL);
    }
    return 0;
}
