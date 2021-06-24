//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_NET_SOCKET
#define _CERIUM_NET_SOCKET

#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>
#include <vector>
#include <condition_variable>
#include <queue>

class Socket {
    private:
        int SocketDesc;
        unsigned char buff[1024];
        std::queue<unsigned char *> queue;
    public:
        Socket(int SocketDesc);
        ~Socket();
        int CloseSocket();
        int SendData(std::vector<unsigned char> data);
        unsigned char *RecvData();
        void PutQueue(unsigned char *);
        unsigned char *ResData();
        std::condition_variable cv;
};

#endif