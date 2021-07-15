//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_NET_TOOLS_BOOTSTRAPPER
#define _CERIUM_NET_TOOLS_BOOTSTRAPPER

#include <iterator>

#include "net/Socket.hpp"
#include "constant/SeedNodes.hpp"
#include "net/primitive/Connector.hpp"
#include "constant/SeedNodes.hpp"
#include "database/DatabasePool.hpp"

class BootStrapper {
    private:
        static Socket *CacheStrap();
        static Socket *SeedStrap();
    public:
        static Socket *BootStrap();
};

#endif