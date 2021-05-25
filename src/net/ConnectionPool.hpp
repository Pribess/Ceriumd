//Copyright (c) 2021 Heewon Cho

#include <vector>

#include "primitive/Connector.hpp"
#include "primitive/Listener.hpp"
#include "Socket.hpp"

class ConnectionPool {
private:
    std::vector<Socket *> ConnectionContainer;
public:
    ConnectionPool();
};