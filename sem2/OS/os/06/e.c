#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<fcntl.h>

int main() {
    int n = 0;
    int d2e, e2d;

    d2e = open("d2e", O_WRONLY);
    e2d = open("e2d", O_RDONLY);

    while(n < 10) {
      n++;
      write(d2e, &n, sizeof(int));
      read(e2d, &n, sizeof(int));
      printf("E: %d\n", n);
    }
    close(e2d);
    close(d2e);
    return 0;
}
