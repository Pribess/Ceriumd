//Copyright (c) 2021 Heewon Cho

#include "Sqlite.hpp"

std::vector<std::vector<std::string>> Sqlite::buff;

Sqlite::Sqlite(std::string dbname) {
    this->OpenDatabase(dbname);
}

Sqlite::~Sqlite() {
    this->CloseDatabase();
}

void Sqlite::OpenDatabase(std::string dbname) {
    if (sqlite3_open(dbname.c_str(), &this->db)) {
        throw std::ios_base::failure("Opening Database Failed!");
    }
}

void Sqlite::CloseDatabase() {
    if (sqlite3_close(this->db)) {
        throw std::ios_base::failure("Closing Database Failed!");
    }
}

int Sqlite::HandleResult(void *ArgThrough, int argc, char **argv, char **azColName) {
    std::vector<std::string> row;
    
    for (int cnt = 0 ; cnt < argc ; cnt++) {
        row.push_back(std::string(argv[cnt]));
    }

    Sqlite::buff.push_back(row);
    return 0;
}

std::vector<std::vector<std::string>> Sqlite::ExecuteQuery(std::string sql) {
    char *errmsg;

    Sqlite::buff.clear();

    if (sqlite3_exec(this->db, sql.c_str(), Sqlite::HandleResult, NULL, &errmsg)) {
        throw std::ios_base::failure(std::strcat((char *)"Get Execute Query Failed : ", errmsg));
    }

    sqlite3_free(errmsg);

    return Sqlite::buff;
}