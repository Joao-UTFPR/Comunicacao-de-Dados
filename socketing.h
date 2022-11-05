#ifndef socketing_h
#define socketing_h

#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <stdlib.h>
#define PORT 8080

int build_client_socket(sockaddr_in serv_addr);

int build_client_fd(int sock, sockaddr_in serv_addr);

int build_server_fd(sockaddr_in address);

#endif