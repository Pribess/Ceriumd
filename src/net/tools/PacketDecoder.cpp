//Copyright (c) 2021 Heewon Cho

#include "PacketDecoder.hpp"

NetByte::version PacketDecoder::Version(std::pair<char *, size_t> pair) {
    NetByte::header headerbuff;
    
    std::memcpy(&headerbuff, &pair.first, sizeof(NetByte::header));

    NetByte::version versionbuff;

    std::memcpy(&versionbuff, &pair.first + sizeof(NetByte::header), headerbuff.length);
    
    if (headerbuff.magic != CERIUM_PACKET_MAGIC) {
        throw std::ios_base::failure("Unknown Magic Byte!");
    }

    if (headerbuff.type != CERIUM_PACKET_TYPE_VERSION) {
        throw std::ios_base::failure("Type Not Matched!");
    }

    if (headerbuff.checksum != Crypto::SHA256(pair.first + sizeof(NetByte::header), sizeof(versionbuff))) {
        throw std::ios_base::failure("CheckSum Not Matched!");
    }
    
    return versionbuff;
}

void PacketDecoder::Verack(std::pair<char *, size_t> pair) {
    NetByte::header headerbuff;
    
    std::memcpy(&headerbuff, &pair.first, sizeof(NetByte::header));

    if (headerbuff.magic != CERIUM_PACKET_MAGIC) {
        throw std::ios_base::failure("Unknown Magic Byte!");
    }

    if (headerbuff.type != CERIUM_PACKET_TYPE_VERSION) {
        throw std::ios_base::failure("Type Not Matched!");
    }

    if (headerbuff.checksum != Crypto::SHA256(pair.first + sizeof(NetByte::header), 0)) {
        throw std::ios_base::failure("CheckSum Not Matched!");
    }
}

void PacketDecoder::GetAddr(std::pair<char *, size_t> pair) {

}

std::vector<std::pair<uint32_t, unsigned short>> PacketDecoder::Addr(std::pair<char *, size_t> pair) {
    NetByte::header headerbuff;
    
    std::memcpy(&headerbuff, &pair.first, sizeof(NetByte::header));

    NetByte::addr addrbuff;

    
    std::vector<std::pair<uint32_t, unsigned short>> list;
}