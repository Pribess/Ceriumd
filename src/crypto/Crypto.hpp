// Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_CRYPTO_CRYPTO
#define _CERIUM_CRYPTO_CRYPTO

#include <openssl/sha.h>
#include <iostream>
#include <string>
#include <cstring>

class Crypto {
    public:
        static unsigned char *SHA256(const char *string, size_t size);
        static char *SHA256str(const char *string);
};

#endif