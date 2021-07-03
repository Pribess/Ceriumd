//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_NET_TOOLS_PACKETDECODER
#define _CERIUM_NET_TOOLS_PACKETDECODER

#include <iostream>
#include <cstring>
#include <thread>
#include <vector>

#include "net/protocol/NetByte.hpp"
#include "crypto/Crypto.hpp"
#include "net/Socket.hpp"
#include "net/tools/PacketSender.hpp"

class PacketDecoder {
    private:
        static void CheckSum(unsigned char *data);
    public:
        static int PacketHandler(unsigned char *data, Socket *socket);

        static void ReqHandler(unsigned char *data, Socket *socket);
        static void ResHandler(unsigned char *data, Socket *socket);

        static NetByte::version Version(unsigned char *data);
        static void Verack(unsigned char *data);

        static void GetAddr(unsigned char *data);
        static std::vector<std::pair<uint32_t, unsigned short>> Addr(unsigned char *data);
};

#endif