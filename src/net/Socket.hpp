//Copyright (c) 2021 Heewon Cho

#include <sys/socket.h>
#include <netinet/in.h>
#include <string>

class Socket
{
private:
    sockaddr_in sin;
public:
    Socket();
    Socket(int sin_family, int sin_port, std::string sin_addr);
};