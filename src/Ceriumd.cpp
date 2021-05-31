//Copyright (c) 2021 Heewon Cho

#include <iostream>

#include <chrono>

namespace Initializer {

    int NetInit() {
        
        return 0;
    }

    int AppInit() {
        NetInit();
        return 0;
    }

}


int SetupEnvironment() {
    return 0;
}

int main(int argc, char* argv[]) {
    std::cout << "   ___          _                 \n  / __\\___ _ __(_)_   _ _ __ ___  \n / /  / _ \\ '__| | | | | '_ ` _ \\\n/ /__|  __/ |  | | |_| | | | | | |\n\\____/\\___|_|  |_|\\__,_|_| |_| |_|" << std::endl;
    SetupEnvironment();
    Initializer::AppInit();
    std::cout << std::chrono::duration_cast<std::chrono::seconds>(
    std::chrono::system_clock::now().time_since_epoch()).count() << std::endl;
    return 0;
}