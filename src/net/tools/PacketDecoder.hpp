//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_NET_TOOLS_PACKETDECODER
#define _CERIUM_NET_TOOLS_PACKETDECODER

#include <iostream>
#include <cstring>

#include "net/protocol/NetByte.hpp"
#include "crypto/Crypto.hpp"

class PacketDecoder {
    public:
        static NetByte::version Version(std::pair<char *, size_t> pair);
        static void Verack(std::pair<char *, size_t> pair);
};

#endif