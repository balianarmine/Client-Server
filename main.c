#include <stdio.h>
#include <string.h>

#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char **argv) //client
{
    printf("Connection...");

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in address;
    address.sin_addr.s_addr = htonl(0xC0A800F9);
    address.sin_family = AF_INET;
    address.sin_port = htons(31415);

    char buff[1024], q[] = "!exit";

    //printf("%d - %d\n %d - %d\n %d - %d", address.sin_family, AF_INET, address.sin_port, htons(31415), address.sin_addr.s_addr ,htonl(0xC0A800F9));


    if (connect(client_socket, &address, sizeof address) < 0) {
        printf("Connection error!");
     //   exit(-1);
    }

    do {
        fflush(stdout);
        scanf("%60s", buff);
        send(client_socket, buff, strlen(buff), 0);
    } while(strcmp(buff, q) != 0);

    close(client_socket);
    return 0;
}
