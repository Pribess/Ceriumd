//Copyright (c) 2021 Heewon Cho

#include <vector>

#include "primitive/Socket.hpp"

class Connection
{
private:
    Socket *s1 = new Socket();
    std::vector<Socket *> ConnectionPool;
public:
    Connection();
};