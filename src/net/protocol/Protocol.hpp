//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_NET_PROTOCOL_PROTOCOL
#define _CERIUM_NET_PROTOCOL_PROTOCOL

#include "net/Socket.hpp"
#include "net/protocol/NetByte.hpp"
#include "net/tools/PacketBuilder.hpp"
#include "net/tools/PacketDecoder.hpp"

class Protocol {
    public:
        static void Version(Socket *socket);
        static void VersionRecv(Socket *socket);
};

#endif