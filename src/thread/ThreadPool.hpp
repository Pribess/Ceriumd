//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_THREAD_THREADPOOL
#define _CERIUM_THREAD_THREADPOOL

#include <vector>
#include <thread>

class ThreadPool {
    private:
        static std::vector<std::thread *> ThreadContainer;
    public:
        static void AddThread(std::thread *thread);
        static int GetLength();
};

#endif