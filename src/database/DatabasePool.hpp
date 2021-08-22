// Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_DATABASE_DATABASEPOOL
#define _CERIUM_DATABASE_DATABASEPOOL

#include "database/primitive/Sqlite.hpp"
#include "NetDB.hpp"

class DatabasePool {
    public:
        static void SetUpDatabases();
};

#endif