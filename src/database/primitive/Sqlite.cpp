//Copyright (c) 2021 Heewon Cho

#include "Sqlite.hpp"

std::vector<char *> Sqlite::buff;

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
    Sqlite::buff.clear();
    for (int cnt = 0 ; cnt < argc ; cnt++) {
        //printf("%s", argv[cnt]);
        Sqlite::buff.push_back(argv[cnt]);
    }
    printf("%s\n", Sqlite::buff.front());
    printf("asdf");
    return 0;
}

std::vector<char *> Sqlite::ExecuteQuery(char sql[]) {
    char *errmsg;

    if (sqlite3_exec(this->db, sql, Sqlite::HandleResult, NULL, &errmsg)) {
        throw std::ios_base::failure(std::strcat("Get Execute Query Failed : ", errmsg));
    }
    sqlite3_free(errmsg);
    printf("%s\n", Sqlite::buff.back());
    return Sqlite::buff;
}