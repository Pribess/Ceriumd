//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_THREAD_THREADRUNNER
#define _CERIUM_THREAD_THREADRUNNER

#include <thread>

#include "ThreadFunction.hpp"
#include "ThreadPool.hpp"

class ThreadRunner {
    private:
    public:
        static void StartSocketListenerThread();
        static void StartSocketConnectorThread();

        static void StartServerSocketHandlerThread(Socket *socket);
        static void StartClientSocketHandlerThread(Socket *socket);
        
        static void StartSocketReaderThread(Socket *socket);
};

#endif