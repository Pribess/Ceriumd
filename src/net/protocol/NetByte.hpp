//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_NET_PROTOCOL_NETBYTE
#define _CERIUM_NET_PROTOCOL_NETBYTE

#include "constant/Define.hpp"
#include "PacketTypes.hpp"

namespace NetByte {

    typedef struct packetheader {
        const short magic = CERIUM_PACKET_MAGIC;
        short type;
        short length;
        long checksum;
    } packetheader;

    typedef struct version {
        unsigned int version;
        long int timestamp;
    } version;

    typedef struct addr {
        unsigned int count;
        unsigned int addr[];
    } addr;
}

#endif