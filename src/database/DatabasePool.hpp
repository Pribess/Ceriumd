//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_DATABASE_DATABASEPOOL
#define _CERIUM_DATABASE_DATABASEPOOL

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sqlite3.h>
#include <cstring>
#include <string>


class DatabasePool {
    public:
        static void SetUpDatabase(std::string dirname);
};

#endif