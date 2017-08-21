#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>

int main() {
    int i, p;
    for(i=0; i<10; i++) {
        p = fork();
        if(p == 0) {
            printf("%d\n", i);
            exit(0);
        }
        wait(0);
    }
    //sleep(5);
    //for(i=0; i<10; i++) {
    //    wait(0);
    //}
    return 0;
}
