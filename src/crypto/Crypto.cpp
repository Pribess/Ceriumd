//Copyright (c) 2021 Heewon Cho

#include "Crypto.hpp"

unsigned char *Crypto::SHA256(const char *string, size_t size) {
    static unsigned char digest[SHA256_DIGEST_LENGTH];
 
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, string, size);
    SHA256_Final(digest, &ctx);

    return digest;
}

char *Crypto::SHA256str(const char *string) {
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