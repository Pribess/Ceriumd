//Copyright (c) 2021 Heewon Cho

#include "BootStrapper.hpp"

std::pair<uint32_t, Socket *> BootStrapper::BootStrap() {
    try {
        return BootStrapper::CacheStrap();
    } catch (std::ios_base::failure e) {
        return BootStrapper::SeedStrap();
    }
}

std::pair<uint32_t, Socket *> BootStrapper::CacheStrap() {
    std::vector<std::pair<uint32_t, unsigned short>> rs = DatabasePool::NetDB::GetNetCache();

    for (int cnt = 0 ; cnt < rs.size() ; cnt++) {
        try {
            Connector *soc = new Connector(rs.at(cnt).first, rs.at(cnt).second);
            return std::pair<uint32_t, Socket *>(rs.at(cnt).first, soc->Connect());
        } catch (std::ios_base::failure e) {
            continue;
        }
    }
    throw std::ios_base::failure("Failed To Strapping!");
}

std::pair<uint32_t, Socket *> BootStrapper::SeedStrap() {
    for (int cnt = 0 ; cnt < Seed::SeedNodesLength ; cnt++) {
        try {
            Connector *soc = new Connector(Seed::SeedNodes[cnt].first, Seed::SeedNodes[cnt].second);
            return std::pair<uint32_t, Socket *>(Seed::SeedNodes[cnt].first, soc->Connect());
        } catch (std::ios_base::failure e) {
            continue;
        }
    }
    throw std::ios_base::failure("Failed To Strapping!");
}