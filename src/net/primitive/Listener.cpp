// Copyright (c) 2021 Heewon Cho

#include "Listener.hpp"

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
    this->ListenSocketDesc = socket(this->Sin.sin_family, SOCK_STREAM, IPPROTO_TCP);
    if (0 > this->ListenSocketDesc) {
        throw std::runtime_error("Socket Creation Failed!");
    } else {
        const int arg = 1;
        if (0 > setsockopt(this->ListenSocketDesc, SOL_SOCKET, SO_REUSEADDR, &arg, sizeof(arg))) {
            throw std::runtime_error("Set Socket Option Failed!");
        } else {
            return 0;
        }
    }
}

int Listener::CloseSocket() {
    if (0 > close(this->ListenSocketDesc)) {
        return -1;
    }
    return 0;
}

int Listener::BindSocket() {
    if (0 > bind(this->ListenSocketDesc, (sockaddr *)&this->Sin, sizeof(sockaddr_in))) {
        throw std::runtime_error("Socket Bind Failed!");
    } else {
        return 0;
    }
}

std::pair<Socket *, uint32_t> Listener::Listen() {
    this->LenBuff = sizeof(sockaddr_in);;
    if (0 > listen(this->ListenSocketDesc, 1)) {
        throw std::runtime_error("Socket Listen Failed!");
    } else {
        this->SocketDesc = accept(this->ListenSocketDesc, (sockaddr *)&this->SinOppo, &LenBuff);
        if(0 > this->SocketDesc) {
            throw std::runtime_error("Socket Accept Failed!");
        } else {
            Socket *socket = new Socket(this->SocketDesc);
            return std::pair<Socket *, uint32_t>(socket, SinOppo.sin_addr.s_addr);
        }
    }
}