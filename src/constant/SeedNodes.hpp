//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_CONSTANT_SEEDNODES
#define _CERIUM_CONSTANT_SEEDNODES

#include <cstdint>
#include <array>

namespace Seed {
    typedef struct Addrset {
        uint32_t addr;
        unsigned short port;
    } Addrset;

    static const int SeedNodesLength = 1;

    static const Seed::Addrset SeedNodes[SeedNodesLength] = {
        { 0x0200A8C0, 0xCA04 }
    };

};

#endif