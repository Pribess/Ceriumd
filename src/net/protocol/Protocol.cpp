// Copyright (c) 2021 Heewon Cho

#include "Protocol.hpp"

NetByte::version Protocol::GetVersion(Connection *con) {
    PacketSender::GetVersion(con);
    return PacketDecoder::Version(con->ResData());
}

std::vector<std::pair<uint32_t, unsigned short>> Protocol::GetAddr(Connection *con) {
    PacketSender::GetAddr(con);
    return PacketDecoder::Addr(con->ResData());
}