//Copyright (c) 2021 Heewon Cho

#include <sys/socket.h>
#include <netinet/in.h>
#include <string>
#include <cstddef>

class Socket
{
private:
    socklen_t LenBuff;
    int SocketDesc;
    int OppoSocketDesc;
    sockaddr_in Sin;
    sockaddr_in Sin_Oppo;
    char Buff[256];
public:
    Socket(int sin_port);
    Socket(int sin_port, char sin_addr[]);
    int CreateSocket(int type, int protocol);
    int BindSocket();
    int Listen();
    int CloseSocket();
    int SendData(int data);
    int SendData(char data[]);
    int SendData(std::string data);
    char *RecvData();
};