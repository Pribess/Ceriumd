//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_CONSTANT_SEEDNODES
#define _CERIUM_CONSTANT_SEEDNODES

#include <cstdint>
#include <array>

static const int SeedNodesLength = 1;

static const std::pair<uint32_t, unsigned short> SeedNodes[SeedNodesLength] = {
    std::pair<uint32_t, unsigned short>(0x0200A8C0, 0xCA04)
};

#endif