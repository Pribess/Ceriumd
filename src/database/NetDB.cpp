// Copyright (c) 2021 Heewon Cho

#include "NetDB.hpp"

Sqlite *NetDB::netdb;

Sqlite *NetDB::GetDB() {
    return NetDB::netdb;
}

void NetDB::SetDB(Sqlite *netdb) {
    NetDB::netdb = netdb;
}

void NetDB::ResetDB() {

    std::vector<std::vector<std::vector<unsigned char>>> clearsql = NetDB::GetDB()->ExecuteQuery(R"(SELECT 'DROP TABLE ' || name || ';' FROM sqlite_master WHERE type = 'table';)");

    for (int cnt = 0 ; cnt < clearsql.size() ; cnt++) {
        NetDB::GetDB()->ExecuteQuery(std::string(clearsql.at(cnt).front().begin(), clearsql.at(cnt).front().end()));
    }

    NetDB::GetDB()->ExecuteQuery(R"(CREATE TABLE "AddrCache" ("NodeAddr"	BLOB, "NodePort"	BLOB););)");

}

std::vector<std::pair<uint32_t, unsigned short>> NetDB::GetNetCache() {
    std::vector<std::pair<uint32_t, unsigned short>> buff;
    std::vector<std::vector<std::vector<unsigned char>>> rs = NetDB::GetDB()->ExecuteQuery("SELECT * FROM AddrCache");
    
        for (int cnt = 0 ; cnt < rs.size() ; cnt++) {
            uint32_t addr;
            unsigned short port;
            std::memcpy(&addr, rs.at(cnt).at(0).data(), sizeof(uint32_t));
            std::memcpy(&port, rs.at(cnt).at(1).data(), sizeof(port));
            buff.push_back(std::pair<uint32_t, unsigned short>(addr, port));
        }

    return buff;
}

void NetDB::AddNetCache(std::vector<std::pair<uint32_t, unsigned short>> data) {
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

    NetDB::GetDB()->ExecuteQuery(sql, binddata);
}

void NetDB::RmNetCache(std::vector<std::pair<uint32_t, unsigned short>> data) {
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

        NetDB::GetDB()->ExecuteQuery(sql, binddata);
    }
}