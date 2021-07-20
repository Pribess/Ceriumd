//Copyright (c) 2021 Heewon Cho

#include "BootStrapper.hpp"

std::pair<Socket *, std::pair<uint32_t, unsigned short>> BootStrapper::BootStrap() {
    try {
        return BootStrapper::CacheStrap();
    } catch (std::runtime_error e) {
        return BootStrapper::SeedStrap();
    }
}

std::pair<Socket *, std::pair<uint32_t, unsigned short>> BootStrapper::CacheStrap() {
    std::vector<std::pair<uint32_t, unsigned short>> rs = DatabasePool::NetDB::GetNetCache();

    for (std::pair<uint32_t, unsigned short> cnt : rs) {
        try {
            Connector *soc = new Connector(cnt.first, cnt.second);
            return std::pair<Socket *, std::pair<uint32_t, unsigned short>>(soc->Connect(), std::pair<uint32_t, unsigned short>(cnt.first, cnt.second));
        } catch (std::runtime_error e) {
            continue;
        }
    }
    throw std::runtime_error("Failed To CacheStrapping!");
}

std::pair<Socket *, std::pair<uint32_t, unsigned short>> BootStrapper::SeedStrap() {

    for (int cnt = 0 ; cnt < std::size(Seed::SeedNodes) ; cnt++) {
        try {
            Connector *soc = new Connector(Seed::SeedNodes[cnt].addr, Seed::SeedNodes[cnt].port);
            return std::pair<Socket *, std::pair<uint32_t, unsigned short>>(soc->Connect(), std::pair<uint32_t, unsigned short>(Seed::SeedNodes[cnt].addr, Seed::SeedNodes[cnt].port));
        } catch (std::runtime_error e) {
            continue;
        }
    }
    throw std::runtime_error("Failed To SeedStrapping!");
}