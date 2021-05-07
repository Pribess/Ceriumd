//Copyright (c) 2021 Heewon Cho

#include "Block.hpp"

#include <cstring>

Block::Block(
        unsigned int BlockVersion,
        char PreviousHash[32],
        char RootHash[32],
        unsigned int TimeStamp
    ) {
    Block::BlockVersion = this->BlockVersion;
    strcpy(Block::PreviousHash, this->PreviousHash);
    strcpy(Block::PreviousHash, this->RootHash);
    Block::TimeStamp = this->TimeStamp;
}