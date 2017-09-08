#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t ma, mb;

void* a(void* p) {
    int i;
    for(i=0; i<10;i++) {
        pthread_mutex_lock(&ma);
        printf("A\n");
        pthread_mutex_unlock(&mb);
    }
    return NULL;
}
void* b(void* p) {
    int i;
    for(i=0; i<10;i++) {
        pthread_mutex_lock(&mb);
        printf("B\n");
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
