/*
	The client sends to the server a string and a character. 
	The server returns to the client a list of all positions 
	in the string where specified character is found.
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>

int main() {
    int c;
    struct sockaddr_in server;
    uint16_t n, len;
    char m;
    char array[100];
    uint16_t rez[100];

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

    // READ

	printf("string = ");

	fgets(array, 100, stdin);
    n = strlen(array);
    array[strlen(array)] = '\0';

    printf("Character: ");
    scanf(" %c", &m);

    // SEND

    n = htons(n + 1);
    send(c, &n, sizeof(n), 0);

    send(c, array, strlen(array) + 1, 0);

    send(c, &m, sizeof(m), 0);
    
   	// GET
	
	recv(c, &len, sizeof(len), 0);
    len = ntohs(len);
    
    for (uint16_t i = 0; i < (uint16_t) len; i++) {
        uint16_t elementToReceive;
        recv(c, &elementToReceive, sizeof(elementToReceive), MSG_WAITALL);
        rez[i] = ntohs(elementToReceive);
    }
    
    printf("len: %hu\n", len);
    printf("Your character was found on the following positions: ");
    for (uint16_t i = 0; i < (uint16_t) len; i++) {
        printf("%hu ", rez[i]);
    }
    printf("\n");

    close(c);

}
