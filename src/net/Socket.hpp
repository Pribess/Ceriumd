//Copyright (c) 2021 Heewon Cho

#include <sys/socket.h>
#include <netinet/in.h>
#include <string>

class Socket
{
private:
    int SocketDesc;
    sockaddr_in Sin;
public:
    Socket();
    Socket(int sin_family, int sin_port, std::string sin_addr);
    int CreateSocket(int type, int protocol);
    int BindSocket();
    int Listen(int backlog);
};