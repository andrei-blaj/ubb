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
    uint16_t array1[100], array2[100], rez[100];

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

    for (uint16_t i = 0; i < (uint16_t) n; i++) {
        printf("a[%i]: ", i);
        scanf("%hu", &array1[i]);
    }

    printf("m = ");
    scanf("%hu", &m);
    
    for (uint16_t i = 0; i < (uint16_t) m; i++) {
        printf("a[%i]: ", i);
        scanf("%hu", &array2[i]);
    }

    n = htons(n);
    m = htons(m);

    send(c, &n, sizeof(n), 0);
    send(c, &m, sizeof(m), 0);
    
    for (uint16_t i = 0; i < (uint16_t) ntohs(n); i++) {
        uint16_t elementToSend = htons(array1[i]);
        send(c, &elementToSend, sizeof(elementToSend), 0);
    }
    
    for (uint16_t i = 0; i < (uint16_t) ntohs(m); i++) {
        uint16_t elementToSend = htons(array2[i]);
        send(c, &elementToSend, sizeof(elementToSend), 0);
    }

    recv(c, &len, sizeof(len), 0);
    
    len = ntohs(len);
    
    for (uint16_t i = 0; i < (uint16_t) len; i++) {
        uint16_t elementToReceive;
        recv(c, &elementToReceive, sizeof(elementToReceive), MSG_WAITALL);
        rez[i] = ntohs(elementToReceive);
    }
    
    printf("Common elements: ");
    for (uint16_t i = 0; i < (uint16_t) len; i++) {
        printf("%hu ", rez[i]);
    }
    printf("\n");

    close(c);

}
