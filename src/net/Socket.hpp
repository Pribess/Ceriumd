//Copyright (c) 2021 Heewon Cho

#ifndef CERIUM_NET_SOCKET
#define CERIUM_NET_SOCKET

#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>

class Socket {
private:
    int SocketDesc;
    char Buff[256];
public:
    Socket(int SocketDesc);
    ~Socket();
    int CloseSocket();
    int SendData(int data);
    int SendData(char data[]);
    int SendData(std::string data);
    char *RecvData();
};

#endif