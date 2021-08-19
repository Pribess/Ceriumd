// Copyright (c) 2021 Heewon Cho

#include "Connection.hpp"

Connection::Connection(Socket *socket) {
    this->socket = socket;
}

int Connection::CloseConnection() {
    return this->socket->CloseSocket();
}

int Connection::SendData(std::vector<unsigned char> data) {
    return this->socket->SendData(data);
}

unsigned char *Connection::RecvData() {
    return this->socket->RecvData();
}

void Connection::PushToQueue(unsigned char *data) {
    this->queue.front()->set_value(data);
}

unsigned char *Connection::ResData() {
    try {
        std::promise<unsigned char *> *promise = new std::promise<unsigned char *>;
        this->queue.push(promise);
        std::future<unsigned char *> future = queue.front()->get_future();
        future.wait();
        static unsigned char *data = future.get();
        delete queue.front();
        queue.pop();
        return data;
    } catch (std::exception e) {
        throw e;
    }
}