//Copyright (c) 2021 Heewon Cho

#include "Protocol.hpp"

#include "tools/CastingTools.hpp"

void Protocol::Version(Socket *socket) {
    try {
        char buff[sizeof(NetByte::header) + sizeof(NetByte::version)];

        NetByte::version payload = PacketBuilder::VersionBuilder();
        NetByte::header header = PacketBuilder::HeaderBuilder(CERIUM_PACKET_TYPE_VERSION, &payload, sizeof(payload));

        std::memcpy(buff, &header, sizeof(NetByte::header));
        std::memcpy(buff + sizeof(NetByte::header), &payload, sizeof(NetByte::version));

        socket->SendData(buff, sizeof(buff));
        PacketDecoder::Verack(socket->RecvData());
    } catch (std::exception e) {
        throw e;
    }
}

void Protocol::VersionRecv(Socket *socket) {
    try {
        PacketDecoder::Version(socket->RecvData());

        char buff[sizeof(NetByte::header)];

        NetByte::header header = PacketBuilder::HeaderBuilder(CERIUM_PACKET_TYPE_VERACK, NULL, 0);

        std::memcpy(buff, &header, sizeof(NetByte::header));
        
        socket->SendData(buff, sizeof(buff));
    } catch (std::exception e) {
        throw e;
    }
}