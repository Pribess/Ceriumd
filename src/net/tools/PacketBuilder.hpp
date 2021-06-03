//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_NET_TOOLS_PACKETSENDER
#define _CERIUM_NET_TOOLS_PACKETSENDER

#include "net/protocol/NetByte.hpp"
#include "net/Socket.hpp"
#include "crypto/Crypto.hpp"
#include "tools/TimeStamp.hpp"
#include "constant/Version.hpp"

class PacketBuilder {
    public:
        static NetByte::header HeaderBuilder(short type, void *payload, size_t size);
        static NetByte::version VersionBuilder();
};

#endif