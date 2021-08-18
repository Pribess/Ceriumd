// Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_NET_TOOLS_PACKETBUILDER
#define _CERIUM_NET_TOOLS_PACKETBUILDER

#include "net/protocol/NetByte.hpp"
#include "net/primitive/Socket.hpp"
#include "crypto/Crypto.hpp"
#include "tools/TimeStamp.hpp"
#include "constant/Version.hpp"
#include "database/DatabasePool.hpp"

class PacketBuilder {
    public:
        static NetByte::header HeaderBuilder(short type, void *payload, size_t size);

        static NetByte::version VersionBuilder();
        static std::vector<unsigned char> AddrBuilder();
};

#endif