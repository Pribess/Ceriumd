//Copyright (c) 2021 Heewon Cho

class Block {
private:
    unsigned int BlockVersion;
    char PreviousHash[32];
    char RootHash[32];
    unsigned int TimeStamp;
    unsigned int bits;
    unsigned int nonce;
public:
    Block(
        unsigned int BlockVersion,
        char PreviousHash[32],
        char RootHash[32],
        unsigned int TimeStamp,
        unsigned int bits,
        unsigned int nonce
    );
};  