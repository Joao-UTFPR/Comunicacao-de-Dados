// Client side C/C++ program to demonstrate Socket
// programming
#include "socketing.h"
#include "cryptography.h"


int main(int argc, char const* argv[])
{
    int sock = 0, client_fd;

    struct sockaddr_in serv_addr;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    sock = build_client_socket(serv_addr);
    client_fd = build_client_fd(sock, serv_addr); 


    char buffer[1024] = { 0 };
    int valread;

    while(true){
        char* hello;
        scanf("%s", hello);
        hello = encrypt(hello);

        send(sock, hello, strlen(hello), 0);

        printf("Mensagem Enviada\n");
        
        valread = read(sock, buffer, 1024);

        printf("%s\n", buffer);
    }
    
    // closing the connected socket
    close(client_fd);
    
    return 0;
}