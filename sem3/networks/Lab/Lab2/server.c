#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <stdint.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int c;

void time_out(int semnal) {
    int32_t len = -1;
    len = htonl(len);
    printf("Time out.\n");
    send(c, &len, sizeof(int32_t), 0);
    close(c); // desi nu am primit nimic de la client in 10 secunde, inchidem civilizat conexiunea cu acesta
    exit(1);
}

void tratare() {
    
    int cod;
    uint16_t n, m, len;
    uint16_t array1[100], array2[100], rez[100];
    uint16_t uReceived[100], vReceived[100], rezToSend[100];
    
    struct sockaddr_in server;
    
    if (c < 0) {
        fprintf(stderr, "Eroare la stabilirea conexiunii cu clientul.\n");
        exit(1);
    }
    else
        printf("Un nou client s-a conectat cu succes.\n");
    
    signal(SIGALRM, time_out);
    alarm(10);
    
    cod = recv(c, &n, sizeof(n), MSG_WAITALL);
    
    if (cod == 1)
        alarm(10);
    
    cod = recv(c, &m, sizeof(m), MSG_WAITALL);
    
    if (cod == 1)
        alarm(10);
    
    n = ntohs(n);
    m = ntohs(m);
    
    for (uint16_t i = 0; i < (uint16_t) n; i++) {
        uint16_t elementToReceive;
        cod = recv(c, &elementToReceive, sizeof(elementToReceive), MSG_WAITALL);
        array1[i] = ntohs(elementToReceive);
        
        if (cod == 1)
            alarm(10);
    }
    
    for (uint16_t i = 0; i < (uint16_t) m; i++) {
        uint16_t elementToReceive;
        cod = recv(c, &elementToReceive, sizeof(elementToReceive), MSG_WAITALL);
        array2[i] = ntohs(elementToReceive);
        
        if (cod == 1)
            alarm(10);
    }
    
    alarm(0);
    
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
    
    len = ntohs(len);
    
    close(c);
    
    if (len >= 0)
        printf("Am inchis cu succes conexiunea cu un client.");
    else {
        printf("Am inchis cu eroare conexiunea la client. Cod de eroare %d.\n", len);
        exit(1);
    }
    
    exit(0);
    
}

int main() {
    
    int s;
    struct sockaddr_in server, client;
    int l;
    
    // Creating the socket
    s = socket(PF_INET, SOCK_STREAM, 0);
    
    if (s < 0) {
        printf("Eroare la crearea socketului server! \n");
        return 1;
    }
    
    memset(&server, 0, sizeof(struct sockaddr_in));
    server.sin_port = htons(4321);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    
    if (bind(s, (struct sockaddr *) &server, sizeof(server)) < 0) {
        printf("Eroare la bind! \n");
        return 1;
    }
    
    listen(s, 5);
    
    while (1) {
        
        memset(&client, 0, sizeof(client));
        l = sizeof(client);
        
        c = accept(s, (struct sockaddr *) &client, &l);
        printf("S-a conectat clientul cu adresa %s si portul %d.\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
        
        if (fork() == 0) {
            tratare();
        }
        
    }
    
}
