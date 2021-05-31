//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_CHAIN_BLOCK
#define _CERIUM_CHAIN_BLOCK

#include <cstring>
#include <string>

#include "crypto/Crypto.hpp"
#include "tools/CastingTools.hpp"

class Block {
    private:
        unsigned int BlockVersion;
        char PreviousHash[32];
        char RootHash[32];
        unsigned int TimeStamp;
    public:
        Block(
            unsigned int BlockVersion,
            char PreviousHash[32],
            char RootHash[32],
            unsigned int TimeStamp
        );
        char *CalculateBlockHash();
};

#endif