// Copyright (c) 2021 Heewon Cho

#include "Node.hpp"

Node::Node(Connection *con, uint32_t addr, unsigned short port) {
    this->con = con;
    this->addr = addr;
    this->port = port;
    this->isNetWorkForwarded = true;
    this->StartSocketReceiver();
    this->StartSocketHandler();
}

Node::Node(Connection *con, uint32_t addr) {
    this->con = con;
    this->addr = addr;
    this->isNetWorkForwarded = false;
    this->StartSocketReceiver();
    this->StartSocketHandler();
}

Node::~Node() {
    this->con->CloseConnection();
    this->SocketReceiver->detach();
}

void Node::StartSocketReceiver() {
    this->SocketReceiver = new std::thread([&]() {
        try {
            while (true) {
                if (PacketDecoder::PacketHandler(this->con->RecvData(), this->con)) {
                    NodePool::RemoveNode(this);
                    return;
                }
            }
        } catch (std::runtime_error &e) {
            throw e;
        }
    });
}

void Node::StartSocketHandler() {
    if (this->isNetWorkForwarded) {
        this->SocketHandler = new std::thread([&]() {
            try {
                this->NetVersion = Protocol::GetVersion(this->con).version;
            } catch (std::runtime_error &e) {
                throw e;
            }
        });
    } else {
        this->SocketHandler = new std::thread([&]() {
            try {
                this->NetVersion = Protocol::GetVersion(this->con).version;
            } catch (std::runtime_error &e) {
                throw e;
            }
        });
    }
}

std::pair<uint32_t, unsigned short> Node::GetNetData() {
    return std::pair<uint32_t, unsigned short>(this->addr, this->port);
}

Connection *Node::GetConnection() {
    return this->con;
}