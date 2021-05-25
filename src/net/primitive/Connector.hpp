//Copyright (c) 2021 Heewon Cho

#ifndef CERIUM_NET_PRIMITIVE_CONNECTOR
#define CERIUM_NET_PRIMITIVE_CONNECTOR

#include <netinet/in.h>
#include <string>
#include <cstddef>

#include "net/Socket.hpp"

class Connector {
private:
    socklen_t BuffLen;
    int SocketDesc;
    sockaddr_in SinOppo;
    char Buff[256];
    int CreateSocket();
    int Connect();
    int CloseSocket();
public:
    Connector(int sin_port, char sin_addr[]);
    std::pair<std::string, Socket*> GetConnection();
};

#endif