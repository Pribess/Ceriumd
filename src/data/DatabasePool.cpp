//Copyright (c) 2021 Heewon Cho

#include "DatabasePool.hpp"
#include "tools/CastingTools.hpp"
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

            DatabasePool::NetDB::SetDB(new Sqlite(dirname));
            DatabasePool::NetDB::GetDB()->ExecuteQuery(R"(CREATE TABLE "AddrCache" ("NodeAddr"	BLOB, "NodePort"	BLOB);)");
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

        DatabasePool::NetDB::SetDB(new Sqlite(dirname));

        std::string sql(R"(SELECT name FROM sqlite_master WHERE type IN ('table', 'view') AND name NOT LIKE 'sqlite_%' UNION ALL SELECT name FROM sqlite_temp_master WHERE type IN ('table', 'view') ORDER BY 1;)");

        std::vector<std::vector<std::vector<unsigned char>>> rs = DatabasePool::NetDB::GetDB()->ExecuteQuery(sql);

        if (rs.empty()) {

            DatabasePool::NetDB::GetDB()->ExecuteQuery(R"(CREATE TABLE "AddrCache" ("NodeAddr"	BLOB, "NodePort"	BLOB);)");

        } else if (std::string("AddrCache") != std::string(rs.front().front().begin(), rs.front().front().end()) ) {

            std::vector<std::vector<std::vector<unsigned char>>> clearsql = DatabasePool::NetDB::GetDB()->ExecuteQuery(R"(SELECT 'DROP TABLE ' || name || ';' FROM sqlite_master WHERE type = 'table';)");

            for (int cnt = 0 ; cnt < clearsql.size() ; cnt++) {
                DatabasePool::NetDB::GetDB()->ExecuteQuery(std::string(clearsql.at(cnt).front().begin(), clearsql.at(cnt).front().end()));
            }

            DatabasePool::NetDB::GetDB()->ExecuteQuery(R"(CREATE TABLE "AddrCache" ("NodeAddr"	BLOB, "NodePort"	BLOB););)");
        
        } else if (1 < rs.size()) {

            std::vector<std::vector<std::vector<unsigned char>>> clearsql = DatabasePool::NetDB::GetDB()->ExecuteQuery(R"(SELECT 'DROP TABLE ' || name || ';' FROM sqlite_master WHERE type = 'table';)");

            for (int cnt = 0 ; cnt < clearsql.size() ; cnt++) {
                DatabasePool::NetDB::GetDB()->ExecuteQuery(std::string(clearsql.at(cnt).front().begin(), clearsql.at(cnt).front().end()));
            }

            DatabasePool::NetDB::GetDB()->ExecuteQuery(R"(CREATE TABLE "AddrCache" ("NodeAddr"	BLOB, "NodePort"	BLOB););)");

        }

    } catch (std::exception e) {
        throw e;
        std::cout << "Ceriumd: fatal: unable to read file '" << dirname << "' Permission Denied" << std::endl; 
        exit(1); 
    }

    return 0;
}

Sqlite *DatabasePool::NetDB::GetDB() {
    return DatabasePool::NetDB::netdb;
}

void DatabasePool::NetDB::SetDB(Sqlite *netdb) {
    DatabasePool::NetDB::netdb = netdb;
}

std::vector<std::pair<uint32_t, unsigned short>> DatabasePool::NetDB::GetNetCache() {
    std::vector<std::vector<std::vector<unsigned char>>> rs = DatabasePool::NetDB::GetDB()->ExecuteQuery("SELECT * FROM AddrCache");
}

void DatabasePool::NetDB::AddNetCache() {

}

void DatabasePool::NetDB::RmNetCache() {

}