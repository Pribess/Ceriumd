//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_DATABASE_PRIMITIVE_SQLITE
#define _CERIUM_DATABASE_PRIMITIVE_SQLITE

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <sqlite3.h>
#include <cstddef>

class Sqlite {
    private:
        sqlite3 *db;
        void OpenDatabase(std::string dbname);
        void CloseDatabase();
    public:
        Sqlite(std::string dbname);
        ~Sqlite();
        std::vector<std::vector<std::pair<std::string, size_t>>> ExecuteQuery(std::string sql);
};

#endif