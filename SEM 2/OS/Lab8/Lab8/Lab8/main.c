
///////////////////////////////////////// Lab 5 ///////////////////////////////////////////////

//#include <sys/types.h>
//#include <sys/wait.h>
//#include <stdio.h>
//
//int main() {
//    int pid, state;
//    printf(" 7The parent: before fork()\n ");
//    
//    pid = fork();
//    
//    if (pid != 0) {
//        wait(&state);
//    } else {
//        int pid;
//        printf("The child: begins the execution \n");
//        pid = getpid();
//        printf("The son: %d terminated\n", pid);
//        exit(10);
//    }
//    
//    printf("The parent: after fork()\n");
//    state = WEXITSTATUS(state);
//    printf("PID child=%d; terminated with the code %d = %x\n", pid, state, state);
//    
//}

///////////////////////////////////////// Lab 7 ///////////////////////////////////////////////


#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char *argv[])

{
    
    int pipefd[2];
    
    pid_t cpid;
    
    char buf;
    
    
    
    if (argc != 2) {
        
        fprintf(stderr, "Usage: %s \n", argv[0]);
    
        exit(EXIT_FAILURE);
        
    }
    
    
    
    if (pipe(pipefd) == -1) {
        
        perror("pipe");
        
        exit(EXIT_FAILURE);
        
    }
    
    
    
    cpid = fork();
    
    if (cpid == -1) {
        
        perror("fork");
        
        exit(EXIT_FAILURE);
        
    }
    
    
    
    if (cpid == 0) {    /* Child reads from pipe */
        
        close(pipefd[1]);          /* Close unused write end */
        
        
        
        while (read(pipefd[0], &buf, 1) > 0)
            
            write(STDOUT_FILENO, &buf, 1);
        
        
        
        write(STDOUT_FILENO, "\n", 1);
        
        close(pipefd[0]);
        
        _exit(EXIT_SUCCESS);
        
        
        
    } else {            /* Parent writes argv[1] to pipe */
        
        close(pipefd[0]);          /* Close unused read end */
        
        write(pipefd[1], argv[1], strlen(argv[1]));
        
        close(pipefd[1]);          /* Reader will see EOF */
        
        wait(NULL);                /* Wait for child */
        
        exit(EXIT_SUCCESS);
        
    }
    
}

///////////////////////////////////////// Lab 8 ///////////////////////////////////////////////


