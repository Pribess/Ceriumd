//Copyright (c) 2021 Heewon Cho

#include "Node.hpp"

Node::Node(Socket *socket, uint32_t addr, unsigned short port) {
    this->socket = socket;
    this->addr = addr;
    this->port = port;
}

Node::~Node() {
    this->socket->CloseSocket();
}