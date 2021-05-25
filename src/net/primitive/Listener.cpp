//Copyright (c) 2021 Heewon Cho

#include "Listener.hpp"

#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>

Listener::Listener(int sin_port) {
    memset(&this->Sin, 0, sizeof(this->Sin));
    memset(&this->SinOppo, 0, sizeof(this->SinOppo));
    this->Sin.sin_family = AF_INET;
    this->Sin.sin_port = htons(sin_port);
    this->Sin.sin_addr.s_addr = htonl(INADDR_ANY);
    this->CreateSocket();
    this->BindSocket();
}

Listener::~Listener() {
    this->CloseSocket();
}

int Listener::CreateSocket() {
    char cnt = 5;
    while (cnt) {
        this->ListenSocketDesc = socket(this->Sin.sin_family, SOCK_STREAM, IPPROTO_TCP);
        if (0 > this->ListenSocketDesc) {
            cnt--;
        } else {
            const int arg = 1;
            if (0 > setsockopt(this->ListenSocketDesc, SOL_SOCKET, SO_REUSEADDR, &arg, sizeof(arg))) {
                throw std::ios_base::failure("Set Socket Option Failed!");
            } else {
                return 0;
            }
        }
    }
    throw std::ios_base::failure("Socket Creation Failed!");
}

int Listener::CloseSocket() {
    if (0 > close(this->ListenSocketDesc)) {
        return -1;
    }
    return 0;
}

int Listener::BindSocket() {
    char cnt = 5;
    while (cnt) {
        if (0 > bind(this->ListenSocketDesc, (sockaddr *)&this->Sin, sizeof(sockaddr_in))) {
            cnt--;
        } else {
            return 0;
        }
    }
    throw std::ios_base::failure("Socket Bind Failed!");
}

int Listener::Listen() {
    this->LenBuff = sizeof(sockaddr_in);;
    if (0 > listen(this->ListenSocketDesc, 1)) {
        throw std::ios_base::failure("Socket Listen Failed!");
    } else {
        this->SocketDesc = accept(this->ListenSocketDesc, (sockaddr *)&this->SinOppo, &LenBuff);
        if(0 > this->SocketDesc) {
            throw std::ios_base::failure("Socket Accept Failed!");
        } else {
            return 0;
        }
    }
}

std::pair<std::string, Socket *> Listener::GetConnection() {
    Socket *socket = new Socket(this->SocketDesc);
    return std::pair<std::string, Socket *>(std::string(inet_ntoa(this->SinOppo.sin_addr)), socket);
}