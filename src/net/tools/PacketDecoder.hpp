//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_NET_TOOLS_PACKETDECODER
#define _CERIUM_NET_TOOLS_PACKETDECODER

#include <iostream>
#include <cstring>
#include <vector>

#include "net/protocol/NetByte.hpp"
#include "crypto/Crypto.hpp"

class PacketDecoder {
    private:
        static void CheckSum(char *data, unsigned char checksum[4]);
    public:
        static short PacketClassifier(char *data);

        static NetByte::version Version(char *data);
        static void Verack(char *data);

        static void GetAddr(char *data);
        static std::vector<std::pair<uint32_t, unsigned short>> Addr(char *data);
};

#endif