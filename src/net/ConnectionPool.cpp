//Copyright (c) 2021 Heewon Cho

#include "ConnectionPool.hpp"

int ConnectionPool::AddSocket(std::string addr, Socket *socket) {
    try {
        this->ConnectionContainer.insert(std::pair<std::string, Socket *>(addr, socket));
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