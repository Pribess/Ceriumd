// Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_NODE_NODE
#define _CERIUM_NODE_NODE

#include "net/primitive/Socket.hpp"
#include "net/tools/BootStrapper.hpp"
#include "net/protocol/Protocol.hpp"
#include "node/NodePool.hpp"

class NodePool;

class Node {
    private:
        uint64_t NetVersion;

        Socket *socket;
        uint32_t addr;
        unsigned short port;
        bool isNetWorkForwarded;

        std::thread *SocketReceiver;
        std::thread *SocketHandler;

        void StartSocketReceiver();
        void StartSocketHandler();


    public:
        Node(Socket *socket, uint32_t addr, unsigned short port);
        Node(Socket *socket, uint32_t addr);
        ~Node();

        std::pair<uint32_t, unsigned short> GetNetData();
        Socket *GetSocket();
};

#endif