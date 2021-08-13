// Copyright (c) 2021 Heewon Cho

#include "DatabasePool.hpp"

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

            NetDB::SetDB(new Sqlite(dirname));
            NetDB::GetDB()->ExecuteQuery(R"(CREATE TABLE "AddrCache" ("NodeAddr"	BLOB, "NodePort"	BLOB);)");
            return 0;
        } catch (std::runtime_error &e) {
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

        NetDB::SetDB(new Sqlite(dirname));

        std::string sql(R"(SELECT name FROM sqlite_master WHERE type IN ('table', 'view') AND name NOT LIKE 'sqlite_%' UNION ALL SELECT name FROM sqlite_temp_master WHERE type IN ('table', 'view') ORDER BY 1;)");

        std::vector<std::vector<std::vector<unsigned char>>> rs = NetDB::GetDB()->ExecuteQuery(sql);
        int cnt = NetDB::GetDB()->ExecuteQuery("PRAGMA table_info(AddrCache);").size();

        if (rs.empty()) {
            NetDB::GetDB()->ExecuteQuery(R"(CREATE TABLE "AddrCache" ("NodeAddr"	BLOB, "NodePort"	BLOB);)");
        } else if (std::string("AddrCache") != std::string(rs.front().front().begin(), rs.front().front().end()) ) {
            NetDB::ResetDB();
        } else if (rs.size() != 1) {
            NetDB::ResetDB();
        } else if (cnt != 2) {
            NetDB::ResetDB();     
        }

    } catch (std::runtime_error &e) {
        throw e;
        std::cout << "Ceriumd: fatal: unable to read file '" << dirname << "' Permission Denied" << std::endl; 
        exit(1); 
    }

    return 0;
}