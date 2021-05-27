//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_THREAD_THREADFUNCTION
#define _CERIUM_THREAD_THREADFUNCTION

#include <iostream>

#include "constant/Define.hpp"
#include "net/ConnectionPool.hpp"
#include "ThreadPool.hpp"

class ThreadFunction {
    private:
    public:
        static void SocketListener();
};

#endif