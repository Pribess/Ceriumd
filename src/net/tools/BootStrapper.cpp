//Copyright (c) 2021 Heewon Cho

#include "BootStrapper.hpp"

Socket *BootStrapper::BootStrap() {
    // try {
        return BootStrapper::CacheStrap();
    // } catch (std::runtime_error e) {
    //     return BootStrapper::SeedStrap();
    // }
}

Socket *BootStrapper::CacheStrap() {
    std::vector<std::pair<uint32_t, unsigned short>> rs = DatabasePool::NetDB::GetNetCache();

    for (std::pair<uint32_t, unsigned short> cnt : rs) {
        try {
            Connector *soc = new Connector(cnt.first, cnt.second);
            return soc->Connect();
        } catch (std::runtime_error e) {
            continue;
        }
    }
    throw std::runtime_error("Failed To CacheStrapping!");
}

Socket *BootStrapper::SeedStrap() {
    for (int cnt = 0 ; cnt < Seed::SeedNodesLength ; cnt++) {
        try {
            Connector *soc = new Connector(Seed::SeedNodes[cnt].first, Seed::SeedNodes[cnt].second);
            return soc->Connect();
        } catch (std::runtime_error e) {
            continue;
        }
    }
    throw std::runtime_error("Failed To SeedStrapping!");
}