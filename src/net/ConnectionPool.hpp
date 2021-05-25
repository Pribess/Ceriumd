//Copyright (c) 2021 Heewon Cho

#include <map>

#include "primitive/Connector.hpp"
#include "primitive/Listener.hpp"
#include "Socket.hpp"

class ConnectionPool {
private:
    std::map<std::string, Socket *> ConnectionContainer;
public:
    int AddSocket(std::string InetAddr, Socket *Socket);
    int GetLength();
};