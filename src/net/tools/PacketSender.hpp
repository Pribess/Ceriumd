// Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_NET_TOOLS_PACKETSENDER
#define _CERIUM_NET_TOOLS_PACKETSENDER

#include <vector>

#include "net/primitive/Socket.hpp"
#include "net/protocol/NetByte.hpp"
#include "net/tools/PacketBuilder.hpp"
#include "net/tools/PacketDecoder.hpp"
#include "net/Connection.hpp"

class PacketSender {
    public:
        static void GetVersion(Connection *con);
        static void Version(Connection *con);

        static void GetAddr(Connection *con);
        static void Addr(Connection *con);
};

#endif