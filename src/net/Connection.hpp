//Copyright (c) 2021 Heewon Cho

#include <vector>

#include "primitive/Socket.hpp"

class Connection
{
private:
    std::vector<Socket *> ConnectionPool;
public:
    Connection();
};