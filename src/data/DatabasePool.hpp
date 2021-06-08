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
        static void SetUpNetdb();
    public:
        static void SetUpDatabases();
};

#endif