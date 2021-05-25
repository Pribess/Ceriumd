//Copyright (c) 2021 Heewon Cho

#include "ConnectionPool.hpp"

int ConnectionPool::AddSocket(std::string InetAddr, Socket *Socket) {
    try {
        this->ConnectionContainer.insert({InetAddr, Socket});
        return 0;
    } catch (std::exception e) {
        throw e;
    }
}

int ConnectionPool::GetLength() {
    try {
        return this->ConnectionContainer.size();
    } catch (std::exception e) {
        throw e;
    }
}