//
//  main.c
//  Lab 10
//
//  Created by Andrei-Sorin Blaj on 10/05/2017.
//  Copyright © 2017 Andrei-Sorin Blaj. All rights reserved.
//

    /*
 Parintele citeste un numar n < 100 si il trimite fiului.
 Fiul va calcula n*1 .. n * 10 si le va transmite parintelui.
 Parintele va afisa rez de la fiu.
     */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, const char * argv[]) {
    
    int n;
    printf("n: ");
    scanf("%d", &n);
    
    int childToParent[2];
    
    pipe(childToParent);
    
    for (int i = 1; i<= 10; i++) {
        
        if (fork() == 0) {
            
            n *= i;
            
            write(childToParent[1], &n, sizeof(int));
            
            close(childToParent[0]);
            close(childToParent[1]);
            
            exit(0);
            
        } else {
            wait(0);
            
            read(childToParent[0], &n, sizeof(int));
            
            printf("%d\n", n);
            
            n /= i;
        };
    };
    
    close(childToParent[0]);
    close(childToParent[1]);
    
    return 0;
}
