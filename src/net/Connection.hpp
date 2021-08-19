// Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_NET_CONNECTION
#define _CERIUM_NET_CONNECTION

#include "primitive/Socket.hpp"

class Connection {
    private:
        Socket *socket;
        std::queue<std::promise<unsigned char *> *> queue;
    public:
        Connection(Socket *socket);
        ~Connection();

        int CloseConnection();

        int SendData(std::vector<unsigned char> data);
        unsigned char *RecvData();

        void PushToQueue(unsigned char *data);
        unsigned char *ResData();
};

#endif