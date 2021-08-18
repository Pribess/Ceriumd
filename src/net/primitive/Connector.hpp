// Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_NET_PRIMITIVE_CONNECTOR
#define _CERIUM_NET_PRIMITIVE_CONNECTOR

#include <netinet/in.h>
#include <string>
#include <cstddef>
#include <fcntl.h>
#include <sys/socket.h>

#include "net/primitive/Socket.hpp"

class Connector {
    private:
        socklen_t BuffLen;
        int SocketDesc;
        sockaddr_in SinOppo;
        char Buff[256];
        int CreateSocket();
        static int ConnectWithTimeout(int sd, const sockaddr *addrst, socklen_t len, unsigned long time);
    public:
        Connector(char sin_addr[], int sin_port);
        Connector(in_addr_t sin_addr, int sin_port);
        
        Socket *Connect();
};

#endif