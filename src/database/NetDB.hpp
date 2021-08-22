// Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_DATABASE_NETDB
#define _CERIUM_DATABASE_NETDB

#include "database/primitive/Sqlite.hpp"
#include "constant/KeyValue.hpp"

class NetDB {
    private:
        static Sqlite *netdb;
        static void ResetDB();
    public:
        static void InitDB();
        
        static std::vector<std::pair<uint32_t, unsigned short>> GetNetCache();
        static void AddNetCache(std::vector<std::pair<uint32_t, unsigned short>> data);
        static void RmNetCache(std::vector<std::pair<uint32_t, unsigned short>> data);
};

#endif