//Copyright (c) 2021 Heewon Cho

#include "ThreadRunner.hpp"

int ThreadRunner::StartSocketListenerThread() {
    std::thread *SocketListenerThread = new std::thread(ThreadFunction::SocketListener);
    SocketListenerThread->join();
    return 0;
}