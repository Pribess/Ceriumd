//Copyright (c) 2021 Heewon Cho

#include "DatabasePool.hpp"

Sqlite *DatabasePool::NetDB::netdb;

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

            DatabasePool::NetDB::netdb = new Sqlite(dirname);
            DatabasePool::NetDB::netdb->ExecuteQuery(R"(CREATE TABLE "AddrCache" ("NodeAddr"	BLOB);)");
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

        DatabasePool::NetDB::netdb = new Sqlite(dirname);

        std::string sql(R"(SELECT name FROM sqlite_master WHERE type IN ('table', 'view') AND name NOT LIKE 'sqlite_%' UNION ALL SELECT name FROM sqlite_temp_master WHERE type IN ('table', 'view') ORDER BY 1;)");

        std::vector<std::vector<std::string>> rs = DatabasePool::NetDB::netdb->ExecuteQuery(sql);

        if (rs.empty()) {

            DatabasePool::NetDB::netdb->ExecuteQuery(R"(CREATE TABLE "AddrCache" ("NodeAddr"	BLOB);)");

        } else if (std::string("AddrCache") != rs.front().front() ) {

            std::vector<std::vector<std::string>> clearsql = DatabasePool::NetDB::netdb->ExecuteQuery(R"(SELECT 'DROP TABLE ' || name || ';' FROM sqlite_master WHERE type = 'table';)");

            for (int cnt = 0 ; cnt < clearsql.size() ; cnt++) {
                DatabasePool::NetDB::netdb->ExecuteQuery(clearsql.at(cnt).front());
            }

            DatabasePool::NetDB::netdb->ExecuteQuery(R"(CREATE TABLE "AddrCache" ("NodeAddr"	BLOB);)");
        
        } else if (1 < rs.size()) {

            std::vector<std::vector<std::string>> clearsql = DatabasePool::NetDB::netdb->ExecuteQuery(R"(SELECT 'DROP TABLE ' || name || ';' FROM sqlite_master WHERE type = 'table';)");

            for (int cnt = 0 ; cnt < clearsql.size() ; cnt++) {
                DatabasePool::NetDB::netdb->ExecuteQuery(clearsql.at(cnt).front());
            }

            DatabasePool::NetDB::netdb->ExecuteQuery(R"(CREATE TABLE "AddrCache" ("NodeAddr"	BLOB);)");

        }

    } catch (std::exception e) {
        throw e;
        std::cout << "Ceriumd: fatal: unable to read file '" << dirname << "' Permission Denied" << std::endl; 
        exit(1); 
    }

    return 0;
}

std::vector<std::pair<uint32_t, short>> DatabasePool::NetDB::GetNetCache() {

}

void DatabasePool::NetDB::AddNetCache() {

}

void DatabasePool::NetDB::RmNetCache() {

}