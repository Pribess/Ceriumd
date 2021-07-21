//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_NODE_NODE
#define _CERIUM_NODE_NODE

#include "net/Socket.hpp"
#include "thread/ThreadFunction.hpp"

class Node {
    private:
        Socket *socket;
        uint32_t addr;
        unsigned short port;
        bool isNetWorkForwarded;
    public:
        Node(Socket *socket, uint32_t addr, unsigned short port);
        Node(Socket *socket, uint32_t addr);
        ~Node();
        std::thread *StartSocketReceiver();
};

#endif