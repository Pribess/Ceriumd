// Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_DATABASE_MEMDB
#define _CERIUM_DATABASE_MEMDB

#include "database/primitive/Sqlite.hpp"

class MemDB {
    private:
        static Sqlite *memdb;
    public:
        static void InitDB();
};

#endif