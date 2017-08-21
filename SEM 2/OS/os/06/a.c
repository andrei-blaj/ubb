#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>

int main() {
    int a[4] = {1, 2, 3, 4};
    if(fork() == 0) {
        a[2] += a[3];
        exit(0);
    }
    a[0] += a[1];
    wait(0);
    a[0] += a[2];
    printf("%d\n", a[0]);
    return 0;
}
