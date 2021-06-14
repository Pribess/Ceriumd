//Copyright (c) 2021 Heewon Cho

#include "BootStrapper.hpp"

Socket *BootStrapper::BootStrap() {
    try {
        return BootStrapper::CacheStrap();
    } catch (std::ios_base::failure e) {
        return BootStrapper::SeedStrap();
    }
}

Socket *BootStrapper::CacheStrap() {
    std::vector<std::pair<uint32_t, unsigned short>> rs = DatabasePool::NetDB::GetNetCache();

    for (int cnt = 0 ; cnt < rs.size() ; cnt++) {
        try {
            Connector *soc = new Connector(rs.at(cnt).first, rs.at(cnt).second);
            return soc->Connect();
        } catch (std::ios_base::failure e) {
            continue;
        }
    }
    throw std::ios_base::failure("Failed To Strapping!");
}

Socket *BootStrapper::SeedStrap() {
    for (int cnt = 0 ; cnt < SeedNodesLength ; cnt++) {
        try {
            Connector *soc = new Connector(SeedNodes[cnt].first, SeedNodes[cnt].second);
            return soc->Connect();
        } catch (std::ios_base::failure e) {
            continue;
        }
    }
    throw std::ios_base::failure("Failed To Strapping!");
}