#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int i, j;

    for(i=0; i<3; i++) {
        if(fork()) {
            for(j=0; j<10; j++) {
                printf("%d: I am %d son of %d\n",j,getpid(),getppid());
                sleep(1);
            }
            exit(0);
        }
    }
    for(i=0; i<3; i++) {
        wait(0);
    }
    return 0;
}
