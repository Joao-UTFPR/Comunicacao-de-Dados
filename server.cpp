// Server side C/C++ program to demonstrate Socket
// programming
#include "socketing.h"
#include "cryptography.h"


int main()
{
    int server_fd, new_socket; 
    int valread;
    
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    char* hello = "resposta!";

    server_fd=build_server_fd(address);

    if ((new_socket
            = accept(server_fd, (struct sockaddr*)&address,
                    (socklen_t*)&addrlen))
            < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
    while(true)
    {
        char buffer[1024] = { 0 };
   
        valread = read(new_socket, buffer, 1024);
        printf("%s\n", decrypt(buffer));
        
        send(new_socket, hello, strlen(hello), 0);
        printf("Resposta enviada\n");

    }
    
 
    // closing the connected socket
    close(new_socket);
    // closing the listening socket
    shutdown(server_fd, SHUT_RDWR);
    return 0;
}