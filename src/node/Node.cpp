//Copyright (c) 2021 Heewon Cho

#include "Node.hpp"

Node::Node(Socket *socket, uint32_t addr, unsigned short port) {
    this->socket = socket;
    this->addr = addr;
    this->port = port;
    this->isNetWorkForwarded = true;
    this->StartSocketReceiver();
}

Node::Node(Socket *socket, uint32_t addr) {
    this->socket = socket;
    this->addr = addr;
    this->isNetWorkForwarded = false;
    this->StartSocketReceiver();
}

Node::~Node() {
    this->socket->CloseSocket();
    this->SocketReceiver->detach();
}

void Node::StartSocketReceiver() {
    this->SocketReceiver = new std::thread(ThreadFunction::SocketReaderThread, this->socket);
}

std::pair<uint32_t, unsigned short> Node::GetNetData() {
    return std::pair<uint32_t, unsigned short>(this->addr, this->port);
}