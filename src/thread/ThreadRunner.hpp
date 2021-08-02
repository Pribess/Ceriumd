// Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_THREAD_THREADRUNNER
#define _CERIUM_THREAD_THREADRUNNER

#include <thread>

#include "net/Socket.hpp"
#include "node/Node.hpp"
#include "node/NodePool.hpp"
#include "net/primitive/Listener.hpp"
#include "constant/Constant.hpp"
#include "net/tools/BootStrapper.hpp"

class ThreadRunner {
    private:
    public:
        static std::thread *StartSocketListenerThread();
        static std::thread *StartSocketConnectorThread();
};

#endif