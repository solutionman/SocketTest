#include<stdio.h>  // printf
#include<string.h> // strcpy
#include<sys/socket.h>
#include<netdb.h> // hostent
#include<arpa/inet.h>

//int main() {
int pingTest() {

    char *hostname = "www.google.com";
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

    return 0;
}


