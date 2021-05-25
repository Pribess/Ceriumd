//Copyright (c) 2021 Heewon Cho

#include "ConnectionPool.hpp"

int ConnectionPool::AddSocket(std::pair<std::string, Socket *> pair) {
    try {
        this->ConnectionContainer.insert(pair);
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