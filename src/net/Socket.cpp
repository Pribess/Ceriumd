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

int Socket::SendData(int data, size_t size) {
    char cnt =5;
    while (cnt) {
        if (0 > write(this->SocketDesc, &data, size)) {
            cnt--;
        } else {
            return 0;
        }
    }
    throw std::ios_base::failure("Write Data Failed!");
}

int Socket::SendData(char *data, size_t size) {
    char cnt = 5;
    while (cnt) {
        if (0 > write(this->SocketDesc, data, size)) {
            cnt--;
        } else {
            return 0;
        }
    }
    throw std::ios_base::failure("Write Data Failed!");
}

std::pair<char *, size_t> Socket::RecvData() {
    char cnt = 5;
    memset(this->buff, 0, sizeof(this->buff));
    while (cnt) {
        if (0 > read(this->SocketDesc, this->buff, sizeof(this->buff))) {
            cnt--;
        } else {
            return std::pair<char *, size_t>(this->buff, sizeof(this->buff));
        }
    }
    throw std::ios_base::failure("Recieve Data Failed!");
}