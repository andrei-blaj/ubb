#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pgs[2], psw[2];

    pipe(pgs);
    pipe(psw);

    if(fork() == 0) {
      close(pgs[0]); close(psw[0]); close(psw[1]);
      dup2(pgs[1], 1);
      execl("/bin/grep","/bin/grep","a","/etc/passwd",NULL);
      exit(0);
    }

    if(fork() == 0) {
      close(pgs[1]); close(psw[0]);
      dup2(pgs[0], 0);
      dup2(psw[1], 1);
      execl("/bin/sed","/bin/sed","s/[^a]//g",NULL);
      exit(0);
    }

    if(fork() == 0) {
      close(pgs[0]); close(pgs[1]); close(psw[1]);
      dup2(psw[0], 0);
      execl("/usr/bin/wc","/usr/bin/wc","-c",NULL);
      exit(0);
    }

    close(pgs[0]); close(pgs[1]); close(psw[0]); close(psw[1]);

    wait(0);
    wait(0);
    wait(0);

    return 0;
}
