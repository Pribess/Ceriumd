// Copyright (c) 2021 Heewon Cho

#include <iostream>
#include <dirent.h>
#include <vector>

#include "thread/ThreadRunner.hpp"
#include "constant/KeyValue.hpp"
#include "tools/CastingTools.hpp"
#include "net/tools/BootStrapper.hpp"
#include "constant/SeedNodes.hpp"
#include "tools/TimeStamp.hpp"

namespace Initializer {

    void NetInit() {
        ThreadRunner::StartSocketListenerThread();
        ThreadRunner::StartSocketConnectorThread();
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

void ArgParser(int argc, char **argv) {
    std::vector<std::string> args;
    
    if (argc < 2) {
        std::cout << "Ceriumd: Usage <directory> <option>" << std::endl; 
        exit(1);
    }

    for (char cnt = 0 ; cnt < argc ; cnt++) {
        args.push_back(argv[cnt]);
    }

    std::vector<std::string>::iterator iter = args.begin();

    Tools::CheckDirExist(iter[1]);

    if (iter[1].back() != '/') {
        iter[1].append("/");
    }

    KeyValue::SetKeyValue("DataDir", iter[1]);

    const char *optstring = "f";
    int opt;

    while ((opt = getopt(argc, argv, optstring)) != -1) {
        switch (opt) {
            case 'f':
                
        }
    }
}

void SetupEnvironment() {
    setlocale(LC_ALL, "");
    NetDB::InitDB();
}

int main(int argc, char **argv) {
    std::cout << "   ___          _                 \n  / __\\___ _ __(_)_   _ _ __ ___  \n / /  / _ \\ '__| | | | | '_ ` _ \\\n/ /__|  __/ |  | | |_| | | | | | |\n\\____/\\___|_|  |_|\\__,_|_| |_| |_|" << std::endl;
    ArgParser(argc, argv);
    SetupEnvironment();
    AppInit();
    while (true)
    {
    }
    
    return 0;
}