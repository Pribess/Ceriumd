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

            DatabasePool::NetDB::SetDB(new Sqlite(dirname));
            DatabasePool::NetDB::GetDB()->ExecuteQuery(R"(CREATE TABLE "AddrCache" ("NodeAddr"	BLOB, "NodePort"	BLOB);)");
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

        DatabasePool::NetDB::SetDB(new Sqlite(dirname));

        std::string sql(R"(SELECT name FROM sqlite_master WHERE type IN ('table', 'view') AND name NOT LIKE 'sqlite_%' UNION ALL SELECT name FROM sqlite_temp_master WHERE type IN ('table', 'view') ORDER BY 1;)");

        std::vector<std::vector<std::vector<unsigned char>>> rs = DatabasePool::NetDB::GetDB()->ExecuteQuery(sql);
        int cnt = DatabasePool::NetDB::GetDB()->ExecuteQuery("PRAGMA table_info(AddrCache);").size();

        if (rs.empty()) {
            DatabasePool::NetDB::GetDB()->ExecuteQuery(R"(CREATE TABLE "AddrCache" ("NodeAddr"	BLOB, "NodePort"	BLOB);)");
        } else if (std::string("AddrCache") != std::string(rs.front().front().begin(), rs.front().front().end()) ) {
            DatabasePool::NetDB::ResetDB();
        } else if (rs.size() != 1) {
            DatabasePool::NetDB::ResetDB();
        } else if (cnt != 2) {
            DatabasePool::NetDB::ResetDB();     
        }

    } catch (std::runtime_error &e) {
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

void DatabasePool::NetDB::ResetDB() {

    std::vector<std::vector<std::vector<unsigned char>>> clearsql = DatabasePool::NetDB::GetDB()->ExecuteQuery(R"(SELECT 'DROP TABLE ' || name || ';' FROM sqlite_master WHERE type = 'table';)");

    for (int cnt = 0 ; cnt < clearsql.size() ; cnt++) {
        DatabasePool::NetDB::GetDB()->ExecuteQuery(std::string(clearsql.at(cnt).front().begin(), clearsql.at(cnt).front().end()));
    }

    DatabasePool::NetDB::GetDB()->ExecuteQuery(R"(CREATE TABLE "AddrCache" ("NodeAddr"	BLOB, "NodePort"	BLOB););)");

}

std::vector<std::pair<uint32_t, unsigned short>> DatabasePool::NetDB::GetNetCache() {
    std::vector<std::pair<uint32_t, unsigned short>> buff;
    std::vector<std::vector<std::vector<unsigned char>>> rs = DatabasePool::NetDB::GetDB()->ExecuteQuery("SELECT * FROM AddrCache");
    
        for (int cnt = 0 ; cnt < rs.size() ; cnt++) {
            uint32_t addr;
            unsigned short port;
            std::memcpy(&addr, rs.at(cnt).at(0).data(), sizeof(uint32_t));
            std::memcpy(&port, rs.at(cnt).at(1).data(), sizeof(port));
            buff.push_back(std::pair<uint32_t, unsigned short>(addr, port));
        }

    return buff;
}

void DatabasePool::NetDB::AddNetCache(std::vector<std::pair<uint32_t, unsigned short>> data) {
    std::vector<std::vector<unsigned char>> binddata;
    std::string sql("INSERT INTO AddrCache (NodeAddr, NodePort) VALUES ");

    for (int cnt = 0 ; cnt < data.size() ; cnt++) {
        sql.append("(?, ?)");
        if (cnt < data.size() - 1) {
            sql.append(", ");
        } else {
            sql.append(";");
        }

        for (int cntdata = 0 ; cntdata < data.size() ; cntdata++) {
            std::vector<unsigned char> addr;
            std::vector<unsigned char> port;

            for (int cntaddr = 0 ; cntaddr < 4 ; cntaddr++) {
                addr.push_back(((unsigned char *)&data.at(cntdata).first)[cntaddr]);
            }

            for (int cntport = 0 ; cntport < 2 ; cntport++) {
                port.push_back(((unsigned char *)&data.at(cntdata).second)[cntport]);
            }

            binddata.push_back(addr);
            binddata.push_back(port);
        }
    }

    DatabasePool::NetDB::GetDB()->ExecuteQuery(sql, binddata);
}

void DatabasePool::NetDB::RmNetCache(std::vector<std::pair<uint32_t, unsigned short>> data) {
    std::string sql("DELETE FROM AddrCache WHERE NodeAddr = ? AND NodePort = ?");

    for (int cnt = 0 ; cnt < data.size() ; cnt++) {
        std::vector<std::vector<unsigned char>> binddata;

        std::vector<unsigned char> addr;
        std::vector<unsigned char> port;

        addr.resize(sizeof(uint32_t));
        port.resize(sizeof(unsigned short));

        std::memcpy(addr.data(), &data.at(cnt).first, sizeof(uint32_t));
        std::memcpy(port.data(), &data.at(cnt).second, sizeof(unsigned short));

        binddata.push_back(addr);
        binddata.push_back(port);

        DatabasePool::NetDB::GetDB()->ExecuteQuery(sql, binddata);
    }
}