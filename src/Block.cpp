//Copyright (c) 2021 Heewon Cho

#include "Block.hpp"

#include <cstring>

#include "crypto/Crypto.hpp"

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
    strcpy(this->RootHash, RootHash);
    this->TimeStamp = TimeStamp;
    this->bits = bits;
    this->nonce = nonce;
}

char *Block::CalculateBlockHash() {
    return Crypto::SHA256(this->BlockVersion + strcat(this->PreviousHash, this->RootHash) + this->TimeStamp + this->bits + this->nonce);
}