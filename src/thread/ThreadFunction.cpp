//Copyright (c) 2021 Heewon Cho

#include "ThreadFunction.hpp"

void ThreadFunction::SocketListener() {
    try {
        Listener *listener = new Listener(CERIUM_PORT);
        while (true) {
            std::pair<Socket *, uint32_t> buff = listener->Listen();
            Node *node = new Node(buff.first, buff.second);
            NodePool::AddNode(node);
            
        }
        delete listener;
    } catch (std::runtime_error &e) {
        throw e;
    }
}

void ThreadFunction::SocketConnector() {
    try {
        std::pair<Socket *, std::pair<uint32_t, unsigned short>> buff = BootStrapper::BootStrap();
        Node *node = new Node(buff.first, buff.second.first, buff.second.second);
        NodePool::AddNode(node);
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

void ThreadFunction::ServerSocketHandler(Socket *socket) {
    try {
        Protocol::Version(socket);
    } catch (std::runtime_error &e) {
        throw e;
    }
}

void ThreadFunction::ClientSocketHandler(Socket *socket) {
    try {
        Protocol::Version(socket);
    } catch (std::runtime_error &e) {
        throw e;
    }
}