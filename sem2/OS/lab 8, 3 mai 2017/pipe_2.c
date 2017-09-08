#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define myfifo "/tmp/myfifo"

int main() {
    int a[] = { 1, 2, 3, 4 };
    int pid;

    system("echo \"\" > /tmp/myfifo");

    if( (pid=fork()) == 0 ) {
        int sum = a[0] + a[1];

        int f = open(myfifo, O_WRONLY);

        write(f, &sum, sizeof(int));

        close(f);
        exit(0);

    } else {
        int sum = a[3] + a[2], aux_sum;

        int f = open(myfifo, O_RDONLY);
        wait(0);
        read(f, &aux_sum, sizeof(int));
        close(f);
        remove(myfifo);

        printf("%d\n", (sum+aux_sum));
    }
    return 0;
}
