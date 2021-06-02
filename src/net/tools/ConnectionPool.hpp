//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_NET_TOOLS_CONNECTIONPOOL
#define _CERIUM_NET_TOOLS_CONNECTIONPOOL

#include <map>

#include "net/primitive/Connector.hpp"
#include "net/primitive/Listener.hpp"
#include "net/Socket.hpp"

class ConnectionPool {
    private:
        static std::map<uint32_t, Socket *> ConnectionContainer;
    public:
        static void AddSocket(std::pair<uint32_t, Socket *> pair);
        static int GetLength();
};

#endif