//Copyright (c) 2021 Heewon Cho

#include "Protocol.hpp"

void Protocol::Version(Socket *socket) {
    PacketSender::Version(socket);
    PacketDecoder::Verack(socket->ResData());
}

std::vector<std::pair<uint32_t, unsigned short>> GetAddr(Socket *socket) {
    PacketSender::GetAddr(socket);
    return PacketDecoder::Addr(socket->ResData());
}