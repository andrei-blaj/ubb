#include <stdio.h>
#include <pthread.h>
#include <math.h>

void* f1(void* p) {
    int i, j;
    double r = 1000;
    for(i=0; i<10; i++) {
        for(j=0; j<100000; j++) {
            r = sqrt(r+j);
        }
        printf("F1 %lf\n", r);
    }
    return NULL;
}

void* f2(void* p) {
    int i, j;
    double r = 1000;
    for(i=0; i<10; i++) {
        for(j=0; j<100000; j++) {
            r = sqrt(r+j);
        }
        printf("F2 %lf\n", r);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, f1, NULL);
    pthread_create(&t2, NULL, f2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
