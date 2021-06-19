//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_NET_TOOLS_PACKETDECODER
#define _CERIUM_NET_TOOLS_PACKETDECODER

#include <iostream>
#include <cstring>
#include <vector>

#include "net/protocol/NetByte.hpp"
#include "crypto/Crypto.hpp"

class PacketDecoder {
    public:
        static NetByte::version Version(std::pair<char *, size_t> pair);
        static void Verack(std::pair<char *, size_t> pair);

        static void GetAddr(std::pair<char *, size_t> pair);
        static std::vector<std::pair<uint32_t, unsigned short>> Addr(std::pair<char *, size_t> pair);
};

#endif