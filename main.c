#include<stdio.h>
#include<sys/socket.h>

//  https://www.binarytides.com/socket-programming-c-linux-tutorial/
int main(int argc, char *argv[]){
    int socket_desc;
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    
    if(socket_desc == -1){
        printf("Could not create socket");
    } else {
        printf("Socket created");
    }
    
    return 0;
}
