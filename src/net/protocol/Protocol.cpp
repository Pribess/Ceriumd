//Copyright (c) 2021 Heewon Cho

#include "Protocol.hpp"

int Protocol::Version(Socket *socket) {
    char buff[sizeof(NetByte::packetheader) + sizeof(NetByte::version)];
    NetByte::packetheader header;
    NetByte::version payload;
    header.type = CERIUM_PACKET_VERSION;
    header.length = sizeof(NetByte::version);
    payload.timestamp = TimeStamp::GetUtcTimeStamp();
    std::memcpy(buff, &header, sizeof(NetByte::packetheader));
    std::memcpy(buff + sizeof(NetByte::packetheader), &payload, sizeof(NetByte::version));
    try {
        socket->SendData(buff);
    } catch (std::exception e) {
        throw e;
    }
    return 0;
}