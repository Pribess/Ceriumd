//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_THREAD_THREADFUNCTION
#define _CERIUM_THREAD_THREADFUNCTION

#include <iostream>

#include "constant/Define.hpp"
#include "net/protocol/Protocol.hpp"
#include "net/primitive/Listener.hpp"
#include "ThreadRunner.hpp"
#include "net/tools/BootStrapper.hpp"
#include "node/NodePool.hpp"

class ThreadFunction {
    private:
    public:
        static void SocketListener();
        static void SocketConnector();

        static void SocketReaderThread(Socket *socket);
        
        static void ServerSocketHandler(Socket *socket);
        static void ClientSocketHandler(Socket *socket);
};

#endif