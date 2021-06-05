//Copyright (c) 2021 Heewon Cho

#include "Sqlite.hpp"

Sqlite::Sqlite(char dbname[]) {
    this->OpenDatabase(dbname);
}

Sqlite::~Sqlite() {
    this->CloseDatabase();
}

void Sqlite::OpenDatabase(char dbname[]) {
    if (sqlite3_open(dbname, &this->db)) {
        throw std::ios_base::failure("Opening Database Failed!");
    }
}

void Sqlite::CloseDatabase() {
    if (sqlite3_close(this->db)) {
        throw std::ios_base::failure("Closing Database Failed!");
    }
}

int Sqlite::HandleResult(void *ArgThrough, int argc, char **argv, char **azColName) {

    for (int cnt = 0 ; cnt < argc ; cnt++) {
        
    }
}

void Sqlite::SetExecuteQuery(char *sql) {
    char *errmsg;
    if (sqlite3_exec(this->db, sql, NULL, NULL, &errmsg)) {
        throw std::ios_base::failure(std::strcat("Set Execute Query Failed : ", errmsg));
    }
    sqlite3_free(errmsg);
}

std::vector<std::pair<char *, size_t>> Sqlite::GetExecuteQuery(char *sql) {
    std::vector<std::pair<char *, size_t>> buff;
    char *errmsg;

    if (sqlite3_exec(this->db, sql, Sqlite::HandleResult, NULL, &errmsg)) {
        throw std::ios_base::failure(std::strcat("Get Execute Query Failed : ", errmsg));
    }
}