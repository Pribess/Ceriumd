//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_NET_PROTOCOL_PROTOCOL
#define _CERIUM_NET_PROTOCOL_PROTOCOL

#include <vector>

#include "net/Socket.hpp"
#include "net/protocol/NetByte.hpp"
#include "net/tools/PacketBuilder.hpp"
#include "net/tools/PacketDecoder.hpp"

class Protocol {
    public:
        static void Version(Socket *socket);
        static void VersionRecv(Socket *socket);

        static std::vector<std::pair<uint32_t, unsigned short>> GetAddr(Socket *socket);
        static void GetAddrRecv(Socket *socket);
};

#endif