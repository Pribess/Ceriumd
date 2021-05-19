//Copyright (c) 2021 Heewon Cho

#include "Socket.hpp"

#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>

Socket::Socket() {
    memset(&this->Sin, 0, sizeof(this->Sin));
}

Socket::Socket(int sin_family, int sin_port, std::string sin_addr) {
    memset(&this->Sin, 0, sizeof(this->Sin));
    this->Sin.sin_family = sin_family;
    this->Sin.sin_port = htons(sin_port);
    this->Sin.sin_addr.s_addr = inet_addr(sin_addr.c_str());
}

int Socket::CreateSocket(int type, int protocol) {
    SocketDesc = socket(this->Sin.sin_family, type, protocol);
    if (0 > SocketDesc) {
        throw std::ios_base::failure("Socket Creation Failed!");
    } else {
        return 0;
    }
}

int Socket::BindSocket() {
    if(0 > bind(this->SocketDesc, (sockaddr *)&this->Sin, sizeof(sockaddr_in))) {
        throw std::ios_base::failure("Socket Bind Failed!");
    } else {
        return 0;
    }
}

int Socket::Listen(int backlog) {
    if(0 > listen(this->SocketDesc, backlog)) {
        throw std::ios_base::failure("Socket Listen Failed!");
    } else {
        return 0;
    }
}