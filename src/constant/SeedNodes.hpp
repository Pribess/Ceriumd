//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_CONSTANT_SEEDNODES
#define _CERIUM_CONSTANT_SEEDNODES

#include <cstdint>

static const std::pair<uint32_t, unsigned short> SeedNodes[] = {
    std::pair<uint32_t, unsigned short>(inet_addr("192.168.0.2"), 1226)
};

#endif