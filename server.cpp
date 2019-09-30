#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int server_socketfd;
    int client_socketfd;
    int server_len;
    socklen_t client_len;
    struct sockaddr_un server_address;
    struct sockaddr_un client_address;

    unlink("server_socket");
    server_socketfd = socket(AF_UNIX, SOCK_STREAM, 0);
    server_address.sun_family = AF_UNIX;
    strcpy(server_address.sun_path, "server_socket");
    server_len = sizeof(server_address);
    bind(server_socketfd, (struct sockaddr *)&server_address, server_len);
    listen(server_socketfd, 5);
    while (1){
        char ch;
        printf("server waiting\n");
        client_len = sizeof(client_address);
        client_socketfd = accept(server_socketfd, (struct sockaddr *)&client_address, &client_len);
        read(client_socketfd, &ch, 1);
        ch++;
        write(client_socketfd, &ch, 1);
        close(client_socketfd);
    }
}