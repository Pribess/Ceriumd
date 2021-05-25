//Copyright (c) 2021 Heewon Cho

#include <netinet/in.h>
#include <string>
#include <cstddef>

#include "net/Socket.hpp"

class Listener {
private:
    socklen_t LenBuff;
    int ListenSocketDesc;
    int SocketDesc;
    sockaddr_in Sin;
    sockaddr_in SinOppo;
    char Buff[256];
    int CreateSocket();
    int BindSocket();
    int CloseSocket();
public:
    Listener(int sin_port);
    ~Listener();
    int Listen();
    std::pair<std::string, Socket*> GetConnection();
};