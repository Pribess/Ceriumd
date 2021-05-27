//Copyright (c) 2021 Heewon Cho

#include <iostream>

#include "thread/ThreadRunner.hpp"

int SetupEnvironment() {
    ThreadRunner::StartSocketListenerThread();
    return 0;
}

int main(int argc, char* argv[]) {
    std::cout << "   ___          _                 \n  / __\\___ _ __(_)_   _ _ __ ___  \n / /  / _ \\ '__| | | | | '_ ` _ \\\n/ /__|  __/ |  | | |_| | | | | | |\n\\____/\\___|_|  |_|\\__,_|_| |_| |_|" << std::endl;
    SetupEnvironment();
    return 0;
}