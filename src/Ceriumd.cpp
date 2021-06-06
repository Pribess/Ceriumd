//Copyright (c) 2021 Heewon Cho

#include <iostream>

#include "tools/TimeStamp.hpp"
#include "crypto/Crypto.hpp"
#include "tools/CastingTools.hpp"
#include "thread/ThreadRunner.hpp"
#include "database/primitive/Sqlite.hpp"
#include "net/protocol/Protocol.hpp"

namespace Initializer {

    void NetInit() {
        ThreadRunner::StartSocketListenerThread();
    }

}

void AppInit() {
    Initializer::NetInit();
}

void ArgParser(int argc, char *argv[]) {
    std::vector<char *> args;
    
    for (char cnt = 0 ; cnt < argc ; cnt++) {
        args.push_back(argv[cnt]);
    }


}

void SetupEnvironment() {
    setlocale(LC_ALL, "");
}

int main(int argc, char *argv[]) {
    std::cout << "   ___          _                 \n  / __\\___ _ __(_)_   _ _ __ ___  \n / /  / _ \\ '__| | | | | '_ ` _ \\\n/ /__|  __/ |  | | |_| | | | | | |\n\\____/\\___|_|  |_|\\__,_|_| |_| |_|" << std::endl;
    SetupEnvironment();
    ArgParser(argc, argv);
    AppInit();
    std::cout << TimeStamp::GetUtcTimeStamp() << std::endl;
    /*Connector *cn = new Connector("192.168.0.24", 1226);
    std::pair<std::string, Socket *> p1;
    p1 = cn->Connect();
    Protocol::Version(p1.second);*/
    return 0;
}