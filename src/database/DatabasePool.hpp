// Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_DATABASE_DATABASEPOOL
#define _CERIUM_DATABASE_DATABASEPOOL

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <cstring>
#include <string>

#include "constant/KeyValue.hpp"
#include "database/primitive/Sqlite.hpp"
#include "NetDB.hpp"

class DatabasePool {
    private:
        static int SetUpNetdb();
    public:
        static void SetUpDatabases();
};

#endif