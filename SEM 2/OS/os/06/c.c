#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<fcntl.h>

int main() {
    int a[4] = {1, 2, 3, 4};
    int f;

    if(fork() == 0) {
        f = open("cfifo", O_WRONLY);
        a[2] += a[3];
        write(f, &a[2], sizeof(int));
        write(f, &a[2], sizeof(int));
        close(f);
        exit(0);
    }
    f = open("cfifo", O_RDONLY);

    a[0] += a[1];
    read(f, &a[2], sizeof(int));
    close(f);
    wait(0);
    a[0] += a[2];
    printf("%d\n", a[0]);
    return 0;
}
