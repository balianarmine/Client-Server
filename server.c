#include <stdio.h>
#include <string.h>

#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>


int main(int argc, char **argv) //server
{
    char buff[1024], q[] = "!exit";
    int socket_server = socket(AF_INET, SOCK_STREAM, 0), temp_sock;
    struct sockaddr_in address = {AF_INET, htons(50001), inet_addr(argv[1])};

    printf("Connecting address: %s:%d\n", argv[1], 50001);

    if (bind(socket_server, &address, sizeof address) < 0) {
        perror("bind");
        exit(-1);
    }

    if (listen(socket_server, 0) < 0) {
        perror("connect");
        exit(-1);
    }

    printf("Ready!\n");
    do {
    if ((temp_sock = accept(socket_server, 0,0)) < 0) {
       perror("accept:");
       exit(-1);
        }
    do {
        int len = recv(temp_sock, buff, sizeof buff - 1,0);
        buff[len] = 0;
        if(len > 0) printf("%s\n", buff);
        else break;
    } while(1);

    close(temp_sock);
    } while(strcmp(buff, q))

    return 0;
}
