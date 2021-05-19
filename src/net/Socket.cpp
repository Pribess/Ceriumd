//Copyright (c) 2021 Heewon Cho

#include "Socket.hpp"

#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>

Socket::Socket() {
    memset(&this->Sin, 0, sizeof(this->Sin));
    memset(&this->Sin_Client, 0, sizeof(this->Sin_Client));
}

Socket::Socket(int sin_family, int sin_port) {
    memset(&this->Sin, 0, sizeof(this->Sin));
    memset(&this->Sin_Client, 0, sizeof(this->Sin_Client));
    this->Sin.sin_family = sin_family;
    this->Sin.sin_port = htons(sin_port);
    this->Sin.sin_addr.s_addr = INADDR_ANY;
}

int Socket::CreateSocket(int type, int protocol) {
    SocketDesc = socket(this->Sin.sin_family, type, protocol);
    if (0 > SocketDesc) {
        throw std::ios_base::failure("Socket Creation Failed!");
    } else {
        return 0;
    }
}

int Socket::CloseSocket() {
    if (0 > close(this->ClientSocketDesc)) {
        throw std::ios_base::failure("Close Client Socket Failed!");
    }
    if (0 > close(this->SocketDesc)) {
        throw std::ios_base::failure("Close Server Socket Failed!");
    }
    return 0;
}

int Socket::BindSocket() {
    if (0 > bind(this->SocketDesc, (sockaddr *)&this->Sin, sizeof(sockaddr_in))) {
        throw std::ios_base::failure("Socket Bind Failed!");
    } else {
        return 0;
    }
}

int Socket::Listen() {
    if (0 > listen(this->SocketDesc, 1)) {
        throw std::ios_base::failure("Socket Listen Failed!");
    } else {
        this->LenBuff = sizeof(sockaddr_in);
        this->ClientSocketDesc = accept(this->SocketDesc, (sockaddr *)&this->Sin_Client, &LenBuff);
        if(0 > this->ClientSocketDesc) {
            throw std::ios_base::failure("Socket Accept Failed!");
        } else {
            return 0;
        }
    }
}

int Socket::SendData(int data) {
    if (0 > write(this->ClientSocketDesc, &data, sizeof(data))) {
        throw std::ios_base::failure("Write Data Failed!");
    } else {
        return 0;
    }
}

int Socket::SendData(char data[]) {
    if (0 > write(this->ClientSocketDesc, &data, sizeof(&data))) {
        throw std::ios_base::failure("Write Data Failed!");
    } else {
        return 0;
    }
}

int Socket::SendData(std::string data) {
    if (0 > write(this->ClientSocketDesc, data.c_str(), sizeof(data))) {
        throw std::ios_base::failure("Write Data Failed!");
    } else {
        return 0;
    }
}