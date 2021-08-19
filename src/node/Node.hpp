// Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_NODE_NODE
#define _CERIUM_NODE_NODE

#include "net/primitive/Socket.hpp"
#include "net/tools/BootStrapper.hpp"
#include "net/protocol/Protocol.hpp"
#include "node/NodePool.hpp"
#include "net/Connection.hpp"

class NodePool;

class Node {
    private:
        uint64_t NetVersion;

        Connection *con;
        uint32_t addr;
        unsigned short port;
        bool isNetWorkForwarded;

        std::thread *SocketReceiver;
        std::thread *SocketHandler;

        void StartSocketReceiver();
        void StartSocketHandler();


    public:
        Node(Connection *con, uint32_t addr, unsigned short port);
        Node(Connection *con, uint32_t addr);
        ~Node();

        std::pair<uint32_t, unsigned short> GetNetData();
        Connection *GetConnection();
};

#endif