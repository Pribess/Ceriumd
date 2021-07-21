//Copyright (c) 2021 Heewon Cho

#include "ThreadRunner.hpp"

void ThreadRunner::StartSocketListenerThread() {
    std::thread *SocketListenerThread = new std::thread(ThreadFunction::SocketListener);
}

void ThreadRunner::StartSocketConnectorThread() {
    std::thread *SocketConnectorThread = new std::thread(ThreadFunction::SocketConnector);
}