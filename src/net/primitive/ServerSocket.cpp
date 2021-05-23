//Copyright (c) 2021 Heewon Cho

#include "ServerSocket.hpp"

#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>

ServerSocket::ServerSocket(int sin_port) {
    memset(&this->Sin, 0, sizeof(this->Sin));
    memset(&this->SinOppo, 0, sizeof(this->SinOppo));
    this->Sin.sin_family = AF_INET;
    this->Sin.sin_port = htons(sin_port);
    this->Sin.sin_addr.s_addr = htonl(INADDR_ANY);
    this->CreateSocket();
    this->BindSocket();
    this->Listen();
}

ServerSocket::~ServerSocket() {
    this->CloseSocket();
}

int ServerSocket::CreateSocket() {
    char cnt = 5;
    while (cnt) {
        this->SocketDesc = socket(this->Sin.sin_family, SOCK_STREAM, IPPROTO_TCP);
        if (0 > this->SocketDesc) {
            cnt--;
        } else {
            const int arg = 1;
            if (0 > setsockopt(this->SocketDesc, SOL_SOCKET, SO_REUSEADDR, &arg, sizeof(arg))) {
                throw std::ios_base::failure("Set Socket Option Failed!");
            } else {
                return 0;
            }
        }
    }
    throw std::ios_base::failure("Socket Creation Failed!");
}

int ServerSocket::CloseSocket() {
    if (0 > close(this->OppoSocketDesc)) {
        return -1;
    }
    if (0 > close(this->SocketDesc)) {
        return -1;
    }
    return 0;
}

int ServerSocket::BindSocket() {
    char cnt = 5;
    while (cnt) {
        if (0 > bind(this->SocketDesc, (sockaddr *)&this->Sin, sizeof(sockaddr_in))) {
            cnt--;
        } else {
            return 0;
        }
    }
    throw std::ios_base::failure("Socket Bind Failed!");
}

int ServerSocket::Listen() {
    this->LenBuff = sizeof(sockaddr_in);;
    if (0 > listen(this->SocketDesc, 1)) {
        throw std::ios_base::failure("Socket Listen Failed!");
    } else {
        this->OppoSocketDesc = accept(this->SocketDesc, (sockaddr *)&this->SinOppo, &LenBuff);
        if(0 > this->OppoSocketDesc) {
            throw std::ios_base::failure("Socket Accept Failed!");
        } else {
            return 0;
        }
    }
}

int ServerSocket::SendData(int data) {
    char cnt =5;
    while (cnt) {
        if (0 > write(this->OppoSocketDesc, &data, sizeof(data))) {
            cnt--;
        } else {
            return 0;
        }
    }
    throw std::ios_base::failure("Write Data Failed!");
}

int ServerSocket::SendData(char data[]) {
    char cnt = 5;
    while (cnt) {
        if (0 > write(this->OppoSocketDesc, data, sizeof(&data))) {
            cnt--;
        } else {
            return 0;
        }
    }
    throw std::ios_base::failure("Write Data Failed!");
}

int ServerSocket::SendData(std::string data) {
    char cnt = 5;
    while (cnt) {
        if (0 > write(this->OppoSocketDesc, data.c_str(), sizeof(data))) {
            cnt--;
        } else {
            return 0;
        }
    }
    throw std::ios_base::failure("Write Data Failed!");
}

char *ServerSocket::RecvData() {
    char cnt = 5;
    memset(this->Buff, 0, sizeof(this->Buff));
    while (cnt) {
        if (0 > read(this->OppoSocketDesc, this->Buff, sizeof(this->Buff))) {
            cnt--;
        } else {
            return this->Buff;
        }
    }
    throw std::ios_base::failure("Recieve Data Failed!");
}