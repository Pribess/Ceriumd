//Copyright (c) 2021 Heewon Cho

#include <iostream>

#include "tools/TimeStamp.hpp"
#include "crypto/Crypto.hpp"
#include "tools/CastingTools.hpp"
#include "thread/ThreadRunner.hpp"
#include "database/primitive/Sqlite.hpp"
#include "net/protocol/Protocol.hpp"

namespace Initializer {

    int NetInit() {
        ThreadRunner::StartSocketListenerThread();
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
    std::cout << TimeStamp::GetUtcTimeStamp() << std::endl;
    /*Connector *cn = new Connector("192.168.0.24", 1226);
    std::pair<std::string, Socket *> p1;
    p1 = cn->Connect();
    Protocol::Version(p1.second);*/
    return 0;
}