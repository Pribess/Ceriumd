//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_DATABASE_DATABASEPOOL
#define _CERIUM_DATABASE_DATABASEPOOL

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <cstring>
#include <string>

#include "constant/KeyValue.hpp"
#include "data/primitive/Sqlite.hpp"

class DatabasePool {
    private:
        static int SetUpNetdb();
    public:
        static void SetUpDatabases();
        class NetDB {
            public:
                static Sqlite *netdb;

                static std::vector<std::pair<uint32_t, unsigned short>> GetNetCache();
                static void AddNetCache();
                static void RmNetCache();
        };
};

#endif