// Copyright (c) 2021 Heewon Cho

#include "PacketSender.hpp"

void PacketSender::GetVersion(Socket *socket) {
    try {
        std::vector<unsigned char> buff;

        buff.resize(sizeof(NetByte::header));

        NetByte::header header = PacketBuilder::HeaderBuilder(CERIUM_PACKET_TYPE_GETVERSION, NULL, 0);

        std::memcpy(buff.data(), &header, sizeof(NetByte::header));
        
        socket->SendData(buff);
    } catch (std::runtime_error &e) {
        throw e;
    }
}

void PacketSender::Version(Socket *socket) {
    try {
        std::vector<unsigned char> buff;

        buff.resize(sizeof(NetByte::header) + sizeof(NetByte::version));

        NetByte::version payload = PacketBuilder::VersionBuilder();
        NetByte::header header = PacketBuilder::HeaderBuilder(CERIUM_PACKET_TYPE_VERSION, &payload, sizeof(payload));

        std::memcpy(buff.data(), &header, sizeof(NetByte::header));
        std::memcpy(buff.data() + sizeof(NetByte::header), &payload, sizeof(NetByte::version));

        socket->SendData(buff);
    } catch (std::runtime_error &e) {
        throw e;
    }
}

void PacketSender::GetAddr(Socket *socket) {
    try {
        std::vector<unsigned char> buff;

        buff.resize(sizeof(NetByte::header));

        NetByte::header header = PacketBuilder::HeaderBuilder(CERIUM_PACKET_TYPE_GETADDR, NULL, 0);

        std::memcpy(buff.data(), &header, sizeof(NetByte::header));
        
        socket->SendData(buff);
    } catch (std::runtime_error &e) {
        throw e;
    }
}

void PacketSender::Addr(Socket *socket) {
    try {
        std::vector<unsigned char> payload = PacketBuilder::AddrBuilder();
        NetByte::header header = PacketBuilder::HeaderBuilder(CERIUM_PACKET_TYPE_ADDR, payload.data(), payload.size());

        std::vector<unsigned char> buff;

        buff.resize(sizeof(NetByte::header) + payload.size());

        std::memcpy(buff.data(), &header, sizeof(NetByte::header));
        std::memcpy(buff.data() + sizeof(NetByte::header), payload.data(), payload.size());

        socket->SendData(buff);
    } catch (std::runtime_error &e) {
        throw e;
    }
}