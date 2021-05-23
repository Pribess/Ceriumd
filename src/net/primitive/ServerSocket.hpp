//Copyright (c) 2021 Heewon Cho

#include <netinet/in.h>
#include <string>
#include <cstddef>

class ServerSocket {
private:
    socklen_t LenBuff;
    int SocketDesc;
    int OppoSocketDesc;
    sockaddr_in Sin;
    sockaddr_in SinOppo;
    char Buff[256];
    int CreateSocket();
    int BindSocket();
    int Listen();
    int CloseSocket();
public:
    ServerSocket(int sin_port);
    ~ServerSocket();
    int SendData(int data);
    int SendData(char data[]);
    int SendData(std::string data);
    char *RecvData();
};