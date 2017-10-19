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
        uint16_t n, m, len;
        uint16_t array1[100], array2[100], rez[100];
        uint16_t uReceived[100], vReceived[100], rezToSend[100];
        
        c = accept(s, (struct sockaddr *) &client, &l);
        printf("S-a conectat un client. \n");
        
        recv(c, &n, sizeof(n), MSG_WAITALL);
        recv(c, &m, sizeof(m), MSG_WAITALL);
        
        n = ntohs(n);
        m = ntohs(m);
        
        for (uint16_t i = 0; i < (uint16_t) n; i++) {
            uint16_t elementToReceive;
            recv(c, &elementToReceive, sizeof(elementToReceive), MSG_WAITALL);
            array1[i] = ntohs(elementToReceive);
        }
        
        for (uint16_t i = 0; i < (uint16_t) m; i++) {
            uint16_t elementToReceive;
            recv(c, &elementToReceive, sizeof(elementToReceive), MSG_WAITALL);
            array2[i] = ntohs(elementToReceive);
        }
        
        len = 0;
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (array1[i] == array2[j]) {
                    int ok = 1;
                    for (int h = 0; h < len; h++)
                        if (rez[h] == array1[i])
                            ok = 0;
                    if (ok)
                        rez[len++] = array1[i];
                }
        
        len = htons(len);
        
        send(c, &len, sizeof(len), 0);
        
        for (uint16_t i = 0; i < (uint16_t) ntohs(len); i++) {
            uint16_t elementToSend = htons(rez[i]);
            send(c, &elementToSend, sizeof(elementToSend), 0);
        }
        
        close(c);
    }
    
}
