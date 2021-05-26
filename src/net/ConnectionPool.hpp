//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_NET_CONNECTIONPOOL
#define _CERIUM_NET_CONNECTIONPOOL

#include <map>

#include "primitive/Connector.hpp"
#include "primitive/Listener.hpp"
#include "Socket.hpp"

class ConnectionPool {
private:
    static std::map<std::string, Socket *> ConnectionContainer;
public:
    static int AddSocket(std::pair<std::string, Socket *> pair);
    static int GetLength();
};

#endif