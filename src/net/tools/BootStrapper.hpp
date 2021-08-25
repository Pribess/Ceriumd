// Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_NET_TOOLS_BOOTSTRAPPER
#define _CERIUM_NET_TOOLS_BOOTSTRAPPER

#include <iterator>

#include "net/primitive/Socket.hpp"
#include "constant/SeedNodes.hpp"
#include "net/primitive/Connector.hpp"
#include "constant/SeedNodes.hpp"
#include "database/NetDB.hpp"

class BootStrapper {
    private:
        static std::pair<Socket *, std::pair<uint32_t, unsigned short>> CacheStrap();
        static std::pair<Socket *, std::pair<uint32_t, unsigned short>> SeedStrap();
    public:
        static std::pair<Socket *, std::pair<uint32_t, unsigned short>> BootStrap();
};

#endif