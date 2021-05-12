//Copyright (c) 2021 Heewon Cho

#include "Crypto.hpp"

#include <openssl/sha.h>
#include <iostream>
#include <cstring>

char *Crypto::SHA256(const char *string) {
    unsigned char digest[SHA256_DIGEST_LENGTH];
 
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, string, std::strlen(string));
    SHA256_Final(digest, &ctx);
 
    static char mdString[SHA256_DIGEST_LENGTH*2+1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        std::sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
    }

    return mdString;
};