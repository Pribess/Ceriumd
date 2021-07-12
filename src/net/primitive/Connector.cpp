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

int Connector::ConnectWithTimeout(int sd, const sockaddr *addrst, socklen_t socklen, unsigned long time) {
    fd_set writefds;
    FD_ZERO(&writefds);

    int flags = fcntl(sd, F_GETFL);
    flags = (flags | O_NONBLOCK);
    if (0 != fcntl(sd, F_SETFL, flags)) {
        return -1;
    }

    if (0 != connect(sd, addrst, socklen)) {
        if (errno != EINPROGRESS)
        {
            return -1;
        }
    }

    timeval timeout;
    timeout.tv_sec = time / 1000;
    timeout.tv_usec = (time % 1000) * 1000;
    FD_SET(sd, &writefds);
    if (0 >= select(sd+1, NULL, &writefds, NULL, &timeout)) {
        return -1;
    }
    
    int err;
    socklen_t len = sizeof(err);
    getsockopt(sd, SOL_SOCKET, SO_ERROR, (char *)&err, &len);
    if (err) {
        return -1;
    }

    flags = fcntl(sd, F_GETFL);
    flags = (flags & ~O_NONBLOCK);
    if (0 != fcntl(sd, F_SETFL, flags)) {
        return -1;
    }
    return 0;
}

Socket *Connector::Connect() {
    if (0 > fcntl(this->SocketDesc, F_SETFL, O_NONBLOCK)) {
        throw std::runtime_error("Alter Socket Mode Failed!");
    }
    if (0 > Connector::ConnectWithTimeout(this->SocketDesc, (sockaddr *)&this->SinOppo, sizeof(SinOppo), 1000)) {
        throw std::runtime_error("Socket Connecting Failed!");
    } else {
        Socket *socket = new Socket(this->SocketDesc);
        return socket;
    }
}