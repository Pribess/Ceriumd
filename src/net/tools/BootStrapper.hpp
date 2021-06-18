//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_NET_TOOLS_BOOTSTRAPPER
#define _CERIUM_NET_TOOLS_BOOTSTRAPPER

#include "net/Socket.hpp"
#include "constant/SeedNodes.hpp"
#include "net/primitive/Connector.hpp"
#include "constant/SeedNodes.hpp"
#include "database/DatabasePool.hpp"

class BootStrapper {
    private:
        static std::pair<uint32_t, Socket *> CacheStrap();
        static std::pair<uint32_t, Socket *> SeedStrap();
    public:
        static std::pair<uint32_t, Socket *> BootStrap();
};

#endif