//Copyright (c) 2021 Heewon Cho

#include "Socket.hpp"

#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>

Socket::Socket(int sin_family, int sin_port) {
    memset(&this->Sin, 0, sizeof(this->Sin));
    memset(&this->Sin_Client, 0, sizeof(this->Sin_Client));
    this->Sin.sin_family = sin_family;
    this->Sin.sin_port = htons(sin_port);
    this->Sin.sin_addr.s_addr = htonl(INADDR_ANY);
}

int Socket::CreateSocket(int type, int protocol) {
    char cnt = 5;
    this->SocketDesc = socket(this->Sin.sin_family, type, protocol);
    while (cnt) {
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
    char cnt =5;
    while (cnt) {
        if (0 > write(this->ClientSocketDesc, &data, sizeof(data))) {
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
        if (0 > write(this->ClientSocketDesc, &data, sizeof(&data))) {
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
        if (0 > write(this->ClientSocketDesc, data.c_str(), sizeof(data))) {
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
        if (0 > read(this->ClientSocketDesc, this->Buff, sizeof(this->Buff))) {
            cnt--;
        } else {
            return this->Buff;
        }
    }
    throw std::ios_base::failure("Recieve Data Failed!");
}