//Copyright (c) 2021 Heewon Cho

#include "ThreadRunner.hpp"

void ThreadRunner::StartSocketListenerThread() {
    std::thread *SocketListenerThread = new std::thread(ThreadFunction::SocketListener);
    ThreadPool::AddThread(SocketListenerThread);
}

void ThreadRunner::StartSocketConnectorThread() {
    std::thread *SocketConnectorThread = new std::thread(ThreadFunction::SocketConnector);
    ThreadPool::AddThread(SocketConnectorThread);
}

void ThreadRunner::StartServerSocketHandlerThread(Socket *socket) {
    std::thread *SocketHandlerThread = new std::thread(ThreadFunction::ServerSocketHandler, socket);
    ThreadPool::AddThread(SocketHandlerThread);
}

void ThreadRunner::StartClientSocketHandlerThread(Socket *socket) {
    std::thread *SocketHandlerThread = new std::thread(ThreadFunction::ClientSocketHandler, socket);
    ThreadPool::AddThread(SocketHandlerThread);
}

void ThreadRunner::StartSocketReaderThread(Socket *socket) {
    std::thread *SocketReaderThread = new std::thread(ThreadFunction::SocketReaderThread, socket);
    ThreadPool::AddThread(SocketReaderThread);
}