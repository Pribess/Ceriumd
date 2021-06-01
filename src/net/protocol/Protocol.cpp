//Copyright (c) 2021 Heewon Cho

#include "Protocol.hpp"

#include "tools/CastingTools.hpp"

NetByte::header Protocol::HeaderBuilder(short type, void *payload, size_t payload_size) {
    NetByte::header headerbuilder;

    headerbuilder.type = type;
    headerbuilder.length = payload_size;

    char checksumbuff[payload_size];

    std::memcpy(checksumbuff, payload, payload_size);
    std::memcpy(headerbuilder.checksum, (const char *)Crypto::SHA256(checksumbuff, sizeof(checksumbuff)), sizeof(headerbuilder.checksum));
    return headerbuilder;
}

int Protocol::Version(Socket *socket) {
    char buff[sizeof(NetByte::header) + sizeof(NetByte::version)];

    NetByte::version payload;

    payload.version = CERIUM_PROTOCOL_VERSION;
    payload.timestamp = TimeStamp::GetUtcTimeStamp();

    NetByte::header header = HeaderBuilder(CERIUM_PACKET_TYPE_VERSION, &payload, sizeof(payload));

    std::memcpy(buff, &header, sizeof(NetByte::header));
    std::memcpy(buff + sizeof(NetByte::header), &payload, sizeof(NetByte::version));

    try {
        socket->SendData(buff, sizeof(buff));
    } catch (std::exception e) {
        throw e;
    }
    return 0;
}