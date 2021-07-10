//Copyright (c) 2021 Heewon Cho

#include "Connector.hpp"

Connector::Connector(char sin_addr[], int sin_port) {
    memset(&this->SinOppo, 0, sizeof(this->SinOppo));
    this->SinOppo.sin_family = AF_INET;
    this->SinOppo.sin_port = htons(sin_port);
    this->SinOppo.sin_addr.s_addr = inet_addr(sin_addr);
    this->CreateSocket();
}

Connector::Connector(in_addr_t sin_addr, int sin_port) {
    memset(&this->SinOppo, 0, sizeof(this->SinOppo));
    this->SinOppo.sin_family = AF_INET;
    this->SinOppo.sin_port = sin_port;
    this->SinOppo.sin_addr.s_addr = sin_addr;
    this->CreateSocket();
}


int Connector::CreateSocket() {
    this->SocketDesc = socket(this->SinOppo.sin_family, SOCK_STREAM, IPPROTO_TCP);
    if (0 > this->SocketDesc) {
        throw std::runtime_error("Socket Creation Failed!");
    } else {
        return 0;
    }
}

Socket *Connector::Connect() {
    if (0 > connect(this->SocketDesc, (sockaddr *)&this->SinOppo, sizeof(SinOppo))) {
        throw std::runtime_error("Socket Connection Failed!");
    } else {
        Socket *socket = new Socket(this->SocketDesc);
        return socket;
    }
}