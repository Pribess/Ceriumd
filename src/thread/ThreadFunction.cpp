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

void ThreadFunction::SocketConnector() {
    try {
        ThreadRunner::StartClientSocketHandlerThread(BootStrapper::BootStrap());
    } catch (std::exception e) {
        throw e;
    }
}

void ThreadFunction::ServerSocketHandler(Socket *socket) {
    try {
        ThreadRunner::StartSocketReaderThread(socket);
        // std::vector<std::pair<uint32_t, unsigned short>> buff = Protocol::GetAddr(socket);
        // printf("%d", buff.at(0).first);
        // printf("%d", buff.at(0).second);
    } catch (std::exception e) {
        throw e;
    }
}

void ThreadFunction::ClientSocketHandler(Socket *socket) {
    try {
        ThreadRunner::StartSocketReaderThread(socket);
        Protocol::Version(socket);
    } catch (std::exception e) {
        throw e;
    }
}

void ThreadFunction::SocketReaderThread(Socket *socket) {
    try {
        while (true) {
            PacketDecoder::PacketHandler(socket->RecvData(), socket);
        }
    } catch (std::exception e) {
        throw e;
    }
}