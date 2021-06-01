//Copyright (c) 2021 Heewon Cho

#include "Protocol.hpp"

#include "tools/CastingTools.hpp"

int Protocol::Version(Socket *socket) {
    char buff[sizeof(NetByte::packetheader) + sizeof(NetByte::version)];

    NetByte::packetheader header;
    NetByte::version payload;
    
    header.type = CERIUM_PACKET_VERSION;
    header.length = sizeof(NetByte::version);
    payload.version = CERIUM_PROTOCOL_VERSION;
    payload.timestamp = TimeStamp::GetUtcTimeStamp();

    char checksumbuff[sizeof(NetByte::version)];
    std::memcpy(checksumbuff, &payload, sizeof(NetByte::version));
    std::memcpy(header.checksum, (const char *)Crypto::SHA256(checksumbuff, sizeof(checksumbuff)), sizeof(header.checksum));

    std::memcpy(buff, &header, sizeof(NetByte::packetheader));
    std::memcpy(buff + sizeof(NetByte::packetheader), &payload, sizeof(NetByte::version));

    try {
        socket->SendData(buff, sizeof(buff));
    } catch (std::exception e) {
        throw e;
    }
    return 0;
}