//Copyright (c) 2021 Heewon Cho

#include "ThreadRunner.hpp"

void ThreadRunner::StartSocketListenerThread() {
    std::thread *SocketListenerThread = new std::thread(ThreadFunction::SocketListener);
    ThreadPool::AddThread(SocketListenerThread);
}

void ThreadRunner::StartSocketConnectorThread(Socket *socket) {
    std::thread *SocketConnectorThread = new std::thread(ThreadFunction::SocketConnector, socket);
    ThreadPool::AddThread(SocketConnectorThread);
}

void ThreadRunner::StartServerSocketHandlerThread(Socket *socket) {
    std::thread *SocketHandlerThread = new std::thread(ThreadFunction::ServerSocketHandler, socket);
    ThreadPool::AddThread(SocketHandlerThread);
}