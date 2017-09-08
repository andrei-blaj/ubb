#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    printf("111111111111111111\n");
    if(fork() == 0) {
        execl("/usr/bin/sort", "/usr/bin/sort", "-r", "a.c", NULL);
        exit(0);
    }
    printf("222222222222222222\n");
    wait(0);
    return 0;
}
