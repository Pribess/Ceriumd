//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_NET_PROTOCOL_NETBYTE
#define _CERIUM_NET_PROTOCOL_NETBYTE

#include <cstdint>

#include "constant/Define.hpp"
#include "PacketTypes.hpp"

namespace NetByte {

    typedef struct packetheader {
        const short magic = CERIUM_PACKET_MAGIC;
        short type;
        short length;
        unsigned char checksum[4];
    } packetheader;
    
    typedef struct version {
        uint64_t version;
        long timestamp;
    } version;

    typedef struct addr {
        uint64_t count;
        uint32_t addr[];
    } addr;
}

#endif