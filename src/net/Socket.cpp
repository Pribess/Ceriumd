//Copyright (c) 2021 Heewon Cho

#include "Socket.hpp"

#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>

Socket::Socket() {
    memset(&this->sin, 0, sizeof(this->sin));
}

Socket::Socket(int sin_family, int sin_port, std::string sin_addr) {
    memset(&this->sin, 0, sizeof(this->sin));
    this->sin.sin_family = sin_family;
    this->sin.sin_port = htons(sin_port);
    this->sin.sin_addr.s_addr = inet_addr(sin_addr.c_str());
}