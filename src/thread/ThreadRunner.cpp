// Copyright (c) 2021 Heewon Cho

#include "ThreadRunner.hpp"

std::thread *ThreadRunner::StartSocketListenerThread() {
    return new std::thread([]() {
        try {
            Listener *listener = new Listener(CERIUM_PORT);
            while (true) {
                std::pair<Socket *, uint32_t> buff = listener->Listen();
                Node *node = new Node(buff.first, buff.second);
                NodePool::AddNode(node);
            }
            delete listener;
        } catch (std::runtime_error &e) {
            throw e;
        }
    });
}

std::thread *ThreadRunner::StartSocketConnectorThread() {
    return new std::thread([]() {
        try {
            std::pair<Socket *, std::pair<uint32_t, unsigned short>> buff = BootStrapper::BootStrap();
            std::cout << "Bootstraped With : " << std::hex<< buff.second.first << "/" << buff.second.second << std::endl;
            Node *node = new Node(buff.first, buff.second.first, buff.second.second);
            NodePool::AddNode(node);
        } catch (std::runtime_error &e) {
            throw e;
        } 
    });
}