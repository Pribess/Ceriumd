//Copyright (c) 2021 Heewon Cho

#include <sys/socket.h>
#include <netinet/in.h>
#include <string>

class Socket
{
private:
    socklen_t LenBuff;
    int SocketDesc;
    int ClientSocketDesc;
    sockaddr_in Sin;
    sockaddr_in Sin_Client;
    char Buff[256];
public:
    Socket(int sin_family, int sin_port);
    int CreateSocket(int type, int protocol);
    int BindSocket();
    int Listen();
    int CloseSocket();
    int SendData(int data);
    int SendData(char data[]);
    int SendData(std::string data);
    char *RecvData();
};