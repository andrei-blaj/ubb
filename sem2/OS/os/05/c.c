#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void noway(int sig) {
    printf("No!\n");
}

int main() {
    signal(SIGINT, noway);
    while(1) {
        sleep(1);
        printf("Not dead yet!\n");
    }
    return 0;
}
