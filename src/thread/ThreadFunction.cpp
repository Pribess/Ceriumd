//Copyright (c) 2021 Heewon Cho

#include "ThreadFunction.hpp"

void ThreadFunction::SocketListener() {
    try {
        Listener *listener = new Listener(CERIUM_PORT);
        while (true) {
            std::pair<Socket *, uint32_t> buff = listener->Listen();
            NodePool::AddNode(new Node(buff.first, buff.second));
        }
        delete listener;
    } catch (std::runtime_error &e) {
        throw e;
    }
}

void ThreadFunction::SocketConnector() {
    try {
        std::pair<Socket *, std::pair<uint32_t, unsigned short>> buff = BootStrapper::BootStrap();
        NodePool::AddNode(new Node(buff.first, buff.second.first, buff.second.second));
    } catch (std::runtime_error &e) {
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
    } catch (std::runtime_error &e) {
        throw e;
    }
}