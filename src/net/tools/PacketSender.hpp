//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_NET_TOOLS_PACKETSENDER
#define _CERIUM_NET_TOOLS_PACKETSENDER

#include <vector>

#include "net/Socket.hpp"
#include "net/protocol/NetByte.hpp"
#include "net/tools/PacketBuilder.hpp"
#include "net/tools/PacketDecoder.hpp"

class PacketSender {
    public:
        static void Version(Socket *socket);
        static void Verack(Socket *socket);

        static void GetAddr(Socket *socket);
        static void Addr(Socket *socket);
};

#endif