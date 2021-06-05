//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_DATABASE_DATABASEPOOL
#define _CERIUM_DATABASE_DATABASEPOOL

#include <iostream>
#include <sqlite3.h>

class DatabasePool {
    private:
        static sqlite3 *db;
    public:
        static void SetUpDatabase();
};

#endif