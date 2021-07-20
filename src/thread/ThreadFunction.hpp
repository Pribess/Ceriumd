//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_THREAD_THREADFUNCTION
#define _CERIUM_THREAD_THREADFUNCTION

#include <iostream>

#include "constant/Define.hpp"
#include "net/protocol/Protocol.hpp"
#include "net/primitive/Listener.hpp"
#include "ThreadRunner.hpp"
#include "ThreadPool.hpp"
#include "net/tools/BootStrapper.hpp"

class ThreadFunction {
    private:
    public:
        static void SocketListener();
        static void SocketConnector();

        static void ServerSocketHandler(Socket *socket);
        static void ClientSocketHandler(Socket *socket);

        static void SocketReaderThread(Socket *socket);
};

#endif