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
        static std::vector<std::vector<std::string>> buff;
        void OpenDatabase(std::string dbname);
        void CloseDatabase();
        static int HandleResult(void *ArgThrough, int argc, char **argv, char **azColName);
    public:
        Sqlite(std::string dbname);
        ~Sqlite();
        std::vector<std::vector<std::string>> ExecuteQuery(std::string sql);
};

#endif