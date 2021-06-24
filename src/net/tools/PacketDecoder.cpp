//Copyright (c) 2021 Heewon Cho

#include "PacketDecoder.hpp"

void PacketDecoder::PacketHandler(unsigned char *data, Socket *socket) {
    NetByte::header headerbuff;
    
    std::memcpy(&headerbuff, data, sizeof(NetByte::header));
    
    if (headerbuff.magic != CERIUM_PACKET_MAGIC) {
        throw std::ios_base::failure("Unknown Magic Byte!");
    }
    
    PacketDecoder::CheckSum(data);
    
    if (headerbuff.type % 2 == 0) {
        PacketDecoder::ReqHandler(data);
    } else {
        PacketDecoder::ResHandler(data, socket);
    }
}

void PacketDecoder::ReqHandler(unsigned char *data) {
    
}

void PacketDecoder::ResHandler(unsigned char *data, Socket *socket) {
    socket->PushToQueue(data);
    socket->cv.notify_all();
}

void PacketDecoder::CheckSum(unsigned char *data) {
    uint32_t checksum;
    uint32_t checksumorigin;

    NetByte::header headerbuff;

    std::memcpy(&headerbuff, data, sizeof(NetByte::header));

    std::memcpy(&checksumorigin, headerbuff.checksum, sizeof(checksumorigin));
    std::memcpy(&checksum, (const char *)Crypto::SHA256((const char *)data + sizeof(NetByte::header), headerbuff.length), 4);

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

    if (headerbuff.type != CERIUM_PACKET_TYPE_VERSION) {
        throw std::ios_base::failure("Type Not Matched!");
    }
}

void PacketDecoder::GetAddr(unsigned char *data) {
    NetByte::header headerbuff;
    
    std::memcpy(&headerbuff, data, sizeof(NetByte::header));

    if (headerbuff.type != CERIUM_PACKET_TYPE_VERSION) {
        throw std::ios_base::failure("Type Not Matched!");
    }
}

std::vector<std::pair<uint32_t, unsigned short>> PacketDecoder::Addr(char *data) {
    NetByte::header headerbuff;
    
    std::memcpy(&headerbuff, data, sizeof(NetByte::header));

    NetByte::addrheader addrbuff;

    std::vector<std::pair<uint32_t, unsigned short>> list;
}