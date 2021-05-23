//Copyright (c) 2021 Heewon Cho

#include "ClientSocket.hpp"

#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>

ClientSocket::ClientSocket(int sin_port, char sin_addr[]) {
    memset(&this->SinOppo, 0, sizeof(this->SinOppo));
    this->SinOppo.sin_family = AF_INET;
    this->SinOppo.sin_port = htons(sin_port);
    this->SinOppo.sin_addr.s_addr = inet_addr(sin_addr);
    this->CreateSocket();
    this->Connect();
}

ClientSocket::~ClientSocket() {
    this->CloseSocket();
}

int ClientSocket::CreateSocket() {
    char cnt = 5;
    while (cnt) {
        this->SocketDesc = socket(this->SinOppo.sin_family, SOCK_STREAM, IPPROTO_TCP);
        if (0 > this->SocketDesc) {
            cnt--;
        } else {
            return 0;
        }
    }
    throw std::ios_base::failure("Socket Creation Failed!");
}

int ClientSocket::CloseSocket() {
    if (0 > close(this->SocketDesc)) {
        return -1;
    }
    return 0;
}

int ClientSocket::Connect() {
    char cnt = 5;
    while (cnt) {
        if (0 > connect(this->SocketDesc, (sockaddr *)&this->SinOppo, sizeof(SinOppo))) {
            cnt--;
        } else {
            return 0;
        }
    }
    return -1;
}

int ClientSocket::SendData(int data) {
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

int ClientSocket::SendData(char data[]) {
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

int ClientSocket::SendData(std::string data) {
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

char *ClientSocket::RecvData() {
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