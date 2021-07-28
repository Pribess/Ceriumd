//Copyright (c) 2021 Heewon Cho

#include "Socket.hpp"
#include "tools/CastingTools.hpp"

Socket::Socket(int SocketDesc) {
    this->SocketDesc = SocketDesc;
}

Socket::~Socket() {
    this->CloseSocket();
}

int Socket::CloseSocket() {
    if (0 > close(this->SocketDesc)) {
        return -1;
    }
    return 0;
}

int Socket::SendData(std::vector<unsigned char> data) {
    char cnt = 5;
    if (0 > send(this->SocketDesc, data.data(), data.size(), MSG_NOSIGNAL)) {
        throw std::runtime_error("Send Data Failed!");
    } else {
        std::cout << "Send: " << CastingTools::ctoh(data.data(), data.size()) << std::endl;
        return 0;
    }
}

unsigned char *Socket::RecvData() {
    char cnt = 5;
    if (0 > recv(this->SocketDesc, this->buff, sizeof(this->buff), MSG_NOSIGNAL)) {
        throw std::runtime_error("Recv Data Failed!");
    } else {
        std::cout << "Recv: " << CastingTools::ctoh(this->buff, 20) << std::endl;
        return this->buff;
    }
}

void Socket::PushToQueue(unsigned char *data) {
    this->queue.front()->set_value(data);
}

unsigned char *Socket::ResData() {
    try {
        std::promise<unsigned char *> *promise = new std::promise<unsigned char *>;
        this->queue.push(promise);
        std::future<unsigned char *> future = queue.front()->get_future();
        static unsigned char *data = future.get();
        delete queue.front();
        queue.pop();
        return data;
    } catch (std::exception e) {
        throw e;
    }
}