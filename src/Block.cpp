//Copyright (c) 2021 Heewon Cho

#include "Block.hpp"

#include <cstring>

#include "crypto/Crypto.hpp"
#include "tools/StringBuilder.hpp"

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
    StringBuilder *String = new StringBuilder(this->BlockVersion);
    String->AppendChar(this->PreviousHash);
    String->AppendChar(this->RootHash);
    String->AppendInt(this->TimeStamp);
    String->AppendInt(this->bits);
    String->AppendInt(this->nonce);
    return Crypto::SHA256(String->RetString());
}