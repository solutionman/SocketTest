#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include<arpa/inet.h>

/*
 * run as client:
 * telnet localhost 7777
 */
int main() {
    int socket_desc, new_socket, c;
    struct sockaddr_in server, client;


    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("could not create socket");
    }
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(7777);

    if (bind(socket_desc, (struct sockaddr *) &server, sizeof(server)) < 0) {
        puts("bind failed");
        return 0;
    } else {
        puts("bind done");
        char *server_ip = inet_ntoa(server.sin_addr);
        printf("my ip: %s\n", server_ip);
        int server_port = htons(server.sin_port);
        printf("my port: %d\n", server_port);
    }

    listen(socket_desc, 3);

    puts("waiting for incoming connection...");
    c = sizeof(struct sockaddr_in);
//    new_socket = accept(socket_desc, (struct sockaddr *) &client, (socklen_t *) &c);
//    if (new_socket < 0) {
//        perror("accept failed");
//    } else {
//        puts("connection accepted");
//    }
    char buff[1000];
    while ((new_socket = accept(socket_desc, (struct sockaddr *) &client, (socklen_t *) &c))) {
        puts("connection accepted");
        char *client_ip = inet_ntoa(client.sin_addr);
        int client_port = htons(client.sin_port);
        printf("client ip: %s \n", client_ip);
        printf("client port: %d \n", client_port);

        char *message;
        message = "hello from server\n";
        write(new_socket, message, strlen(message));

        bzero(buff, 1000);
        read(new_socket, buff, sizeof buff);
        printf("from client: %s", buff);
    }

    if (new_socket < 0) {
        perror("accept failed");
        return 1;
    }

    return 0;
}