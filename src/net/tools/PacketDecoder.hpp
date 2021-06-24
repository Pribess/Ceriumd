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
        static void CheckSum(unsigned char *data);
    public:
        static short PacketHandler(unsigned char *data);

        template <typename T>
        static T RecvPacket(int type);

        static NetByte::version Version(unsigned char *data);
        static void Verack(unsigned char *data);

        static void GetAddr(unsigned char *data);
        static std::vector<std::pair<uint32_t, unsigned short>> Addr(char *data);
};

#endif