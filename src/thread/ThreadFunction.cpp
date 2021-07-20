//Copyright (c) 2021 Heewon Cho

#include "ThreadFunction.hpp"

void ThreadFunction::SocketListener() {
    try {
        Listener *listener = new Listener(CERIUM_PORT);
        while (true) {
            std::pair<Socket *, uint32_t> buff = listener->Listen();
            ThreadRunner::StartServerSocketHandlerThread(buff.first);
        }
        delete listener;
    } catch (std::runtime_error e) {
        throw e;
    }
}

void ThreadFunction::SocketConnector() {
    try {
        std::pair<Socket *, std::pair<uint32_t, unsigned short>> buff = BootStrapper::BootStrap();
        ThreadRunner::StartClientSocketHandlerThread(buff.first);
    } catch (std::runtime_error e) {
        throw e;
    }
}

void ThreadFunction::ServerSocketHandler(Socket *socket) {
    try {
        ThreadRunner::StartSocketReaderThread(socket);
    } catch (std::runtime_error e) {
        throw e;
    }
}

void ThreadFunction::ClientSocketHandler(Socket *socket) {
    try {
        ThreadRunner::StartSocketReaderThread(socket);
        Protocol::Version(socket);
        std::vector<std::pair<uint32_t, unsigned short>> buff = Protocol::GetAddr(socket);
        for (std::pair<uint32_t, unsigned short> cnt : buff) {
            printf("%d, ", cnt.first);
            printf("%d\n", cnt.second);
        }
    } catch (std::runtime_error e) {
        throw e;
    }
}

void ThreadFunction::SocketReaderThread(Socket *socket) {
    try {
        while (true) {
            if (PacketDecoder::PacketHandler(socket->RecvData(), socket)) {
                return;
            }
        }
    } catch (std::runtime_error e) {
        throw e;
    }
}