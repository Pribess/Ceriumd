// Copyright (c) 2021 Heewon Cho

#include "Node.hpp"

Node::Node(Socket *socket, uint32_t addr, unsigned short port) {
    this->socket = socket;
    this->addr = addr;
    this->port = port;
    this->isNetWorkForwarded = true;
    this->StartSocketReceiver();
    this->StartSocketHandler();
}

Node::Node(Socket *socket, uint32_t addr) {
    this->socket = socket;
    this->addr = addr;
    this->isNetWorkForwarded = false;
    this->StartSocketReceiver();
    this->StartSocketHandler();
}

Node::~Node() {
    this->socket->CloseSocket();
    this->SocketReceiver->detach();
}

void Node::StartSocketReceiver() {
    this->SocketReceiver = new std::thread([&](Socket *socket) {
        try {
            while (true) {
                if (PacketDecoder::PacketHandler(socket->RecvData(), socket)) {
                    NodePool::RemoveNode(this);
                    return;
                }
            }
        } catch (std::runtime_error &e) {
            throw e;
        }
    }, this->socket);
}

void Node::StartSocketHandler() {
    if (this->isNetWorkForwarded) {
        this->SocketHandler = new std::thread([&](Socket *socket) {
            try {
                this->NetVersion = Protocol::GetVersion(socket).version;
            } catch (std::runtime_error &e) {
                throw e;
            }
        }, this->socket);
    } else {
        this->SocketHandler = new std::thread([&](Socket *socket) {
            try {
                this->NetVersion = Protocol::GetVersion(socket).version;
            } catch (std::runtime_error &e) {
                throw e;
            }
        }, this->socket);
    }
}

std::pair<uint32_t, unsigned short> Node::GetNetData() {
    return std::pair<uint32_t, unsigned short>(this->addr, this->port);
}

Socket *Node::GetSocket() {
    return this->socket;
}