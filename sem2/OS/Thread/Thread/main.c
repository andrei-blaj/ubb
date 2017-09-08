/*
 - read from console 2 msg (max 100 chars)
 - has 2 global vars: letter count, special chars count
 - starts 2 threads, each parses 1 msg chr by chr and increments the values
 - display the two values and stop
 */

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

int letter_count;
int special_count;

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

void* cauta(void *p) {
    
    for (char *i = (char*)p; *i != '\0'; i += sizeof(char)) {
        
        pthread_mutex_lock(&mut);
        
        if ((*i >= 'a' && *i <= 'z') || (*i >= 'A' && *i <= 'Z'))
            letter_count += 1;
        else
            special_count += 1;
        
        pthread_mutex_unlock(&mut);
        
    }
    
    return NULL;
    
}

int main() {
    
    pthread_t threaduri[2];
    
    char msg1[100];
    char msg2[100];
    
    printf("> First message: ");
    scanf("%s", msg1);
    printf("> Second message: ");
    scanf("%s", msg2);
    
    pthread_create(&threaduri[0], NULL, cauta, (void*)(&msg1));
    pthread_create(&threaduri[1], NULL, cauta, (void*)(&msg2));
    
    pthread_join(threaduri[0], NULL);
    pthread_join(threaduri[1], NULL);
    
    printf("> Normal chars: %d\n  Special chars: %d\n", letter_count, special_count);
    
    return 0;
}



