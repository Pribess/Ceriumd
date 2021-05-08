//Copyright (c) 2021 Heewon Cho

#include "Block.hpp"

#include <cstring>

Block::Block(
        unsigned int BlockVersion,
        char PreviousHash[32],
        char RootHash[32],
        unsigned int TimeStamp,
        unsigned int bits,
        unsigned int nonce
    ) {
    this->BlockVersion = BlockVersion;
    strcpy(this->PreviousHash, PreviousHash);
    strcpy(this->PreviousHash, RootHash);
    this->TimeStamp = TimeStamp;
    this->bits = bits;
    this->nonce = nonce;
}
