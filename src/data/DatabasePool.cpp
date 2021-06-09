//Copyright (c) 2021 Heewon Cho

#include "DatabasePool.hpp"

Sqlite *DatabasePool::netdb;

void DatabasePool::SetUpDatabases() {
    DatabasePool::SetUpNetdb();
}

int DatabasePool::SetUpNetdb() {
    std::string dirname = KeyValue::GetKeyValue("DataDir");
    dirname.append("net.db");

    if (access(dirname.c_str(), F_OK)) {
        try {
            std::ofstream out(dirname);
            out.close();

            DatabasePool::netdb = new Sqlite(dirname);
            netdb->ExecuteQuery(R"(CREATE TABLE "AddrCache" ("NodeAddr"	BLOB);)");
            return 0;
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

    try {

        DatabasePool::netdb = new Sqlite(dirname);

        std::string sql(R"(SELECT name FROM sqlite_master WHERE type IN ('table', 'view') AND name NOT LIKE 'sqlite_%' UNION ALL SELECT name FROM sqlite_temp_master WHERE type IN ('table', 'view') ORDER BY 1;)");

        std::vector<std::vector<std::string>> rs = netdb->ExecuteQuery(sql);

        if (rs.empty()) {

            netdb->ExecuteQuery(R"(CREATE TABLE "AddrCache" ("NodeAddr"	BLOB);)");

        } else if (std::string("AddrCache") != rs.front().front() ) {

            std::vector<std::vector<std::string>> clearsql = netdb->ExecuteQuery(R"(SELECT 'DROP TABLE ' || name || ';' FROM sqlite_master WHERE type = 'table';)");

            for (int cnt = 0 ; cnt < clearsql.size() ; cnt++) {
                netdb->ExecuteQuery(clearsql.at(cnt).front());
            }

            netdb->ExecuteQuery(R"(CREATE TABLE "AddrCache" ("NodeAddr"	BLOB);)");
        
        } else if (1 < rs.size()) {

            std::vector<std::vector<std::string>> clearsql = netdb->ExecuteQuery(R"(SELECT 'DROP TABLE ' || name || ';' FROM sqlite_master WHERE type = 'table';)");

            for (int cnt = 0 ; cnt < clearsql.size() ; cnt++) {
                netdb->ExecuteQuery(clearsql.at(cnt).front());
            }

            netdb->ExecuteQuery(R"(CREATE TABLE "AddrCache" ("NodeAddr"	BLOB);)");
            
        }

    } catch (std::exception e) {
        throw e;
        std::cout << "Ceriumd: fatal: unable to read file '" << dirname << "' Permission Denied" << std::endl; 
        exit(1); 
    }

    return 0;
}