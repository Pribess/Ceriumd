//Copyright (c) 2021 Heewon Cho

#include <iostream>
#include <dirent.h>
#include <vector>

#include "thread/ThreadRunner.hpp"
#include "data/primitive/Sqlite.hpp"
#include "data/DatabasePool.hpp"
#include "constant/KeyValue.hpp"
#include "tools/CastingTools.hpp"
#include "constant/SeedNodes.hpp"

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
    Sqlite *net = new Sqlite("src/net.db");
    std::vector<std::vector<unsigned char>> asd;
    std::vector<unsigned char> asdf;
    std::vector<unsigned char> asdfa;
    asdf.resize(4);
    std::memcpy(asdf.data(), (const char *)&SeedNodes[0].first, 4);
    asdfa.push_back(0xad);
    asdfa.push_back(0xad);
    asd.push_back(asdf);
    asd.push_back(asdfa);
    net->ExecuteQuery("UPDATE AddrCache SET NodeAddr = ? WHERE NodePort = ?", asd);
    std::vector<std::pair<uint32_t, unsigned short>> rs = DatabasePool::NetDB::GetNetCache();
    for (int cnt = 0 ; cnt < rs.size() ; cnt++) {
        std::cout << CastingTools::ctoh((const unsigned char *)&rs.at(cnt).first, sizeof(uint32_t)) << std::endl;
        std::cout << CastingTools::ctoh((const unsigned char *)&rs.at(cnt).second, sizeof(unsigned short)) << std::endl;
    }
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