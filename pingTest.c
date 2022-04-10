#include<stdio.h>  // printf
#include<string.h> // strcpy
#include<sys/socket.h>
#include<netdb.h> // hostent
#include<arpa/inet.h>

int main(int argc, char *argv[]){
    char *hostname = "www.google.com";
    char ip[100];
    struct hostent *he;
    struct in_addr **addr_list;    
    
    printf("debug\n");    
    
    if( (he = gethostbyname( hostname ) ) == NULL ) {
        // gethostbyname failed
        herror("gethostbyname");
        return 1;
    }
    printf("debug2\n");
    
    addr_list = (struct in_addr **) he -> h_addr_list;
    
    printf("debug3\n");
    // cast h_addr_list to in_addr
    int i;
    for(i = 0; addr_list[i] != NULL; i++){
        // return first
        strcpy(ip, inet_ntoa(*addr_list[i]) );
    }
    printf("debug4\n");
    
    printf( "%s resolved to : %s", hostname, ip );
    return 0;
}


