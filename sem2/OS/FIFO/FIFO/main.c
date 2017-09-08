/*
 The main process reads commands entered by the user until the stop command is entered.
 For each command one new subprocess is launched (type A) that will launch another subprocess (type B).
 The B subprocess using one of the exec calls will execute the command.
 Process A will redirect the standard input of process B (using dup2 call) in a pipe channel.
 The pipe channel will be used by the process A to print the received content.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main () {
    char cmd[20];
    int pipefd[2];
    pipe(pipefd);
    
    while (1) {
        printf("> ");
        scanf("%s", &cmd);
        if (strcmp(cmd, "stop") == 0) {
            printf("Exiting..\n");
            exit(0);
        }
        
        int p = fork();
        
        if ( p == 0 ) {
            printf(" child A\n" );
            exit(0);
        }
        
        if ( p > 0 ) {
            printf (" parent A\n");
            // type A process
            
            int k = fork();
            
            if ( k == 0 ) {
                printf (" child B\n");
                
                dup2(pipefd[0], 0);
                close(pipefd[1]);
                
                execlp("grep", "grep", "", NULL);
                
                exit(0);
            }
            
            if ( k != 0 ) {
                // type B process
                printf(" parent B, will run exec \n");
                
                dup2(pipefd[1], 1);
                close(pipefd[0]);
                
                execlp(cmd, cmd, NULL, NULL);
            }
        }
    }
    return 0;
}
