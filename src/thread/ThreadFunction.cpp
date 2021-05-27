//Copyright (c) 2021 Heewon Cho

#include "ThreadFunction.hpp"

int ThreadFunction::SocketListener() {
    Listener *listener = new Listener(CERIUM_PORT);
    while (true) {
        ConnectionPool::AddSocket(listener->Listen());
        std::cout << ConnectionPool::GetLength() << std::endl;
    }
    delete listener;
}