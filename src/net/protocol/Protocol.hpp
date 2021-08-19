// Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_NET_PROTOCOL_PROTOCOL
#define _CERIUM_NET_PROTOCOL_PROTOCOL

#include "net/tools/PacketSender.hpp"

class Protocol {
    public:
        static NetByte::version GetVersion(Connection *con);
        static std::vector<std::pair<uint32_t, unsigned short>> GetAddr(Connection *con);
};

#endif