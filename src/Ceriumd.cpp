// Copyright (c) 2021 Heewon Cho

#include <iostream>
#include <vector>
#include <getopt.h>
#include <cstdlib>

#include "thread/ThreadRunner.hpp"
#include "constant/KeyValue.hpp"

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

    KeyValue::SetKeyValue("optdatadir", iter[1]);

    static option optlist[] {
        {"verbose", no_argument, NULL, 'v'},
        {"server", no_argument, NULL, 's'}
    };

    int opt;
    const char *optstring = "vs";
    int optidx;

    std::string optverbose;
    std::string optnetforwarded;

    while ((opt = getopt_long(argc, argv, optstring, optlist, &optidx)) != -1) {
        switch (opt) {
            case 'v':
                optverbose.append("true");
                break;
            case 's':
                optnetforwarded.append("true");
                break;
        }
    }

    optverbose.append("false");
    optnetforwarded.append("false");

    KeyValue::SetKeyValue("optverbose", optverbose);
    KeyValue::SetKeyValue("optnetforwarded", optnetforwarded);
}

void SetupEnvironment() {
    setlocale(LC_ALL, "");
    NetDB::InitDB();
}

int main(int argc, char **argv) {
    std::cout << "   ___          _                 \n  / __\\___ _ __(_)_   _ _ __ ___  \n / /  / _ \\ '__| | | | | '_ ` _ \\\n/ /__|  __/ |  | | |_| | | | | | |\n\\____/\\___|_|  |_|\\__,_|_| |_| |_|" << std::endl;
    SetupEnvironment();
    ArgParser(argc, argv);
    AppInit();
    while (true)
    {
    }
    
    return 0;
}