#include <stdio.h>
#include <string.h>

struct twins {
    int x, y;
};

struct seq {
    int A[1001];
    int len;
};

void appstart();
void sieve();
char getInput();
void menu();

int op1(struct twins *sol);
void op2(struct seq *s, struct seq *rez);
void op3(struct seq *s);

int Sieve[1001];

int main() {
    
    appstart();
    
    return 0;
}

// Generating Erathostene's Sieve in order to check if a number is prime in O(1)
void sieve() {
    int i, j;
    
    for (i = 2; i <= 1000; i++)
        if (Sieve[i] == 0)
            for (j = 2 * i; j <= 1000; j += i)
                Sieve[j] = 1;
            
}

// This function prints the menu to the screen
void menu() {
    
    printf("Choose one of the following: \n");
    printf("1. Determine the first 'n' pairs of twin numbers.\n");
    printf("2. Find the longest contiquous subsequence.\n");
    printf("3. Generate the prime numbers smaller than a number 'n'.\n");
    printf("0. Exit.\n");
    printf("~: ");
    
}

// This function returns either '1' or '2' based on the users choise
char getInput() {
    
    char userInput[100] = "";
    
    while (strlen(userInput) != 1 || (userInput[0] != '1' && userInput[0] != '2' && userInput[0] != '3' && userInput[0] != '0')) {
        
        menu();
        
        scanf("%s", userInput);
        
    }
    
    return userInput[0];
    
}

// This function solves the second operation of the problem and returns the result
int op1(struct twins* sol) {
    int n, i = 1, j = 1;
    
    printf("n: ");
    scanf("%i", &n);
    
    while (j <= n) {
        
        if (Sieve[i] == 0 && Sieve[i + 2] == 0) {
            sol[j].x = i;
            sol[j].y = i + 2;
            j++;
        }
        
        i++;
        
    }
    
    return n;
    
}

// This function solves the second operation of the problem and returns the result
void op2(struct seq* s, struct seq* rez) {
    int n, x, i = 1;
    
    printf("n: ");
    scanf("%i", &n);
    
    (*s).len = n;
    
    for (i = 1; i <= n; i++) {
        scanf("%i", &x);
        (*s).A[i] = x;
    }
    
    int l = 0, z = 0, t = 0;
    int xl = 0, xz = 1, xt = 1;
    
    for (i = 2; i <= n; i++) {
        if ((*s).A[i] != (*s).A[i-1] - 1) {
            xt = i - 1;
            xl = xt - xz + 1;
        
            if (xl > l) {
                l = xl;
                z = xz;
                t = xt;
            }
            
            xz = i;

        }

    }

    xt = n;
    xl = xt - xz + 1;
    
    if (xl > l) {
        l = xl;
        z = xz;
        t = xt;
    }

    (*rez).len = l;
    
    for (i = z; i <= t; i++)
        (*rez).A[i-z+1] = (*s).A[i];
}

// Generate the prime numbers smaller than a number 'n'.
void op3(struct seq* s) {
    
    int i = 1, n;
    
    printf("n: ");
    scanf("%i", &n);
    
    (*s).len = 0;
    
    for (i = 1; i < n; i++)
        if (Sieve[i] == 0)
            (*s).A[++(*s).len] = i;
    
}

// The menu of the application
void appstart() {
    
    int unicornsExist = 1;
    
    while (unicornsExist) {
    
        char operation;
    
        sieve();
    
        operation = getInput();
    
        if (operation == '1') {
            // Determine the first 'n' pairs of twin numbers.
        
            int i, n;
            struct twins sol[100];
        
            n = op1(sol);
        
            for (i = 1; i <= n; i++)
                printf("> %i, %i\n", sol[i].x, sol[i].y);
        
        } else if (operation == '2') {
            // Find the longest contiquous subsequence.
            
            int i;
            struct seq s, rez;

            op2(&s, &rez);
            
            printf("> ");
            for (i = 1; i <= rez.len; i++) {
                printf("%i", rez.A[i]);
                if (i != rez.len)
                    printf(", ");
            }
            printf("\n");
        
        } else if (operation == '3') {
            // Generate the prime numbers smaller than a number 'n'.
            
            int i;
            struct seq s;
            
            op3(&s);
            
            printf("> ");
            for (i = 2; i <= s.len; i++) {
                printf("%i", s.A[i]);
                if (i != s.len)
                    printf(", ");
            }
            printf("\n");
            
            
        } else {
            //Exiting the application.
            printf("Exiting...\n");
            unicornsExist = 0;
        }
        
    }
    
}
