#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    int a[] = { 1, 2, 3, 4 };

    int pid;

    if( (pid = fork()) == 0 ) {
        int sum = a[0] + a[1];
        printf("%d\n",sum);

        exit(0);
    } else {
        int sum = a[2] + a[3];
        printf("%d\n",sum);
    }

    wait(0);

    return 0;
}
