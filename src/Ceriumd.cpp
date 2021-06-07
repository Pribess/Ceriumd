//Copyright (c) 2021 Heewon Cho

#include <iostream>
#include <dirent.h>

#include "thread/ThreadRunner.hpp"
#include "database/primitive/Sqlite.hpp"
#include "constant/Args.hpp"

namespace Initializer {

    void NetInit() {
        ThreadRunner::StartSocketListenerThread();
    }

}

namespace Tools {

    void CheckDirExist(const char dirname[]) {
        DIR *dir = opendir(dirname);
        if (dir) {

        } else if (ENOENT == errno) {
            std::cout << "Ceriumd: " << dirname << ": No such file or directory" << std::endl;
            exit(1);
        } else {
            std::cout << "Ceriumd: " << dirname << ": Failed to open directory" << std::endl;
            exit(1);
        }
    }

}

void AppInit() {
    Initializer::NetInit();
}

void ArgParser(int argc, char *argv[]) {
    std::vector<std::string> args;
    
    for (char cnt = 0 ; cnt < argc ; cnt++) {
        args.push_back(argv[cnt]);
    }

    std::vector<std::string>::iterator iter = args.begin();

    Tools::CheckDirExist(iter[1].c_str());

    Args::DatabaseStoreDirctory = iter[1];
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