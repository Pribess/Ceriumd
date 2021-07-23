//Copyright (c) 2021 Heewon Cho

#include "ThreadRunner.hpp"

std::thread *ThreadRunner::StartSocketListenerThread() {
    return new std::thread(ThreadFunction::SocketListener);
}

std::thread *ThreadRunner::StartSocketConnectorThread() {
    return  new std::thread(ThreadFunction::SocketConnector);
}