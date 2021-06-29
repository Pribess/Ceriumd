//Copyright (c) 2021 Heewon Cho

#include "PacketBuilder.hpp"

NetByte::header PacketBuilder::HeaderBuilder(short type, void *payload, size_t payload_size) {
    NetByte::header headerbuilder;

    headerbuilder.type = type;
    headerbuilder.length = payload_size;

    std::memcpy(headerbuilder.checksum, (const char *)Crypto::SHA256((const char *)payload, payload_size), sizeof(headerbuilder.checksum));
    return headerbuilder;
}

NetByte::version PacketBuilder::VersionBuilder() {
    NetByte::version payloadbuilder;

    payloadbuilder.version = CERIUM_PROTOCOL_VERSION;
    payloadbuilder.timestamp = TimeStamp::GetUtcTimeStamp();

    return payloadbuilder;
}

std::vector<unsigned char> PacketBuilder::AddrBuilder() {
    std::vector<unsigned char> payloadbuilder;

    std::vector<std::pair<uint32_t, unsigned short>> addrlist = DatabasePool::NetDB::GetNetCache();

    NetByte::addrheader addrheader;
    std::vector<NetByte::addrset> addr;

    for (int cnt = 0 ; cnt < addrlist.size() ; cnt++) {
        NetByte::addrset buff;
        
        buff.address = addrlist.at(cnt).first;
        buff.port = addrlist.at(cnt).second;

        addr.push_back(buff);

        if (cnt > 100) {
            break;
        }
    }

    addrheader.count = addr.size();

    payloadbuilder.resize(sizeof(addrheader) + addr.size());

    std::memcpy(payloadbuilder.data(), &addrheader, sizeof(NetByte::addrheader));
    std::memcpy(payloadbuilder.data() + sizeof(NetByte::addrheader), addr.data(), addr.size());

    return payloadbuilder;
}