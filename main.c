#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include "pingTest.c"

//  https://www.binarytides.com/socket-programming-c-linux-tutorial/

int main(int argc, char *argv[]) {

//    pingTest();

    char url[100];
    printf("Enter url: ");
    scanf("%s", url);

    char *hostname = url;
    char ip[100];
    struct hostent *he;
    struct in_addr **addr_list;

    if ((he = gethostbyname(hostname)) == NULL) {
        // gethostbyname failed
        herror("gethostbyname");
        return 1;
    }

    addr_list = (struct in_addr **) he->h_addr_list;

    // cast h_addr_list to in_addr
    int i;
    for (i = 0; addr_list[i] != NULL; i++) {
        strcpy(ip, inet_ntoa(*addr_list[i]));
        printf("%s resolved to : %s\n", hostname, ip);
    }
//    printf("%s\n", ip);
//    printf("you entered %s\n\n", url);

    int socket_desc;

    // Address Family - AF_INET (this is IP version 4)
    // Type - SOCK_STREAM (this means connection oriented TCP protocol)
    // Protocol - 0 [ or IPPROTO_IP This is IP protocol]
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_desc == -1) {
        printf("Could not create socket \n");
    } else {
        printf("Socket created \n");
    }


    struct sockaddr_in server;
    // ping google.com   64.233.165.138
    // or getting ip from pingTest 74.125.131.99
    printf("setting address: %s\n", ip);
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_family = AF_INET;
    server.sin_port = htons(80);

    // connect to remote server
    if (connect(socket_desc, (struct sockaddr *) &server, sizeof(server)) < 0) {
        puts("connection error");
        return 1;
    }

    puts("connected \n");

    // sending some data
    char *message;
    message = "GET / HTTP/1.1\r\n\r\n";
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        puts("send failed");
        return 1;
    }

    puts("data send\n");

    // receive a reply
    char server_reply[2000];
    if (recv(socket_desc, server_reply, 2000, 0) < 0) {
        puts("recv failed");
    }

    puts("reply received\n");
    puts(server_reply);

    return 0;
}




