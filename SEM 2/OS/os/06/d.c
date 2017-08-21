#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<fcntl.h>

int main() {
    int n = 0;
    int d2e, e2d;

    d2e = open("d2e", O_RDONLY);
    e2d = open("e2d", O_WRONLY);

    while(n < 10) {
      read(d2e, &n, sizeof(int));
      printf("D: %d\n", n);
      n++;
      write(e2d, &n, sizeof(int));
    }
    close(e2d);
    close(d2e);
    return 0;
}
