//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_THREAD_THREADRUNNER
#define _CERIUM_THREAD_THREADRUNNER

#include <thread>

#include "ThreadFunction.hpp"
#include "ThreadPool.hpp"

class ThreadRunner {
    private:
    public:
        static int StartSocketListenerThread();
};

#endif