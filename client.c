#include <stdio.h>
#include <string.h>

#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char **argv) //client
{
    char buff[1024], q[] = "!exit";
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in address = {AF_INET, htons(50003), inet_addr(argv[1])};

    if (connect(client_socket, &address, sizeof address) < 0) {
        perror("Connection error");
        exit(-1);
    }

    printf("Ready!\n");
    do {
        scanf("%s", buff);
        send(client_socket, buff, strlen(buff), 0);
    } while(strcmp(buff, q));

    close(client_socket);
    return 0;
}
