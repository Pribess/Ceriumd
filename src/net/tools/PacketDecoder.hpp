//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_NET_TOOLS_PACKETDECODER
#define _CERIUM_NET_TOOLS_PACKETDECODER

#include <iostream>
#include <cstring>
#include <vector>

#include "net/protocol/NetByte.hpp"
#include "crypto/Crypto.hpp"
#include "net/Socket.hpp"

class PacketDecoder {
    private:
        static void CheckSum(unsigned char *data);
    public:
        static void PacketHandler(unsigned char *data, std::condition_variable *cv);

        static void ReqHandler(unsigned char *data);
        static void ResHandler(unsigned char *data);

        static NetByte::version Version(unsigned char *data);
        static void Verack(unsigned char *data);

        static void GetAddr(unsigned char *data);
        static std::vector<std::pair<uint32_t, unsigned short>> Addr(char *data);
};

#endif