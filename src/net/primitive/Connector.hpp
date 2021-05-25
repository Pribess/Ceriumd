//Copyright (c) 2021 Heewon Cho

#include <netinet/in.h>
#include <string>
#include <cstddef>

class Connector {
private:
    socklen_t BuffLen;
    int SocketDesc;
    sockaddr_in SinOppo;
    char Buff[256];
    int CreateSocket();
    int Connect();
    int CloseSocket();
public:
    Connector(int sin_port, char sin_addr[]);
    int GetDesc();
};