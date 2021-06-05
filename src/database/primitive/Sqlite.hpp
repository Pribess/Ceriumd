//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_DATABASE_PRIMITIVE_SQLITE
#define _CERIUM_DATABASE_PRIMITIVE_SQLITE

#include <iostream>
#include <cstring>
#include <sqlite3.h>

class Sqlite {
    private:
        sqlite3 *db;
        void OpenDatabase(char dbname[]);
        void CloseDatabase();
    public:
        Sqlite(char dbname[]);
        ~Sqlite();
        void ExecuteQuery(char *sql);
};

#endif