#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>

int main() {
    int s;
    struct sockaddr_in server, client;
    int c, l;
    
    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s < 0) {
        printf("Eroare la crearea socketului server\n");
        return 1;
    }
    
    memset(&server, 0, sizeof(server));
    server.sin_port = htons(1234);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    
    //    if (bind(s, (struct sockaddr *) &server, sizeof(server)) < 0) {
    //        printf("Eroare la bind\n");
    //        return 1;
    //    }
    
    listen(s, 5);
    
    l = sizeof(client);
    memset(&client, 0, sizeof(client));
    
    while (1) {
        uint16_t n, m, len;
        char a[100], b[100], rez[100];
        
        c = accept(s, (struct sockaddr *) &client, &l);
        printf("S-a conectat un client.\n");
        // deservirea clientului
        recv(c, &n, sizeof(n), MSG_WAITALL);
        recv(c, &m, sizeof(m), MSG_WAITALL);
        recv(c, &a, sizeof(a), MSG_WAITALL);
        recv(c, &b, sizeof(b), MSG_WAITALL);
        
        n = ntohs(n);
        m = ntohs(m);
        strcpy(a, ntohs(a));
        strcpy(b, ntohs(b));
        
        len = 0;
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (a[i] == b[j]) {
                    int ok = 1;
                    for (int h = 0; h < len; h++)
                        if (a[i] == rez[h]) {
                            ok = 0;
                            break;
                        }
                    if (ok == 1) {
                        rez[len++] = a[i];
                    }
                }
        
        send(c, &rez, sizeof(rez), 0);
        send(c, &len, sizeof(len), 0);
        
        close(c);
        // sfarsitul deservirii clientului;
    }
}
