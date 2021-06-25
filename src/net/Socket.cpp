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
    std::cout << CastingTools::ctoh(data.data(), data.size()) << std::endl;
    while (cnt) {
        if (0 > write(this->SocketDesc, data.data(), data.size())) {
            cnt--;
        } else {
            return 0;
        }
    }
    throw std::ios_base::failure("Write Data Failed!");
}

unsigned char *Socket::RecvData() {
    char cnt = 5;
    memset(this->buff, 0, sizeof(this->buff));
    while (cnt) {
        if (0 > read(this->SocketDesc, this->buff, sizeof(this->buff))) {
            cnt--;
        } else {
            std::cout << CastingTools::ctoh(this->buff, 20) << std::endl;
            return this->buff;
        }
    }
    throw std::ios_base::failure("Recieve Data Failed!");
}

void Socket::PushToQueue(unsigned char *data) {
    this->queue.push(data);
}

unsigned char *Socket::ResData() {
    std::mutex mu;
    std::unique_lock<std::mutex> ul(mu);
    this->cv.wait(ul);
    unsigned char *data = queue.front();
    queue.pop();
    return data;
}