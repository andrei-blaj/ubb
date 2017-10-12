#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>

int main() {
    int c;
    struct sockaddr_in server;
    uint16_t n, m, len;
    uint16_t a[100], b[100], rez[100];
    
    c = socket(AF_INET, SOCK_STREAM, 0);
    if (c < 0) {
        printf("Eroare la crearea socketului client\n");
        return 1;
    }
    
    memset(&server, 0, sizeof(server));
    server.sin_port = htons(1234);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    if (connect(c, (struct sockaddr *) &server, sizeof(server)) < 0) {
        printf("Eroare la conectarea la server\n");
        return 1;
    }
    
    printf("n = ");
    scanf("%hu", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("&hu", &a[i]);
    }
    
    printf("m = ");
    scanf("%hu", &m);
    
    for (int i = 0; i < n; i++) {
        scanf("&hu", &a[i]);
    }
    
    n = htons(n);
    m = htons(m);
    
    for (int i = 0; i < n; i++) {
        a[i] = htons(a[i]);
    }
    
    for (int i = 0; i < m; i++) {
        b[i] = htons(b[i]);
    }
    
    send(c, &n, sizeof(n), 0);
    send(c, &m, sizeof(m), 0);
    send(c, &a, sizeof(a), 0);
    send(c, &b, sizeof(b), 0);
    
    recv(c, &rez, sizeof(rez), 0);
    recv(c, &len, sizeof(len), 0);
    
    len = ntohs(len);
    for (int i = 0; i < m; i++) {
        rez[i] = htons(rez[i]);
    }
    
    printf("Result: ");
    for (int i = 0; i < len; i++)
        printf("%hu, ", &rez[i]);
    printf("\n");
    
    close(c);
}
