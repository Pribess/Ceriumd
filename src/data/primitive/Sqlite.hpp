//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_DATABASE_PRIMITIVE_SQLITE
#define _CERIUM_DATABASE_PRIMITIVE_SQLITE

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <sqlite3.h>
#include <cstddef>
#include <array>

#include "tools/CastingTools.hpp" 


class Sqlite {
    private:
        sqlite3 *db;
        void OpenDatabase(std::string dbname);
        void CloseDatabase();
    public:
        Sqlite(std::string dbname);
        ~Sqlite();
        std::vector<std::vector<std::vector<unsigned char>>> ExecuteQuery(std::string sql);
        std::vector<std::vector<std::vector<unsigned char>>> ExecuteQuery(std::string sql, std::vector<std::vector<unsigned char>> data);
};

#endif