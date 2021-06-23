//Copyright (c) 2021 Heewon Cho

#include "PacketDecoder.hpp"

short PacketDecoder::PacketHandler(unsigned char *data) {
    NetByte::header headerbuff;
    
    std::memcpy(&headerbuff, data, sizeof(NetByte::header));
    
    if (headerbuff.magic != CERIUM_PACKET_MAGIC) {
        throw std::ios_base::failure("Unknown Magic Byte!");
    }

    switch (headerbuff.type) {
        case CERIUM_PACKET_TYPE_VERSION:
            PacketDecoder::CheckSum(data, headerbuff.checksum);
            PacketDecoder::Version(data);
        case CERIUM_PACKET_TYPE_VERACK:
        default:
            throw std::ios_base::failure("Cannot Classify Packet Type!");
    }


}

void PacketDecoder::CheckSum(unsigned char *data, unsigned char checksumorigin[4]) {
    unsigned char checksum[4];

    std::memcpy(checksum, (const char *)Crypto::SHA256((const char *)data + sizeof(NetByte::header), 4), 4);

    if (checksumorigin != checksum) {
        throw std::ios_base::failure("Checksum Not Matched!");
    }
}

NetByte::version PacketDecoder::Version(unsigned char *data) {
    NetByte::version versionbuff;

    std::memcpy(&versionbuff, data + sizeof(NetByte::header), sizeof(NetByte::version));

    return versionbuff;
}

void PacketDecoder::Verack(unsigned char *data) {
    NetByte::header headerbuff;
    
    std::memcpy(&headerbuff, data, sizeof(NetByte::header));

    if (headerbuff.magic != CERIUM_PACKET_MAGIC) {
        throw std::ios_base::failure("Unknown Magic Byte!");
    }

    if (headerbuff.type != CERIUM_PACKET_TYPE_VERSION) {
        throw std::ios_base::failure("Type Not Matched!");
    }

    if (headerbuff.checksum != Crypto::SHA256((const char *)data + sizeof(NetByte::header), 0)) {
        throw std::ios_base::failure("CheckSum Not Matched!");
    }
}

void PacketDecoder::GetAddr(unsigned char *data) {

}

std::vector<std::pair<uint32_t, unsigned short>> PacketDecoder::Addr(char *data) {
    NetByte::header headerbuff;
    
    std::memcpy(&headerbuff, data, sizeof(NetByte::header));

    NetByte::addrheader addrbuff;


    std::vector<std::pair<uint32_t, unsigned short>> list;
}