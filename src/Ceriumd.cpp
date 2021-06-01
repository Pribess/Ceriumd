//Copyright (c) 2021 Heewon Cho

#include <iostream>

#include "tools/TimeStamp.hpp"
#include "crypto/Crypto.hpp"
#include "tools/CastingTools.hpp"

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
    std::cout << TimeStamp::GetUtcTimeStamp() <<std::endl;
    return 0;
}