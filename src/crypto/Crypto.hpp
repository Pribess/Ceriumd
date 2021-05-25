//Copyright (c) 2021 Heewon Cho

#ifndef CERIUM_CRYPTO_CRYPTO
#define CERIUM_CRYPTO_CRYPTO

#include <openssl/sha.h>
#include <iostream>
#include <cstring>

class Crypto {
public:
    static char *SHA256(const char *string);
};

#endif