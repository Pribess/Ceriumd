//Copyright (c) 2021 Heewon Cho

#include "ThreadFunction.hpp"

void ThreadFunction::SocketListener() {
    Listener *listener = new Listener(CERIUM_PORT);
    while (true) {
        ConnectionPool::AddSocket(listener->Listen());
    }
    delete listener;
}

void ThreadFunction::SocketHandler(Socket *socket) {
    
}