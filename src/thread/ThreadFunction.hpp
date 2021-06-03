//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_THREAD_THREADFUNCTION
#define _CERIUM_THREAD_THREADFUNCTION

#include <iostream>

#include "constant/Define.hpp"
#include "net/tools/ConnectionPool.hpp"
#include "net/protocol/Protocol.hpp"
#include "ThreadRunner.hpp"
#include "ThreadPool.hpp"

class ThreadFunction {
    private:
    public:
        static void SocketListener();
        static void ServerSocketHandler(Socket *socket);
};

#endif