//Copyright (c) 2021 Heewon Cho

#include "ConnectionPool.hpp"

std::map<uint32_t, Socket *> ConnectionPool::ConnectionContainer;

Socket *ConnectionPool::AddSocket(std::pair<uint32_t, Socket *> pair) {
    try {
        ConnectionPool::ConnectionContainer.insert(pair);
        return ConnectionPool::GetSocket(pair.first);
    } catch (std::runtime_error e) {
        throw e;
    }
}

Socket *ConnectionPool::GetSocket(uint32_t addr) {
    try {
        return ConnectionPool::ConnectionContainer.find(addr)->second;
    } catch (std::runtime_error e) {
        throw e;
    }
}

int ConnectionPool::GetLength() {
    try {
        return ConnectionPool::ConnectionContainer.size();
    } catch (std::runtime_error e) {
        throw e;
    }
}