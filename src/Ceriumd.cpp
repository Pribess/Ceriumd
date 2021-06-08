//Copyright (c) 2021 Heewon Cho

#include <iostream>
#include <dirent.h>

#include "thread/ThreadRunner.hpp"
#include "data/primitive/Sqlite.hpp"
#include "data/DatabasePool.hpp"
#include "constant/KeyValue.hpp"

namespace Initializer {

    void NetInit() {
        ThreadRunner::StartSocketListenerThread();
    }

}

namespace Tools {

    void CheckDirExist(std::string dirname) {
        if (access(dirname.c_str(), F_OK)) {
            std::cout << "Ceriumd: " << dirname << ": No such file or directory" << std::endl;
            exit(1);
        }
    }

}

void AppInit() {
    Initializer::NetInit();
}

void ArgParser(int argc, char *argv[]) {
    std::vector<std::string> args;
    
    if (argc < 2) {
        std::cout << "Ceriumd: Usage <directory>" << std::endl; 
        exit(1);
    }

    for (char cnt = 0 ; cnt < argc ; cnt++) {
        args.push_back(argv[cnt]);
    }

    std::vector<std::string>::iterator iter = args.begin();

    Tools::CheckDirExist(iter[1]); 
    if (!iter[1].ends_with("/")) {
        iter[1].append("/");
    }

    KeyValue::SetKeyValue("DataDir", iter[1]);
}

void SetupEnvironment() {
    setlocale(LC_ALL, "");
    DatabasePool::SetUpDatabases();
}

int main(int argc, char *argv[]) {
    std::cout << "   ___          _                 \n  / __\\___ _ __(_)_   _ _ __ ___  \n / /  / _ \\ '__| | | | | '_ ` _ \\\n/ /__|  __/ |  | | |_| | | | | | |\n\\____/\\___|_|  |_|\\__,_|_| |_| |_|" << std::endl;
    ArgParser(argc, argv);
    SetupEnvironment();
    AppInit();
    std::cout << TimeStamp::GetUtcTimeStamp() << std::endl;
    /*Connector *cn = new Connector("192.168.0.24", 1226);
    std::pair<std::string, Socket *> p1;
    p1 = cn->Connect();
    Protocol::Version(p1.second);*/
    return 0;
}