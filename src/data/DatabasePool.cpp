//Copyright (c) 2021 Heewon Cho

#include "DatabasePool.hpp"

void DatabasePool::SetUpDatabases() {
    DatabasePool::SetUpNetdb();
}

void DatabasePool::SetUpNetdb() {
    std::string dirname = KeyValue::GetKeyValue("DataDir");
    dirname.append("net.db");

    if (access(dirname.c_str(), F_OK)) {
        try {
            std::ofstream out(dirname);
            out.close();

            Sqlite *netdb = new Sqlite(dirname);
            netdb->ExecuteQuery(R"(CREATE TABLE "AddrCache" ("NodeAddr"	BLOB);)");
            delete netdb;
        } catch (std::exception e) {
            std::cout << "Ceriumd: fatal: unable to create file '" << dirname << "' Permission Denied" << std::endl; 
            exit(1);
        }
    }

    if (access(dirname.c_str(), R_OK)) {
        std::cout << "Ceriumd: fatal: unable to read file '" << dirname << "' Permission Denied" << std::endl; 
        exit(1);
    }

    if (access(dirname.c_str(), W_OK)) {
        std::cout << "Ceriumd: fatal: unable to write file '" << dirname << "' Permission Denied" << std::endl; 
        exit(1);
    }
}