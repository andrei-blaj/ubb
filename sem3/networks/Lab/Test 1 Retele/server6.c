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
    
    // Creating the socket
    s = socket(AF_INET, SOCK_STREAM, 0);
    
    if (s < 0) {
        printf("Eroare la crearea socketului server! \n");
        return 1;
    }
    
    memset(&server, 0, sizeof(server));
    server.sin_port = htons(1234);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    
    if (bind(s, (struct sockaddr *) &server, sizeof(server)) < 0) {
        printf("Eroare la bind! \n");
        return 1;
    }
    
    listen(s, 5);
    
    l = sizeof(client);
    memset(&client, 0, sizeof(client));
    
    while (1) {
        uint16_t n, len;
        char m;
        char array[100];
        uint16_t rez[100];
        
        c = accept(s, (struct sockaddr *) &client, &l);
        printf("S-a conectat un client. \n");
        
        // GET

        recv(c, &n, sizeof(n), MSG_WAITALL);
        n = ntohs(n);

        recv(c, array, n, MSG_WAITALL);

        recv(c, &m, sizeof(m), MSG_WAITALL);
        
        // SOLVE

        len = 0;
        
        for (int i = 0; i < n; i++) {
            if (array[i] == m) {
                rez[len++] = i;
            }
        }
        
        // SEND

        len = htons(len);
        send(c, &len, sizeof(len), 0);
        
        for (uint16_t i = 0; i < (uint16_t) ntohs(len); i++) {
            uint16_t elementToSend = htons(rez[i]);
            send(c, &elementToSend, sizeof(elementToSend), 0);
        }
        
        close(c);
    }
    
}
