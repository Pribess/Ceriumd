//Copyright (c) 2021 Heewon Cho

#include "Sqlite.hpp"

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

std::vector<std::vector<std::pair<char *, size_t>>> Sqlite::ExecuteQuery(std::string sql, std::vector<std::pair<char *, size_t>> data) {
    std::vector<std::vector<std::pair<char *, size_t>>> rs;
    sqlite3_stmt *stmt;

    if (sqlite3_finalize(stmt)) {
        throw std::ios_base::failure("Finalize Statement Failed!");
    }

    if (sqlite3_prepare(this->db, sql.c_str(), sql.length(), &stmt, nullptr)) {
        throw std::ios_base::failure("Prepare Statement Failed!");
    }
    
    for (int cnt = 0 ; cnt < data.size() ; cnt++) {
        sqlite3_bind_blob(stmt, 1, data.at(cnt).first, data.at(cnt).second, SQLITE_TRANSIENT);
    }

    while (SQLITE_ROW == sqlite3_step(stmt)) {
        sqlite3_column_blob();
    }

    return rs;
}