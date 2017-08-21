#include <stdio.h>
#include <unistd.h>

int main() {
    printf("111111111111111111\n");
    execl("/usr/bin/sort", "/usr/bin/sort", "-r", "a.c", NULL);
    printf("222222222222222222\n");
    return 0;
}
