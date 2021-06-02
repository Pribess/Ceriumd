//Copyright (c) 2021 Heewon Cho

#include "ConnectionPool.hpp"

std::map<uint32_t, Socket *> ConnectionPool::ConnectionContainer;

void ConnectionPool::AddSocket(std::pair<uint32_t, Socket *> pair) {
    try {
        ConnectionPool::ConnectionContainer.insert(pair);
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