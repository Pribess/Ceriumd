//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_NET_PROTOCOL_NETBYTE
#define _CERIUM_NET_PROTOCOL_NETBYTE

#include <cstdint>

#include "constant/Definition.hpp"
#include "Opcodes.hpp"

namespace NetByte {

    typedef struct header {
        const short magic = CERIUM_PACKET_MAGIC;
        short type;
        uint32_t length;
        unsigned char checksum[4];
    } header;
    
    typedef struct version {
        uint64_t version;
        uint64_t timestamp;
    } version;

    typedef struct addrheader {
        unsigned short count;
    } addrheader;

    typedef struct addrset {
        uint32_t address;
        unsigned short port;
    } addrset;

}

#endif