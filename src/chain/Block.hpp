// Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_CHAIN_BLOCK
#define _CERIUM_CHAIN_BLOCK

#include <cstring>
#include <string>

#include "crypto/Crypto.hpp"
#include "tools/CastingTools.hpp"

class Block {
    private:
        uint32_t BlockVersion;
        char PreviousHash[32];
        char RootHash[32];
        uint64_t TimeStamp;
    public:
        Block(
            uint32_t BlockVersion,
            char PreviousHash[32],
            char RootHash[32],
            uint64_t TimeStamp
        );
        char *CalculateBlockHash();
};

#endif