//Copyright (c) 2021 Heewon Cho

#include "PacketSender.hpp"

void PacketSender::Version(Socket *socket) {
    try {
        char buff[sizeof(NetByte::header) + sizeof(NetByte::version)];

        NetByte::version payload = PacketBuilder::VersionBuilder();
        NetByte::header header = PacketBuilder::HeaderBuilder(CERIUM_PACKET_TYPE_VERSION, &payload, sizeof(payload));

        std::memcpy(buff, &header, sizeof(NetByte::header));
        std::memcpy(buff + sizeof(NetByte::header), &payload, sizeof(NetByte::version));

        socket->SendData(buff, sizeof(buff));
    } catch (std::exception e) {
        throw e;
    }
}

void PacketSender::Verack(Socket *socket) {
    try {
        char buff[sizeof(NetByte::header)];

        NetByte::header header = PacketBuilder::HeaderBuilder(CERIUM_PACKET_TYPE_VERACK, NULL, 0);

        std::memcpy(buff, &header, sizeof(NetByte::header));
        
        socket->SendData(buff, sizeof(buff));
    } catch (std::exception e) {
        throw e;
    }
}

void PacketSender::GetAddr(Socket *socket) {
    try {
        char buff[sizeof(NetByte::header)];

        NetByte::header header = PacketBuilder::HeaderBuilder(CERIUM_PACKET_TYPE_GETADDR, NULL, 0);

        std::memcpy(buff, &header, sizeof(NetByte::header));
        
        socket->SendData(buff, sizeof(buff));
    } catch (std::exception e) {
        throw e;
    }
}

void PacketSender::Addr(Socket *socket) {
    try {
        

        std::vector<unsigned char> payload = PacketBuilder::AddrBuilder();
        NetByte::header header = PacketBuilder::HeaderBuilder(CERIUM_PACKET_TYPE_VERSION, &payload, sizeof(payload));

        char buff[sizeof(NetByte::header) + payload.size()];

        std::memcpy(buff, &header, sizeof(NetByte::header));
        std::memcpy(buff + sizeof(NetByte::header), payload.data(), payload.size());

        socket->SendData(buff, sizeof(buff));
    } catch (std::exception e) {
        throw e;
    }
}