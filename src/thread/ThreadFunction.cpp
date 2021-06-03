//Copyright (c) 2021 Heewon Cho

#include "ThreadFunction.hpp"

void ThreadFunction::SocketListener() {
    try {
        Listener *listener = new Listener(CERIUM_PORT);
        while (true) {
            ThreadRunner::StartServerSocketHandlerThread(ConnectionPool::AddSocket(listener->Listen()));
        }
        delete listener;
    } catch (std::exception e) {
        throw e;
    }
}

void ThreadFunction::ServerSocketHandler(Socket *socket) {
    try {
        Protocol::Version(socket);
    } catch (std::exception e) {
        throw e;
    }
}