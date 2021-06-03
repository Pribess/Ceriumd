//Copyright (c) 2021 Heewon Cho

#include "PacketBuilder.hpp"

NetByte::header PacketBuilder::HeaderBuilder(short type, void *payload, size_t payload_size) {
    NetByte::header headerbuilder;

    headerbuilder.type = type;
    headerbuilder.length = payload_size;

    char checksumbuff[payload_size];

    std::memcpy(checksumbuff, payload, payload_size);
    std::memcpy(headerbuilder.checksum, (const char *)Crypto::SHA256(checksumbuff, sizeof(checksumbuff)), sizeof(headerbuilder.checksum));
    return headerbuilder;
}

NetByte::version PacketBuilder::VersionBuilder() {
    NetByte::version payloadbuilder;

    payloadbuilder.version = CERIUM_PROTOCOL_VERSION;
    payloadbuilder.timestamp = TimeStamp::GetUtcTimeStamp();

    return payloadbuilder;
}