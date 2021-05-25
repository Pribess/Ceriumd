//Copyright (c) 2021 Heewon Cho

#include "Socket.hpp"

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

int Socket::SendData(int data) {
    char cnt =5;
    while (cnt) {
        if (0 > write(this->SocketDesc, &data, sizeof(data))) {
            cnt--;
        } else {
            return 0;
        }
    }
    throw std::ios_base::failure("Write Data Failed!");
}

int Socket::SendData(char data[]) {
    char cnt = 5;
    while (cnt) {
        if (0 > write(this->SocketDesc, data, sizeof(&data))) {
            cnt--;
        } else {
            return 0;
        }
    }
    throw std::ios_base::failure("Write Data Failed!");
}

int Socket::SendData(std::string data) {
    char cnt = 5;
    while (cnt) {
        if (0 > write(this->SocketDesc, data.c_str(), sizeof(data))) {
            cnt--;
        } else {
            return 0;
        }
    }
    throw std::ios_base::failure("Write Data Failed!");
}

char *Socket::RecvData() {
    char cnt = 5;
    memset(this->Buff, 0, sizeof(this->Buff));
    while (cnt) {
        if (0 > read(this->SocketDesc, this->Buff, sizeof(this->Buff))) {
            cnt--;
        } else {
            return this->Buff;
        }
    }
    throw std::ios_base::failure("Recieve Data Failed!");
}