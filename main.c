#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>

//  https://www.binarytides.com/socket-programming-c-linux-tutorial/

int main(int argc, char *argv[]){
    int socket_desc;
    
    // Address Family - AF_INET (this is IP version 4) 
    // Type - SOCK_STREAM (this means connection oriented TCP protocol) 
    // Protocol - 0 [ or IPPROTO_IP This is IP protocol]
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    
    if(socket_desc == -1){
        printf("Could not create socket");
    } else {
        printf("Socket created");
    }
    
    
    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr("64.233.165.138"); // ping google.com   64.233.165.138
    server.sin_family = AF_INET;
    server.sin_port = htons(80);
    
    
    return 0;
}
