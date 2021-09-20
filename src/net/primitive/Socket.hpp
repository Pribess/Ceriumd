// Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_NET_PRIMITIVE_SOCKET
#define _CERIUM_NET_PRIMITIVE_SOCKET

#ifdef WIN32
    #include <winsock2.h>
#else
    #include <sys/socket.h>
    #include <arpa/inet.h>
#endif
#include <cstring>
#include <iostream>
#include <vector>
#include <future>
#include <queue>

class Socket {
    private:
        int SocketDesc;
        unsigned char buff[1024];
    public:
        Socket(int SocketDesc);
        ~Socket();
        
        int CloseSocket();

        int SendData(std::vector<unsigned char> data);
        unsigned char *RecvData();

        static void ClearBuffer(unsigned char *buffer);
};

#endif