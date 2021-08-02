// Copyright (c) 2021 Heewon Cho

#include "PacketDecoder.hpp"

int PacketDecoder::PacketHandler(unsigned char *data, Socket *socket) {
    NetByte::header headerbuff;

    std::memcpy(&headerbuff, data, sizeof(NetByte::header));
    
    if (headerbuff.magic != CERIUM_PACKET_MAGIC) {
        return 1;
    }

    PacketDecoder::CheckSum(data);

    if (headerbuff.type % 2 == 0) {
        PacketDecoder::ReqHandler(data, socket);
    } else {
        PacketDecoder::ResHandler(data, socket);
    }

    return 0;
}

void PacketDecoder::ReqHandler(unsigned char *data, Socket *socket) {
    NetByte::header headerbuff;
    
    std::memcpy(&headerbuff, data, sizeof(NetByte::header));
   
    switch (headerbuff.type)
    {
        case CERIUM_PACKET_TYPE_GETVERSION:
            PacketSender::Version(socket);
            break;
        case CERIUM_PACKET_TYPE_GETADDR:
            PacketSender::Addr(socket);
            break;
        default:
            break;
    }
}

void PacketDecoder::ResHandler(unsigned char *data, Socket *socket) {
    socket->PushToQueue(data);
}

void PacketDecoder::CheckSum(unsigned char *data) {
    uint32_t checksum;
    uint32_t checksumorigin;

    NetByte::header headerbuff;

    std::memcpy(&headerbuff, data, sizeof(NetByte::header));

    std::memcpy(&checksumorigin, headerbuff.checksum, sizeof(checksumorigin));
    std::memcpy(&checksum, (const char *)Crypto::SHA256((const char *)data + sizeof(NetByte::header), headerbuff.length), sizeof(checksum));
    
    std::cout << std::hex << checksumorigin << "==" << checksum <<std::endl;
    if (checksumorigin != checksum) {
        throw std::runtime_error("Checksum Not Matched!");
    }
}

void PacketDecoder::CheckType(unsigned char *data, int type) {
    NetByte::header headerbuff;
    
    std::memcpy(&headerbuff, data, sizeof(NetByte::header));
    
    if (headerbuff.type != type) {
        throw std::runtime_error("Type Not Matched!");
    }
}

void PacketDecoder::GetVersion(unsigned char *data) {
    PacketDecoder::CheckType(data, CERIUM_PACKET_TYPE_GETVERSION);
    Socket::ClearBuffer(data);
}

NetByte::version PacketDecoder::Version(unsigned char *data) {
    NetByte::version versionbuff;

    std::memcpy(&versionbuff, data + sizeof(NetByte::header), sizeof(NetByte::version));

    Socket::ClearBuffer(data);

    return versionbuff;
}

void PacketDecoder::GetAddr(unsigned char *data) {
    PacketDecoder::CheckType(data, CERIUM_PACKET_TYPE_GETADDR);
    Socket::ClearBuffer(data);
}

std::vector<std::pair<uint32_t, unsigned short>> PacketDecoder::Addr(unsigned char *data) {
    std::vector<std::pair<uint32_t, unsigned short>> addrlist;

    NetByte::header headerbuff;

    std::memcpy(&headerbuff, data, sizeof(NetByte::header));

    NetByte::addrheader addrbuff;

    std::memcpy(&addrbuff, data + sizeof(NetByte::header), sizeof(NetByte::addrheader));

    std::vector<NetByte::addrset> listbuff;

    listbuff.resize(addrbuff.count);

    std::memcpy(listbuff.data(), data + sizeof(NetByte::header) + sizeof(NetByte::addrheader), addrbuff.count * sizeof(NetByte::addrset));
    
    for (NetByte::addrset cnt : listbuff) {
        addrlist.push_back(std::pair<uint32_t, unsigned short>(cnt.address, cnt.port));
    }

    Socket::ClearBuffer(data);

    return addrlist;
}