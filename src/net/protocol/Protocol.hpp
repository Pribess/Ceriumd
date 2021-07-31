//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_NET_PROTOCOL_PROTOCOL
#define _CERIUM_NET_PROTOCOL_PROTOCOL

#include "net/tools/PacketSender.hpp"

class Protocol {
    public:
        static void GetVersion(Socket *socket);
        static std::vector<std::pair<uint32_t, unsigned short>> GetAddr(Socket *socket);
};

#endif