//Copyright (c) 2021 Heewon Cho

#include "Block.hpp"

Block::Block(
        unsigned int BlockVersion,
        char PreviousHash[32],
        char RootHash[32],
        unsigned int TimeStamp
    ) {
    this->BlockVersion = BlockVersion;
    strcpy(this->PreviousHash, PreviousHash);
    strcpy(this->RootHash, RootHash);
    this->TimeStamp = TimeStamp;
}

char *Block::CalculateBlockHash() {
    std::string StrBuilder(CastingTools::itoa(this->BlockVersion));
    StrBuilder.append(this->PreviousHash);
    StrBuilder.append(this->RootHash);
    StrBuilder.append(CastingTools::itoa(this->TimeStamp));
    return Crypto::SHA256(StrBuilder.c_str());
}