//Copyright (c) 2021 Heewon Cho

#include "Protocol.hpp"

void Protocol::GetVersion(Socket *socket) {
    PacketSender::GetVersion(socket);
    PacketDecoder::Version(socket->ResData());
}

std::vector<std::pair<uint32_t, unsigned short>> Protocol::GetAddr(Socket *socket) {
    PacketSender::GetAddr(socket);
    return PacketDecoder::Addr(socket->ResData());
}