//Copyright (c) 2021 Heewon Cho

#include "ThreadRunner.hpp"

int ThreadRunner::StartSocketListenerThread() {
    std::thread *SocketListenerThread = new std::thread(ThreadFunction::SocketListener);
    ThreadPool::AddThread(SocketListenerThread);
    return 0;
}

int ThreadRunner::StartServerSocketHandlerThread(Socket *socket) {
    std::thread *SocketHandlerThread = new std::thread(ThreadFunction::ServerSocketHandler, socket);
    ThreadPool::AddThread(SocketHandlerThread);
    return 0;
}