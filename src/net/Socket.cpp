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
    std::cout << "Send: " << CastingTools::ctoh(data.data(), data.size()) << std::endl;
    char cnt = 5;
    if (0 > write(this->SocketDesc, data.data(), data.size())) {
        throw std::runtime_error("Write Data Failed!");
    } else {
        return 0;
    }
}

unsigned char *Socket::RecvData() {
    char cnt = 5;
    memset(this->buff, 0, sizeof(this->buff));
    if (0 > read(this->SocketDesc, this->buff, sizeof(this->buff))) {
        throw std::runtime_error("Recieve Data Failed!");
    } else {
        std::cout << "Recv: " << CastingTools::ctoh(this->buff, 20) << std::endl;
        return this->buff;
    }
}

void Socket::PushToQueue(unsigned char *data) {
    this->queue.push(data);
}

unsigned char *Socket::ResData() {
    try {
        std::mutex mu;
        std::unique_lock<std::mutex> ul(mu);
        this->cv.wait(ul);
        unsigned char *data = queue.front();
        queue.pop();
        return data;
    } catch (std::exception e) {
        throw e;
    }
}