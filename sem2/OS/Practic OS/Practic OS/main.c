#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<string.h>

int nr_aparitii[25];
pthread_mutex_t mtx;


void* number(void* word){
    
    int index;
    char cuv[50];
    strcpy(cuv,(char*)word);
    
    for (index=0;index<strlen(cuv);index++)
    {
        if (cuv[index]>='0' && cuv[index]<='9')
        {
            int c = cuv[index] - '0';
            pthread_mutex_lock(&mtx);
            nr_aparitii[c] = nr_aparitii[c]+1;
            pthread_mutex_unlock(&mtx);
        }
    }
    return NULL;
}

int main(int argc, char*argv[])
{
    pthread_t thread[argc];
    int index;
    int min = 100;
    int digit;
    pthread_mutex_init(&mtx, NULL);
    if (argc < 3){
        printf("You need at least 3 params.");
        return 0;
    }
    for (index=1;index<argc;index++)
    {
        char* word = argv[index];
        pthread_create(&thread[index], NULL, number, (void*)(word));
    }
    for (index=1;index<argc;index++)
    {
        pthread_join(thread[index],NULL);
    }
    
    
    for (index=0;index<=9;index++)
    {
        if (nr_aparitii[index] != 0 && nr_aparitii[index]<min)
        {
            min = nr_aparitii[index];
            digit = index;
        }
    }
    printf("Digit: %d  Frequency: %d\n",digit,min);
    pthread_mutex_destroy(&mtx);
    return 0;
}
