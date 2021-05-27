//Copyright (c) 2021 Heewon Cho

#include "ConnectionPool.hpp"

std::map<std::string, Socket *> ConnectionPool::ConnectionContainer;

int ConnectionPool::AddSocket(std::pair<std::string, Socket *> pair) {
    try {
        ConnectionPool::ConnectionContainer.insert(pair);
        return 0;
    } catch (std::exception e) {
        throw e;
    }
}

int ConnectionPool::GetLength() {
    try {
        return ConnectionPool::ConnectionContainer.size();
    } catch (std::exception e) {
        throw e;
    }
}