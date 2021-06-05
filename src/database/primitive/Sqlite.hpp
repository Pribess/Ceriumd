//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_DATABASE_PRIMITIVE_SQLITE
#define _CERIUM_DATABASE_PRIMITIVE_SQLITE

#include <iostream>
#include <cstring>
#include <vector>
#include <sqlite3.h>

class Sqlite {
    private:
        sqlite3 *db;
        void OpenDatabase(char dbname[]);
        void CloseDatabase();
        static int HandleResult(void *ArgThrough, int argc, char **argv, char **azColName);
    public:
        Sqlite(char dbname[]);
        ~Sqlite();
        void SetExecuteQuery(char *sql);
        std::vector<std::pair<char *, size_t>> GetExecuteQuery(char *sql);
};

#endif